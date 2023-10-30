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
using ll  = long long int;
constexpr ll MOD = 1000000007;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi  = V<int>;
using vll = V<ll>;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/

int f(ll x){
    int f_x = 0;
    while(x != 1)
        f_x++, x /= 2;
    return f_x;
}

int g(ll x){
    int f_x = f(x);
    
    int g_x = 0;
    while(x >= f_x)
        g_x++, x /= f_x;

    return g_x;
}

map<pll, ll> memo_bs_g;
map<pll, ll> memo_l_r;;

void solve(){
    ll l, r; cin >> l >> r;

    ll ans = 0;
    ll l_i = l, r_i = min((1LL << (f(l_i)+1))-1, r);
    while(l_i <= r){
        ll sum = 0;
        if(memo_l_r.count({l_i, r_i}))
            sum = memo_l_r[{l_i, r_i}];
        else{
            for(ll g_x = g(l_i); g_x <= g(r_i); g_x++){
                // Do binary search to find first x s.t g(x) > g_x
                ll lo = l_i, hi = r_i+1;
                if(memo_bs_g.count({r_i, g_x}))
                    lo = min(memo_bs_g[{r_i, g_x}], hi);
                else{
                    while(lo < hi){
                        ll mid = lo + (hi-lo)/2;
                        if(g(mid) > g_x) hi = mid;
                        else lo = mid+1;
                    }
                    memo_bs_g[{r_i, g_x}] = lo;
                }
                sum += ((lo-l_i) * g_x) % MOD;
                sum %= MOD;
                l_i = lo;
            }
            memo_l_r[{l_i, r_i}] = sum;
        }
        ans = (ans + sum) % MOD;
        l_i = r_i+1;
        r_i = min(r, 2*l_i - 1);
    }

    cout << ans;
}

int main(){
    FAST;
    int T;
    cin >> T;
    FOR(t, T){
        solve();
        cout << nl;
    }

    return 0;
}