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
    V<pii> p(n);
    FOR (i, n) { 
        cin >> p[i].first;
    }
    FOR (i, n) { 
        cin >> p[i].second;
    }

    map<pii, int> indices;
    int equal_cnt = 0;
    FOR (i, n) {
        indices[p[i]] = i;
        if (p[i].first == p[i].second) {
            equal_cnt++;
        }
    }

    if (equal_cnt > 1 or equal_cnt == 1 and n % 2 == 0) {
        cout << -1 << nl;
        return;
    }

    V<pii> ans;
    FOR (i, n / 2) {
        auto [a, b] = p[i];
        if (!indices.count({b, a})) {
            cout << -1 << nl;
            return;
        }
        int j = indices[{b, a}];
        if (i == j) {
            if (i == n / 2) {
                continue;
            }
            ans.pb({i + 1, n / 2 + 1});
            swap(p[i], p[n / 2]);
            i--;
            continue;
        }
        if (j + 1 == n - i) {
            continue;
        }

        ans.pb({j + 1, n - i});
        swap(p[j], p[n - i - 1]);
    }

    cout << ans.size() << nl;
    for (auto [a, b] : ans) {
        cout << a << ' ' << b << nl;
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