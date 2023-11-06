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
#define FOR1(i, n)    for(int i = 1; i <= (int)n; ++i)
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
    int n; cin >> n;
    V<string> s(n); cin >> s;

    map<pii, ll> freq;
    FOR(i, n){
        int sum = 0;
        for(auto& c: s[i]) sum += c - '0';
        freq[{s[i].size(), sum}]++;
    }

    ll ans = 0;
    FOR(i, n){
        int r_sum = 0;
        for(auto& c: s[i]) r_sum += c - '0';

        int l1 = 0, l_sum = 0, l = s[i].size();
        while(l1 < l-1){
            l_sum += s[i][l1] - '0';
            r_sum -= s[i][l1] - '0';
            l1++;

            ans += freq[{2*l1 - l, l_sum - r_sum}];
            ans += freq[{l - 2*l1, r_sum - l_sum}];
        }
    }
    for(auto& [len, f]: freq) if(f) ans += f*f, cerr << len.F << ' ' << len.S << ' ' << f << nl;

    cout << ans;
}

int main(){
    FAST;
    solve();
    cout << nl;
    
    return 0;
}