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
#define pb push_back

constexpr char nl = '\n';
constexpr int MOD = 1000000007;
using ll  = long long int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi  = V<int>;
using vll = V<ll>;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/

void solve() {
    string t; cin >> t;
    int n; cin >> n;
    V<string> s(n); cin >> s;

    V<array<int, 3>> ranges;
    FOR(i, n) {
        // Find all occurences of s[i] in t
        for(int l = 0, sz = s[i].size(); l < t.size(); l++) {
            l = t.find(s[i], l);
            if(l == string::npos) break;
            ranges.pb({l, l + sz - 1, i});
        }
    }
    
    ranges.sort(); // Sort by starting point

    V<pii> ans;
    priority_queue<array<int, 3>> pq; // {ending point, starting point, index}
    int cur_i = 0;
    for(int cur_r = -1; cur_r < t.size() - 1; ) {
        // Add all ranges that start before cur_r + 1
        while(cur_i < ranges.size() && ranges[cur_i][0] <= cur_r + 1) {
            pq.push({ranges[cur_i][1], ranges[cur_i][0], ranges[cur_i][2]});
            cur_i++;
        }

        // If no range starts before cur_r + 1 and we havent reached the end, then no answer
        if(pq.empty() && cur_r + 1 < t.size()) {
            cout << -1 << nl;
            return;
        }

        auto [r, l, i] = pq.top(); pq.pop();
        ans.pb({i, l});
        cur_r = r;
    }
    

    cout << ans.size() << nl;
    for(auto& [i, l]: ans)
        cout << i + 1 << ' ' << l + 1 << nl;    
}

int main() {
    FAST;
    int T; cin >> T;
    FOR(t, T) {
        solve();
    }
    
    return 0;
}