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
    string s; cin >> s;

    if (n % 2 == 0) {
        map<char, int> freq_odd, freq_even;
        FOR (i, n) {
            if (i % 2 == 0) {
                freq_even[s[i]]++;
            } else {
                freq_odd[s[i]]++;
            }
        }

        int max_freq_odd = 0, max_freq_even = 0;
        for (auto& [c, f]: freq_odd) {
            max_freq_odd = max(max_freq_odd, f);
        }
        for (auto& [c, f]: freq_even) {
            max_freq_even = max(max_freq_even, f);
        }
        cout << n - max_freq_odd - max_freq_even;
    } else {
        vector<array<int, 26>> prefix_odd_freq(n+1), prefix_even_freq(n+1);
        FOR (i, n) {
            prefix_odd_freq[i+1] = prefix_odd_freq[i];
            prefix_even_freq[i+1] = prefix_even_freq[i];
            if (i % 2 == 0) {
                prefix_even_freq[i+1][s[i]-'a']++;
            } else {
                prefix_odd_freq[i+1][s[i]-'a']++;
            }
        }

        vector<array<int, 26>> suffix_odd_freq(n+1), suffix_even_freq(n+1);
        ROF (i, n) {
            suffix_odd_freq[i] = suffix_odd_freq[i+1];
            suffix_even_freq[i] = suffix_even_freq[i+1];
            if (i % 2 == 0) {
                suffix_even_freq[i][s[i]-'a']++;
            } else {
                suffix_odd_freq[i][s[i]-'a']++;
            }
        }

        int ans = n;
        FOR (i, n) {
            int max_odd_freq = 0, max_even_freq = 0;
            FOR (c, 26) {
                max_odd_freq = max(max_odd_freq, prefix_odd_freq[i][c] + suffix_even_freq[i+1][c]);
                max_even_freq = max(max_even_freq, prefix_even_freq[i][c] + suffix_odd_freq[i+1][c]);
            }
            ans = min(ans, n - max_odd_freq - max_even_freq);
        }

        cout << ans;
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