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

int query(int i) {
    cout << "? " << i + 1 << endl;
    int x; cin >> x;
    return x;
}

void answer(int a, int b) {
    cout << "! " << a << ' ' << b << endl;
}

void answer(int a) {
    cout << "! " << a << endl;
}

void solve() {
    int n, k; cin >> n >> k;

    vi a(k), b(k);
    for (int i = 0; i < k; i++) {
        a[i] = query(i);
        b[i] = query(n - k + i);
    }

    for (int i = 0; i < k; i++) {
        int r = (n / k) * k + i;
        if (r >= n) {
            r -= k;
        }
        int ri = query(r);
        
        if (a[i] == ri) {
            continue;
        }

        // Binary search among (1, i + k, i + 2k, ...) for last idx j such that a[j] == a[i]
        int l = 0, r = n / k + 1;
        while (l < r) {
            int m = (l + r + 1) / 2;
            int j = i + m * k;
            while (j >= n) {
                j -= k;
            }
            if (query(j) == a[i]) {
                l = m;
            } else {
                r = m - 1;
            }
        }

        int l_a = l * k + i;
        int ans_a = l_a;
        for (int cnt = 0, j = i; cnt < k; cnt++, j = (j + 1) % k) {
            if (n - (l_a + cnt + 1) < k) {
                break;
            }
            if (query(l_a + cnt) != a[j]) {
                break;
            }
            ans_a = l_a + cnt;
        }

        int r_b = l_a + k;
        int ans_b = r_b;
        int j = find(b.begin(), b.end(), ri) - b.begin();
        for (int cnt = 0; cnt < k; cnt++, j = (j + k - 1) % k) {
            if (r_b - cnt < k) {
                break;
            }
            if (query(r_b - cnt) != b[j]) {
                break;
            }
            ans_b = r_b - cnt;
        }
        ans_b--;

        if (ans_a != ans_b) {
            answer(-1);
            return;
        } else {
            answer(ans_a + 1, n - ans_a - 1);
            return;
        }
    }

    if (n == 2 * k) {
        answer(k, k);
    } else {
        answer(-1);
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