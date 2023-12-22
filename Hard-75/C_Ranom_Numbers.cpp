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

const vi value = {1, 10, 100, 1000, 10000};

void solve() {
    string s; cin >> s;

    int n = s.size();

    auto calculate = [&](vll& digits) {
        ll value = 0, best = 0;
        for(int i = n - 1; i >= 0; --i) {
            best = max(best, digits[i]);
            if(digits[i] < best) value -= digits[i];
            else value += digits[i];
        }
 
        return value;
    };

    vll digits(n);
    FOR(i, n)
        digits[i] = value[s[i] - 'A'];

    ll ans = calculate(digits);

    vi left(5, false), right(5, false);
    FOR(i, n) {
        if(!left[s[i] - 'A']) {
            left[s[i] - 'A'] = true;

            ll old = digits[i];
            for(auto val: value) {
                digits[i] = val;
                ans = max(ans, calculate(digits));
            }
            digits[i] = old;
        }
    }

    for(int i = n - 1; i >= 0; --i) {
        if(!right[s[i] - 'A']) {
            right[s[i] - 'A'] = true;

            ll old = digits[i];
            for(auto val : value) {
                digits[i] = val;
                ans = max(ans, calculate(digits));
            }
            digits[i] = old;
        }
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