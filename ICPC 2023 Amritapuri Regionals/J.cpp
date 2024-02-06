#include <bits/stdc++.h>

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0)
template<class T> struct V: vector<T>{using vector<T>::vector;
    V& sort()          { std::sort(this->begin(), this->end()); return *this; }
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
    int k, x, y; cin >> k >> x >> y;

    x = abs(x);
    y = abs(y); 

    if (k == 1) {
        cout << 0;
        return;
    } else if (k == 2) {
        cout << 1 - (x + y) % 2;
        // return;
    }

    // k = 3, print the possibilities
    vi pos = {1};
    cerr << "d = " << 1 << ": " << pos << nl;
    for (int d = 2, cur = k; d <= 4; ++d, cur *= k) {
        vi newPos;
        for (auto x: pos) {
            newPos.push_back(cur - x);
            newPos.push_back(cur + x);
        }
        pos = newPos.sort();
        cerr << "d = " << d << ": " << pos << nl;
    }

    V<pii> poss = {{0, 0}};
    for (int d = 1, cur = 1; d <= 15; ++d, cur *= k) {
        V<pii> newPoss;
        for (auto [x, y]: poss) {
            newPoss.push_back(minmax(abs(x - cur), y));
            newPoss.push_back(minmax(x + cur, y));
            newPoss.push_back(minmax(x, abs(y - cur)));
            newPoss.emplace_back(x, y + cur);
        }
        poss = newPoss.sort();
        poss.resize(unique(all(poss)) - poss.begin());
        cerr << "d = " << d << ", pos.size() = " << poss.size() << "\n";
    }
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