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

vi get_binary(int x) {
    vi binary;
    while (x) {
        binary.pb(x % 2);
        x /= 2;
    }

    return binary;
}

bool has_consecutive_ones(int x) {
    vi binary = get_binary(x);
    int n = binary.size();
    FOR(i, n-1) {
        if (binary[i] == 1 && binary[i+1] == 1) return true;
    }

    return false;
}

int next_pow_2(int x) {
    int ans = 1;
    while (ans < x) ans *= 2;
    return ans;
}

void solve(int x) {
    vi nums;
    int sign = 1;
    while (has_consecutive_ones(x)) {
        nums.pb(sign * next_pow_2(x));
        x = next_pow_2(x) - x;
        sign *= -1;
    }
    nums.pb(sign * x);

    vi ans(32);
    for (int num: nums) {
        vi binary = get_binary(abs(num));
        int n = binary.size();
        FOR(i, n) {
            if (binary[i]) ans[i] = num / abs(num);
        }
    }

    FOR (i, 31) {
        if (ans[i] == -1 and ans[i+1] == 1) {
            ans[i] = 1;
            ans[i+1] = 0;
        } else if (ans[i] == 1 and ans[i+1] == -1) {
            ans[i] = -1;
            ans[i+1] = 0;
        }
    }
    while (ans.size() and ans.back() == 0) ans.pop_back();

    cout << ans.size() << nl;
    cout << ans;
}

int main() {
    FAST;
    int T; cin >> T;
    FOR(t, T) {
        int x; cin >> x;
        solve(x);
        cout << nl;
    }
    
    return 0;
}