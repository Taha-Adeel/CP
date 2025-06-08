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

void solve(int t, int T) {
    int n, q; cin >> n >> q;
    string s; cin >> s;

    set<int> b_pos, c_pos;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'b') b_pos.insert(i);
        else if (s[i] == 'c') c_pos.insert(i);
    }

    int bc = 0, cb = 0;
    for (int i = 0; i < q; i++) {
        char x, y; cin >> x >> y;
        if (x == 'a') continue;
        if (x == 'b' and y == 'c') {
            bc++;
        } else if (x == 'c' and y == 'b') {
            cb++;
        }
        if (x == 'b' and y == 'a') {
            int bb = !b_pos.empty() ? *b_pos.begin() : INT_MAX;
            int cc = (cb and !c_pos.empty()) ? *c_pos.begin() : INT_MAX;
            if (min(bb, cc) == INT_MAX) continue;
            if (bb < cc) {
                s[bb] = 'a';
                b_pos.erase(bb);
            } else {
                s[cc] = 'a';
                c_pos.erase(cc);
                cb--;
            }
        }
        if (x == 'c' and y == 'a') {
            int cc = !c_pos.empty() ? *c_pos.begin() : INT_MAX;
            int bb = (bc and !b_pos.empty()) ? *b_pos.begin() : INT_MAX;
            if (min(bb, cc) == INT_MAX) continue;
            if (cc < bb) {
                s[cc] = 'a';
                c_pos.erase(cc);
            } else {
                s[bb] = 'a';
                b_pos.erase(bb);
                bc--;
            }
        }
    }

    while (cb-- and !c_pos.empty()) {
        int cc = *c_pos.begin();
        s[cc] = 'b';
        c_pos.erase(cc);
    } 

    cout << s << nl;
}

int main() {
    FAST;
    int T; cin >> T;
    FOR(t, T) {
        solve(t + 1, T);
    }
    
    return 0;
}