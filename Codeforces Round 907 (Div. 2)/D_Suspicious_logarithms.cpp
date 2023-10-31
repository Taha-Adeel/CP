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

V<tuple<int, ll, ll>> intervals = {
    {2, 4, 7},
    {1, 8, 8},
    {2, 9, 728},
    {3, 729, 50624},
    {4, 50625, 4084100},
    {5, 4084101, 4194303},
    {4, 4194304, 5153631},
    {5, 5153632, 481890303},
    {6, 481890304, 536870911},
    {5, 536870912, 594823320},
    {6, 594823321, 64339296874},
    {7, 64339296875, 68719476735},
    {6, 68719476736, 78364164095},
    {7, 78364164096, 11688200277600},
    {8, 11688200277601, 1953124999999999},
    {9, 1953125000000000, 2251799813685247},
    {8, 2251799813685248, 2334165173090450},
    {9, 2334165173090451, 430804206899405823},
    {10, 430804206899405824, 1000000000000000000}
};

void solve(){
    ll l, r; cin >> l >> r;

    ll ans = 0;
    for(auto& [g, li, ri]: intervals){
        ll intersect = min(ri, r) - max(li, l) + 1;
        if(intersect > 0)
            (ans += intersect % MOD * g) %= MOD;
    }

    cout << ans;
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