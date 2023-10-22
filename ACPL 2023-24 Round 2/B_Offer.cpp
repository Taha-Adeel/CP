#include <bits/stdc++.h>

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0)
template<class T> struct V: vector<T>{using vector<T>::vector;
    void sort()            {std::sort(this->begin(), this->end());}
    V sorted()           {V v = *this; std::sort(this->begin(), this->end()); return v;}
    void sort_dsc()     {std::sort(this->begin(), this->end(), greater<T>());}
    V sorted_dsc()    {V v = *this; std::sort(this->begin(), this->end(), greater<T>()); return v;}
    auto sum()             {T sum = 0; for(auto& i: *this) sum += i; return sum;}
    auto freqs()         {map<T, int> freq; for(auto& i: *this) freq[i]++; return freq;}
    auto indices()        {int n=this->size(); map<T, V<int>> ii; for(int i=0; i<n; i++) ii[(*this)[i]].push_back(i); return ii;}
    auto prefix_sums()     {int n=this->size(); V<T> ps(n+1,0); for(int i=0; i<n; i++) ps[i+1] = ps[i]+(*this)[i]; return ps;}
    friend ostream& operator<<(ostream& out, const V<T>& v) {for(auto& i: v){out << i << ' ';} return out;}
    friend istream& operator>>(istream& in, V<T>& v) {for(auto& i: v){in >> i;} return in;}
};
#define pY {cout << "YES"; return;}
#define pN {cout << "NO";  return;}
#define display(x) if(x) pY else pN

#define FOR(i, n)                for(int i = 0; i < (int)n; ++i)
#define FOR1(i, n)               for(int i = 1; i <= (int)n; ++i)
#define ROF(i, n)            for(int i = (int)n-1; i >= 0; --i)
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
    int n, m; cin >> n >> m;
    vll b(m); cin >> b;

    priority_queue<ll, vector<ll>, greater<ll>> b_asc; for(auto& i: b) b_asc.push(i);
    priority_queue<ll> b_dsc; for(auto& i: b) b_dsc.push(i);
    ll ans_min = 0, ans_max = 0;
    FOR(i, n){
        ll x = b_asc.top(); b_asc.pop();
        ans_min += x--;
        if(x) b_asc.push(x);
    }

    FOR(i, n){
        ll x = b_dsc.top(); b_dsc.pop();
        ans_max += x--;
        if(x) b_dsc.push(x);
    }
    cout << ans_max << ' ' << ans_min;
}

int main(){
    solve();
    cout << nl;
    
    return 0;
}