#include <bits/stdc++.h>

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0)
template<class T> struct V: vector<T>{using vector<T>::vector;
    void sort()            {std::sort(this->begin(), this->end());}
    void sort_dsc()     {std::sort(this->begin(), this->end(), greater<T>());}
    auto sum()             {T sum = 0; for(auto& i: *this) sum += i; return sum;}
    auto freqs()         {map<T, int> freq; for(auto& i: *this) freq[i]++; return freq;}
    auto indices()        {int n=this->size(); map<T, V<int>> ii; for(int i=0; i<n; i++) ii[(*this)[i]].push_back(i); return ii;}
    auto prefix_sums()     {int n=this->size(); V<T> ps(n+1,0); for(int i=0; i<n; i++) ps[i+1] = ps[i]+(*this)[i]; return ps;}
    friend ostream& operator<<(ostream& out, const V<T>& v) {for(auto& i: v) out << i << ' '; return out;}
    friend istream& operator>>(istream& in, V<T>& v) {for(auto& i: v) in >> i; return in;}
};
#define pY {cout << "YES"; return;}
#define pN {cout << "NO";  return;}
#define display(x) if(x) pY else pN

#define FOR(i, n)                for(int i = 0; i < (int)n; ++i)
#define FOR1(i, n)               for(int i = 1; i <= (int)n; ++i)
#define ROF(i, n)                for(int i = (int)n-1; i >= 0; --i)
#define all(v)                   v.begin(), v.end()
#define rall(v)                  v.rbegin(), v.rend()

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
    vi a(n), b(n); cin >> a >> b;

    vi c(n, 0);
    FOR(i, n)
        if(a[i] < b[i]) c[i] = -1;
        else if(a[i] > b[i]) c[i] = 1;

    auto freq = c.freqs();
    if(freq[0] > 1 || (freq[0] + n%2 == 1)) {cout << -1; return;}
    c.resize(unique(all(c))-c.begin());

    auto check = [&](int x){
        vi d = a; d.insert(d.end(), all(b));
        rotate(d.begin(), d.begin()+x, d.end());

        bool good = true;
        FOR(i, n) if(d[i] != d[2*n-i-1]) good = false;
        FOR(i, n/2) if(d[i] >= d[i+n]) good = false;
        FOR(i, (n+1)/2) if(d[n/2+i] < d[n/2+i+n]) good = false;
        if(good) return x;
        else return -1;
    };

    int ans = -2;
    if(n%2 == 0){
        if(c.size() <= 2){
            if(c[0] == -1) {
                if(freq[-1] < n/2) ans = check(freq[-1] + n + n/2);
                else ans = check(freq[-1] - n/2);
            }
            else ans = check(freq[1] + n/2);
        }
        else ans = -1;
    }
    else{
        int zero_pos = -1;
        FOR(i, n) if(a[i] == b[i]) zero_pos = i;
        if(zero_pos >= n/2) {
            if(check(zero_pos - n/2) != -1) ans = check(zero_pos - n/2);
            else ans = check(zero_pos - n/2 + n);
        }
        else {
            if(check(zero_pos + n - n/2) != -1) ans = check(zero_pos + n - n/2);
            else ans = check(zero_pos + 2*n - n/2);
        }
    }

    cout << ans;
}

int main(){
    FAST;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    FOR(t, T){
        cout << "Case #" << t+1 << ": ";
        solve();
        cout << nl;
    }
    
    return 0;
}