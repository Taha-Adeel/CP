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

int query(int i, int j) {
    if (i == j) return -1;
    cout << "? " << i << ' ' << j << endl;
    int x; cin >> x;
    return x;
}

int answer(int i, int j) {
    cout << "! " << i << ' ' << j << endl;
    int x; cin >> x;
    return x;
}

void solve() {
    int n; cin >> n;

    // Find non-1 element
    vi indices;
    for (int i = 1; i + 2 <= n; i += 3) {
        int a = query(i, i + 1), b = query(i, i + 2), c = query(i + 1, i + 2);
        if (max({a, b, c}) != 1) {
            for (int j = i + (c != 1); j <= n; j++) {
                indices.pb(j);
            }
            break;
        }
    }
    

    while (indices.size() > 1) {
        vi gcd_i(n + 1, -1);        
        for (auto& i: indices) {
            gcd_i[i] = query(indices[0], i);
        }

        int max_gcd = *max_element(all(gcd_i));
        vi new_indices;
        for (auto& i: indices) {
            if (gcd_i[i] == max_gcd) {
                new_indices.pb(i);
            }
        }

        if (new_indices.size() == 1) {
            answer(indices[0], new_indices[0]);
            return;
        }
        indices = new_indices;
    }

    if (indices.size() == 1) {
        answer(indices[0], indices[0]);
        return;
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