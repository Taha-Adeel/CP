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
    vector<int> v(n);
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        m[v[i]]++;
    }

    vector<int> elements_to_erase;
    int ans;
    for (int i = 0; i < 5; i++) {
        if (v.size() - elements_to_erase.size() == 1) {
            cout << "! " << ans << endl;
            return;
        }
        cout << "- " << elements_to_erase.size() << " ";
        for (int j = 0; j < elements_to_erase.size(); j++) {
            cout << elements_to_erase[j] << " ";
        }
        cout << endl;
        vector<int> new_v;
        map<int, int> new_m;
        for (int j = 0; j < v.size() - elements_to_erase.size(); j++) {
            int x;
            cin >> x;
            new_v.push_back(x);
            new_m[x]++;
        }
        elements_to_erase.clear();
        int tm = -1;
        for (auto& k : new_m) {
            if (k.second > m[k.first]) {
                tm = k.first;
            }
        }
        if (tm != -1) {
            for (int j = 0; j < new_v.size(); j++) {
                if (new_v[j] != tm)
                    elements_to_erase.push_back(j + 1);
                else
                    ans = j + 1;
            }
            m.clear();
            m[tm] = new_m[tm];
        }
        v = new_v;
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