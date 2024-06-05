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

vi convert(int a, int b) {
    string bin_a = "", bin_b = "";
    int a_copy = a, b_copy = b;
    while (a_copy) {
        bin_a += (a_copy % 2) + '0';
        a_copy /= 2;
    }
    while (b_copy) {
        bin_b += (b_copy % 2) + '0';
        b_copy /= 2;
    }
    reverse(all(bin_a));
    reverse(all(bin_b));
    a_copy = a, b_copy = b;

    string max_common_prefix = "";
    FOR (i, min(bin_a.size(), bin_b.size())) {
        if (bin_a[i] == bin_b[i]) {
            max_common_prefix += bin_a[i];
        } else {
            break;
        }
    }

    int mid_num = bitset<32>(max_common_prefix).to_ulong();
    vi ans;
    while (a_copy != mid_num) {
        if (a_copy != a) {
            ans.pb(a_copy);
        }
        a_copy /= 2;
    }
    if (mid_num != a and mid_num != b) {
        ans.pb(mid_num);
    }

    vi b_ans;
    while (b_copy != mid_num) {
        if (b_copy != b) {
            b_ans.pb(b_copy);
        }
        b_copy /= 2;
    }
    reverse(all(b_ans));
    ans.insert(ans.end(), all(b_ans));
    return ans;
}

void solve() {
    int n; cin >> n;
    vi a(n); cin >> a;

    vi b = a;
    int i = 0;
    while (i < n && a[i] == -1) {
        i++;
    }

    // -1 -1 -1 -1 ... case
    if (i == n) {
        FOR (j, n) {
            b[j] = j % 2 + 1;
        }
        cout << b;
        return;
    }

    // -1 -1 -1 x ... case
    int k = 0;
    for (int j = i - 1; j >= 0; j--, k++) {
        if (k % 2 == 0) {
            b[j] = b[j + 1] * 2;
        } else {
            b[j] = b[j + 1] / 2;
        }
    }

    int next_i = i + 1;
    while (i != n - 1) {
        while (next_i < n && a[next_i] == -1) {
            next_i++;
        }
        if (next_i == n) {
            break;
        }

        int len = next_i - i - 1;
        if (a[i] == a[next_i]) {
            if (len % 2 == 0) {
                cout << -1;
                return;
            }

            int j = 0;
            i++;
            while (i < next_i) {
                if (j % 2 == 0) {
                    b[i] = b[i - 1] * 2;
                } else {
                    b[i] = b[i - 1] / 2;
                }
                i++, j++;
            }
            next_i = i + 1;
            continue;
        }

        vi temp = convert(a[i], a[next_i]);
        if (temp.size() > len or temp.size() % 2 != len % 2) {
            cout << -1;
            return;
        }
        int j = 0;
        i++;
        while (j < temp.size()) {
            b[i] = temp[j];
            i++, j++;
        }
        j = 0;
        while (i < next_i) {
            if (j % 2 == 0) {
                b[i] = b[i - 1] * 2;
            } else {
                b[i] = b[i - 1] / 2;
            }
            i++, j++;
        }
        next_i = i + 1;
    }

    // Handle the last -1s
    int j = 0;
    i++;
    while (i < n) {
        if (j % 2 == 0) {
            b[i] = b[i - 1] * 2;
        } else {
            b[i] = b[i - 1] / 2;
        }
        i++, j++;
    }

    cout << b;
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