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
#define FOR1(i, n)               for(int i = 1; i < (int)n; ++i)
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
    int n, m; cin >> n >> m;
    vi a(n), b(n), c(m); cin >> a >> b >> c;

      int mx = 0; for (auto x : a) mx = max(mx, x);

    vector <bool> mark(n, false);
    for (auto &x : c){
        x--;
        assert(!mark[x]);
        mark[x] = true;
    }

    int ans = accumulate(b.begin(), b.end(), 0);
    
    if (m == 0){
        int mn = INT_MAX;
        for (int i = 0; i < n; i++){
            if (a[i] == mx) mn = min(mn, b[i]);
        }
        
        cout << ans - mn << "\n";
        return;
    }

    vector <pair<int, int>> v;
    for (int i = 0; i < n; i++) if (!mark[i]) v.push_back({a[i], i});

    for (int i = 1; i < m; i++) if (a[c[i]] > a[c[i - 1]]) v.push_back({a[c[i]], c[i]});
    v.push_back({a[c[0]], c[0]});

    sort(v.begin(), v.end(), [&](pair<int, int> x1, pair<int, int> y1){
        int x = x1.second;
        int y = y1.second;
        if (a[x] != a[y]){
            return a[x] > a[y];
        }

        if (mark[x] && !mark[y]) return false;
        if (mark[y] && !mark[x]) return true;

        return b[x] < b[y];
    });

    int ptr = -1;
    for (auto &x : v) if (mark[x.second]){
        ptr = x.second;
        break;
    }
    

    if (a[ptr] != mx){
        mark[ptr] = false;
        reverse(v.begin(), v.end());
        for (auto &x : v){
            if (x.first == mx){
                mark[x.second] = true;
                break;
            }
        }
        reverse(v.begin(), v.end());
    }

    priority_queue <int> pq;
    for (auto x : v){
        pq.push(-b[x.second]);
        if (mark[x.second]){
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans;
}

int main(){
    int T;
    cin >> T;
    FOR(t, T){
        solve();
        cout << nl;
    }
    
    return 0;
}