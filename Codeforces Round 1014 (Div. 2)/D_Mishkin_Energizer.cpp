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

    vi cnt(26, 0);
    FOR (i, n) {
        cnt[s[i] - 'A']++;
    }

    if (max({cnt['L' - 'A'], cnt['I' - 'A'], cnt['T' - 'A']}) == n) {
        cout << -1 << nl; return;
    }

    V<pair<char, int>> v = {
        {'L', cnt['L' - 'A']},
        {'I', cnt['I' - 'A']},
        {'T', cnt['T' - 'A']}
    };
    sort(all(v), [](auto& a, auto& b) {
        return a.second > b.second;
    });

    FOR (i, n) {
        if (s[i] == v[0].first) s[i] = '1';
        else if (s[i] == v[1].first) s[i] = '2';
        else if (s[i] == v[2].first) s[i] = '3';
    }
    cnt[1] = cnt[v[0].first - 'A'];
    cnt[2] = cnt[v[1].first - 'A'];
    cnt[3] = cnt[v[2].first - 'A'];

    int i = 0;
    int other = 1;
    bool reverse = false;
    for (; i < n - 1 ; i++) {
        if (s[i] == '1' and s[i + 1] != '1') {
            other = s[i + 1] - '0';
            reverse = false;
            break;
        }
        if (s[i] != '1' and s[i + 1] == '1') {
            other = s[i] - '0';
            reverse = true;
            break;
        }
    }

    vi ans;
    while (min(cnt[3], cnt[2]) < cnt[1]) {
        ans.pb(i + 1);
        other ^= 2 ^ 3;
        cnt[other]++;
        i += reverse;
        if (ans.size() > 2 * n) {
            cout << 1 << nl; return;
        }
    }

    if (cnt[2] > cnt[1]) {
        if (ans.size() + 2 * (cnt[2] - cnt[1]) > 2 * n) {
            cout << -1 << nl; return;
        }
        if (reverse) {
            i--;
            FOR (j, 2 * (cnt[2] - cnt[1])) {
                ans.pb(i + 1);
            }
        } else {
            i++;
            FOR (j, 2 * (cnt[2] - cnt[1])) {
                ans.pb(i + 1);
                i++;
            }
        }
    }

    cout << ans.size() << nl;
    FOR (i, ans.size()) {
        cout << ans[i] << nl;
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