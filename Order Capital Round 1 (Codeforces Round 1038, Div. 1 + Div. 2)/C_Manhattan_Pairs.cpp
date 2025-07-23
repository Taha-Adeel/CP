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
    vi x(n), y(n);
    FOR (i, n) {
        cin >> x[i] >> y[i];
        x[i] *= 2;
        y[i] *= 2;
    }

    vi x_ = x, y_ = y;
    sort(all(x_));
    sort(all(y_));
    int x_median = (x_[n / 2] + x_[(n - 1) / 2]) / 2;
    int y_median = (y_[n / 2] + y_[(n - 1) / 2]) / 2;

    stack<int> lxly, lxhy, hxly, hxhy;
    stack<int> lxey, hxey, exly, exhy, exey;
    FOR (i, n) {
        if (x[i] < x_median && y[i] < y_median)
            lxly.push(i);
        else if (x[i] < x_median && y[i] > y_median)
            lxhy.push(i);
        else if (x[i] > x_median && y[i] < y_median)
            hxly.push(i);
        else if (x[i] > x_median && y[i] > y_median)
            hxhy.push(i);
        else if (x[i] < x_median && y[i] == y_median)
            lxey.push(i);
        else if (x[i] > x_median && y[i] == y_median)
            hxey.push(i);
        else if (x[i] == x_median && y[i] < y_median)
            exly.push(i);
        else if (x[i] == x_median && y[i] > y_median)
            exhy.push(i);
        else if (x[i] == x_median && y[i] == y_median)
            exey.push(i);
    }

    V<pii> ans;
    auto add = [&](stack<int>& s1, stack<int>& s2) {
        int i = s1.top(); s1.pop();
        int j = s2.top(); s2.pop();
        ans.pb({i, j});
    };

    auto add_all = [&](stack<int>& sll, stack<int>& shh, stack<int>& she, stack<int>& seh) {
        while (!sll.empty()) {
            if (shh.size()) {
                add(sll, shh);
            } else if (she.size()) {
                add(sll, she);
            } else if (seh.size()) {
                add(sll, seh);
            } else if (exey.size()) {
                add(sll, exey);
            } else {
                return;
            }
        }
    };

    add_all(lxly, hxhy, hxey, exhy);
    add_all(lxhy, hxly, hxey, exly);
    add_all(hxly, lxhy, lxey, exhy);
    add_all(hxhy, lxly, lxey, exly);

    add_all(lxey, hxey, exly, exhy);
    add_all(hxey, lxey, exly, exhy);
    add_all(exly, exhy, lxey, hxey);
    add_all(exhy, exly, lxey, hxey);

    while (exey.size() >= 2) {
        add(exey, exey);
    }

    for (auto& [i, j]: ans) {
        cout << i + 1 << ' ' << j + 1 << nl;
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