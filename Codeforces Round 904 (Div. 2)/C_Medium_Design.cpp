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
    ll n, m; cin >> n >> m;
    V<pll> ranges(n); FOR(i, n) cin >> ranges[i].F >> ranges[i].S, ranges[i].F--, ranges[i].S--;

    if(m == 1){cout << 0; return;}
    ranges.sort();
    priority_queue<pll, V<pll>, greater<pll>> pq;
    set<pll> cur_ranges;
    ll range_idx = 0, ans = 0, zero_cnt = 0, last_cnt = 0;
    FOR(t, m){
        while(range_idx < n && ranges[range_idx].F <= t){
            cur_ranges.insert(ranges[range_idx]);
            if(ranges[range_idx].F == 0) zero_cnt++;
            if(ranges[range_idx].S == m-1) last_cnt++;
            pq.push({ranges[range_idx].S, ranges[range_idx].F});
            range_idx++;
        }
        while(!pq.empty() && pq.top().F < t){
            pll cur = pq.top(); pq.pop();
            if(cur.S == 0) zero_cnt--;
            if(cur.F == m-1) last_cnt--;
            cur_ranges.erase({cur.S, cur.F});
        }
        if(!cur_ranges.empty())
            ans = max(ans, (ll)cur_ranges.size() - min(zero_cnt, last_cnt));
        if(range_idx < n) t = ranges[range_idx].F - 1;
        else{
            if(!pq.empty()){
                pll cur = pq.top(); pq.pop();
                if(cur.S == 0) zero_cnt--;
                if(cur.F == m-1) last_cnt--;
                cur_ranges.erase({cur.S, cur.F});
                t = cur.F - 1;
            }
        }
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