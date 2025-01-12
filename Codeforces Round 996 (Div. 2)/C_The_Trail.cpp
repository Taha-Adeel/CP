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
    int n, m; cin >> n >> m;
    string path; cin >> path;
    V<vll> grid(n, vll(m)); cin >> grid;

    V<vi> on_path(n, vi(m, 0));
    int x = 0, y = 0;
    on_path[x][y] = 1;
    for (char c: path) {
        if (c == 'D') {
            x++;
        } else {
            y++;
        }
        on_path[x][y] = 1;
    }

    vll row_sum(n, 0), col_sum(m, 0);
    V<set<int>> row_unknowns(n), col_unknowns(m);
    FOR (i, n) {
        FOR (j, m) {
            row_sum[i] += grid[i][j];
            col_sum[j] += grid[i][j];

            if (on_path[i][j]) {
                row_unknowns[i].insert(j);
                col_unknowns[j].insert(i);
            }
        }
    }

    // pq to hold {num_unknows, row(0)/col(1), index}, with min heap
    priority_queue<array<int, 3>, V<array<int, 3>>, greater<array<int, 3>>> pq;
    FOR (i, n) {
        pq.push({(int)row_unknowns[i].size(), 0, i});
    }
    FOR (i, m) {
        pq.push({(int)col_unknowns[i].size(), 1, i});
    }

    ll req_sum = 1e18;
    auto process = [&](array<int, 3>& elem) {
        auto [num_unknowns, is_row, index] = elem;
        if (is_row == 0) {
            if (num_unknowns > row_unknowns[index].size()) {
                return;
            }
            int i = index, j = *(row_unknowns[i].begin());
            // cerr << "i: " << i << " j: " << j << nl;
            if (req_sum == 1e18) {
                grid[i][j] = -row_sum[i];
                req_sum = 0;
            } else {
                grid[i][j] = req_sum - row_sum[i];
            }
            row_unknowns[i].erase(j);
            col_unknowns[j].erase(i);
            row_sum[i] += grid[i][j];
            col_sum[j] += grid[i][j];
            if (col_unknowns[j].size() > 0) {
                pq.push({(int)col_unknowns[j].size(), 1, j});
            }
        } else {
            if (num_unknowns > col_unknowns[index].size()) {
                return;
            }
            int j = index, i = *(col_unknowns[j].begin());
            // cerr << "i: " << i << " j: " << j << nl;
            if (req_sum == 1e18) {
                grid[i][j] = -col_sum[j];
                req_sum = 0;
            } else {
                grid[i][j] = req_sum - col_sum[j];
            }
            row_unknowns[i].erase(j);
            col_unknowns[j].erase(i);
            row_sum[i] += grid[i][j];
            col_sum[j] += grid[i][j];
            if (row_unknowns[i].size() > 0) {
                pq.push({(int)row_unknowns[i].size(), 0, i});
            }
        }
    };

    while (!pq.empty()) {
        auto elem = pq.top();
        pq.pop();
        process(elem);
    }

    // cerr << "req_sum: " << req_sum << nl;
    // cerr << row_sum << nl;
    // cerr << col_sum << nl;
    // cerr << nl;

    for (auto& row: grid) {
        cout << row << nl;
    }
}

int main() {
    FAST;
    int T; cin >> T;
    FOR(t, T) {
        solve();
    }
    
    return 0;
}