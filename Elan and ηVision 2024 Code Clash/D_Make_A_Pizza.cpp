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
    vi a, b;
    FOR (i, n) {
        int x, t; cin >> x >> t;
        if (t == 1) {
            a.pb(x);
        } else {
            b.pb(x);
        }
    }

    a.sort();
    b.sort();

    auto a_freqs = a.freqs();
    auto b_freqs = b.freqs();

    V<set<int>> sums_a_compact;
    set<int> cur_a_compact;
    V<V<pair<int, map<int, int>>>> sums_a; // {i, {sum, {{a1, f1}, {a2, f2}, {a3, f3}, ...}}}
    V<pair<int, map<int, int>>> cur_a; // {sum, {{a1, f1}, {a2, f2}, {a3, f3}, ...}}
    for (auto& [ai, f]: a_freqs) {
        map<int, int> freq;
        freq[ai] = 1;
        cur_a.emplace_back(make_pair(ai, freq));
        cur_a_compact.insert(ai);
    }
    sums_a.pb(cur_a);
    sums_a_compact.pb(cur_a_compact);
    for (int k = 1; k < min(a.size(), b.size()); k++) { // Picking k elements
        V<pair<int, map<int, int>>> next;
        set<int> next_compact;
        for (auto [sum, freqs]: cur_a) {
            for (auto& [ai, f]: a_freqs) {
                if (sum + ai > 360) {
                    break;
                }
                if (freqs[ai] < f) {
                    freqs[ai]++;
                    next.pb({sum + ai, freqs});
                    next_compact.insert(sum + ai);
                }
            }
        }
        sums_a.pb(next);
        sums_a_compact.pb(next_compact);
        cur_a = next;
    }

    V<set<int>> sums_b_compact;
    set<int> cur_b_compact;
    V<V<pair<int, map<int, int>>>> sums_b; // {i, {sum, {{b1, f1}, {b2, f2}, {b3, f3}, ...}}}
    V<pair<int, map<int, int>>> cur_b; // {sum, {{b1, f1}, {b2, f2}, {b3, f3}, ...}}
    for (auto& [bi, f]: b_freqs) {
        map<int, int> freq;
        freq[bi] = 1;
        cur_b.emplace_back(make_pair(bi, freq));
        cur_b_compact.insert(bi);
    }
    sums_b.pb(cur_b);
    sums_b_compact.pb(cur_b_compact);
    for (int k = 1; k < min(a.size(), b.size()); k++) { // Picking k elements
        V<pair<int, map<int, int>>> next;
        set<int> next_compact;
        for (auto [sum, freqs]: cur_b) {
            for (auto& [bi, f]: b_freqs) {
                if (sum + bi > 360) {
                    break;
                }
                if (freqs[bi] < f) {
                    freqs[bi]++;
                    next.pb({sum + bi, freqs});
                    next_compact.insert(sum + bi);
                }
            }
        }
        sums_b.pb(next);
        sums_b_compact.pb(next_compact);
        cur_b = next;
    }

    for (int sum_a = 1, sum_b = 359; sum_a < 360; sum_a++, sum_b--) {
        for (int k = 0; k < min(a.size(), b.size()); k++) {
            if (sums_a_compact[k].count(sum_a) && sums_b_compact[k].count(sum_b)) {
                cout << "Yes";
                return;
            }
        }
    }
    cout << "No";
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