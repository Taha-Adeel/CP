#include <bits/stdc++.h>

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0)
template<class T> struct V: vector<T>{using vector<T>::vector;
    void sort()        { std::sort(this->begin(), this->end()); }
    void sort_dsc()    { std::sort(this->begin(), this->end(), greater<T>()); }
    auto sum()         { T sum = 0; for(auto& i: *this) sum += i; return sum; }
    auto freqs()       { map<T, int> freq; for(auto& i: *this) freq[i]++; return freq; }
    auto indices()     { int n=this->size(); map<T, V<int>> ii; for(int i=0; i<n; i++) ii[(*this)[i]].push_back(i); return ii; }
    auto prefix_sums() { int n=this->size(); V<T> ps(n+1,0); for(int i=0; i<n; i++) ps[i+1] = ps[i]+(*this)[i]; return ps; }
    friend ostream& operator<<(ostream& out, const V<T>& v) { for(auto& i: v) out << i << ' '; return out; }
    friend istream& operator>>(istream& in, V<T>& v)        { for(auto& i: v) in >> i; return in; }
};
#define pY {cout << "YES"; return;}
#define pN {cout << "NO";  return;}
#define display(x) if(x) pY else pN

#define FOR(i, n)     for(int i = 0; i < (int)n; ++i)
#define FOR1(i, n)    for(int i = 1; i < (int)n; ++i)
#define ROF(i, n)     for(int i = (int)n-1; i >= 0; --i)
#define all(v)        v.begin(), v.end()
#define rall(v)       v.rbegin(), v.rend()

#define F  first
#define S  second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
constexpr char nl = '\n';
constexpr int MOD = 1000000007;
using ll  = long long int;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi  = V<int>;
using vll = V<ll>;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/

void solve(){
    int n, k; cin >> n >> k;
    vi a(n); cin >> a;

    auto good = [](int a, int b){
        return b != 1 && gcd(a, b) == 1;
    };

    // Remove the elements with both neighbours coprime
    FOR1(i, n-1){
        if(k == 0) break;
        if(good(a[i], a[i-1]) && good(a[i], a[i+1])){
            a[i] = 0;
            k--;
        }
    }

    // See if you can remove complete 1 subarrays
    V<pii> ones; // {len, start}
    int cur_len = 0;
    FOR(i, n+1){
        if(i < n && a[i] == 1) cur_len++;
        else{
            if(cur_len) ones.pb({cur_len, i - cur_len});
            cur_len = 0;
        }
    }
    ones.sort();
    for(auto& [len, start]: ones){
        if(k == 0) break;
        if(start && start+len < n && len <= k){
            FOR(i, len) a[start+i] = 0;
            k -= len;
        }
    }

    // Remove the elements with one neighbour coprime
    FOR1(i, n){
        if(k == 0) break;
        if(good(a[i], a[i-1])){
            a[i] = 0;
            k--;
        }
        if(k == 0) break;
        if(good(a[i-1], a[i])){
            a[i-1] = 0;
            k--;
        }
    }

    // Remove the ones with one neighbour coprime
    FOR1(i, n){
        if(k == 0) break;
        if(good(a[i], a[i-1])){
            a[i] = 0;
            k--;
        }
    }
    ROF(i, n-1){
        if(k == 0) break;
        if(good(a[i], a[i+1])){
            a[i] = 0;
            k--;
        }
    }

    // Remove ones
    FOR(i, n){
        if(k == 0) break;
        if(a[i] == 1){
            a[i] = 0;
            k--;
        }
    }

    int ans = 0;
    FOR1(i, n) if(gcd(a[i], a[i-1]) == 1) 
        ans++;
    cout << ans;
    cerr << a << nl;
}

int main(){
    FAST;
    int T; cin >> T;
    FOR(t, T){
        solve();
        cout << nl;
    }
    
    return 0;
}