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
    int n; cin >> n;
    vi a(n); cin >> a;

    auto min_swaps_to_sort = [](vi& arr) {
        int n = arr.size();
        vi temp(arr);
        sort(temp.begin(), temp.end());
        map<int, int> index_map;
        for (int i = 0; i < n; i++) {
            index_map[arr[i]] = i;
        }
        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || arr[i] == temp[i]) {
                continue;
            }
            int cycle_size = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = index_map[temp[j]];
                cycle_size++;
            }
            if (cycle_size > 0) {
                swaps += (cycle_size - 1);
            }
        }
        return swaps;
    };

    vi e, o;
    FOR (i, n) {
        if (i % 2 == 0) {
            e.pb(a[i]);
        } else {
            o.pb(a[i]);
        }
    }
    int e_swaps = min_swaps_to_sort(e);
    int o_swaps = min_swaps_to_sort(o);

    e.sort();
    o.sort();

    vi ans(n);
    int ei = 0, oi = 0;
    FOR (i, n) {
        if (i % 2 == 0) {
            ans[i] = e[ei++];
        } else {
            ans[i] = o[oi++];
        }
    }

    if (e_swaps % 2 != o_swaps % 2) {
        swap(ans[n - 1], ans[n - 3]);
    }
    cout << ans;
}

int main() {
    FAST;
    int T; cin >> T;
    FOR(t, T) {
        solve();
        cout << nl;
    }
    
    return 0;
}