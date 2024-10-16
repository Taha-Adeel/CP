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
    cout << "? " << i << ' ' << j << endl;
    int x; cin >> x;
    return x;
}

void answer(int x) {
    cout << "! " << x << endl;
}

void solve() {
    int n; cin >> n;

    for (int i = n; (n % 2 && (i > 5 || i == 3)) || (n % 2 == 0 && i > 1); i -= 2) {
        if (i == 2) i++;
        if (query(i, i - 1) != query(i - 1, i)) { 
            if (i == 3 && n % 2 == 0) answer(2);
            else if (query(i, i % n + 1) != query(i % n + 1, i)) answer(i);
            else answer(i - 1);
            return;
        }
    }

    if (n % 2 == 0 || n == 3) {
        answer(1);
    } else if (n % 2) {
        auto [a, b, c] = tuple{query(1, 2), query(2, 3), query(3, 1)};
        if ((a + b + c) % 2 == 1) {
            if (query(1, 4) != query(4, 1)) answer(4);
            else answer(5);
        } else {
            int d = query(2, 1), e = query(3, 2);
            if (a != d && b != e) answer(2);
            else if (a != d) answer(1);
            else answer(3);
        }
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