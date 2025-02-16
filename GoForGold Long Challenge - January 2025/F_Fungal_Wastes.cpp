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

// Seive of Eratosthenes
#define MAXN 2000000005
vll primes;
void seive() {
    ll N = sqrt(MAXN) + 1;
    vector<bool> is_prime(N, true);
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i <= N; i++) {
        if (is_prime[i]) {
            primes.pb(i);
            for (ll j = i*i; j < N; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

void solve() {
    int n; cin >> n;
    vll a(n); cin >> a;

    FOR (i, n) {
        ll ai = a[i], x = 1;
        for (ll p: primes) {
            if (p*p > ai) break;
            int cnt = 0;
            while (ai % p == 0) {
                ai /= p;
                cnt++;
            }
            cnt %= 3;
            if (cnt == 1) x *= p;
            else if (cnt == 2) x *= p*p;
        }
        if (ai > 1) x *= ai;

        a[i] = x;
    }

    auto freq = a.freqs();
    ll ans = 0;
    for (auto [x, f]: freq) {
        ans += 1ll * f * (f-1) / 2;
    }

    cout << ans;
}

int main() {
    FAST;
    seive();
    int T; cin >> T;
    FOR(t, T) {
        solve();
        cout << nl;
    }
    
    return 0;
}