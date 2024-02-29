#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    ll x;
    cin >> n >> k >> x;

    string s;
    cin >> s;
    reverse(s.begin(), s.end());

    vector<int> bs{{0}};
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'a') {
            if (bs.back() > 0) {
                bs.push_back(0);
            }
        } else {
            bs.back()++;
        }
    }

    if (bs.back() == 0) {
        bs.pop_back();
    }

    vector<int> vals(bs.size());
    ll m = 1;
    int i = 0;
    --x;
    for (int b: bs) {
        // cerr << "At i = " << i << " b = " << b << " m = " << m << " x = " << x << '\n';
        if (m * (b*k + 1) <= x) {
            m *= b*k + 1;
            ++i;
        } else {
            break;
        }
    }

    while (i >= 0 and x) {
        // Fill vals[i] and decrement i
        vals[i] = x / m;
        x -= vals[i] * m;
        --i;
        if (i >= 0) {
            m /= (bs[i]*k + 1);
        }
    }

    // cerr << "vals: ";
    // for (auto x : vals) {
    //     cerr << x << " ";
    // }
    // cerr << '\n';

    string ans = "";
    i = 0; 
    int j = 0;
    while (i < n) {
        if (s[i] == 'a') {
            ans += 'a';
            ++i;
        } else {
            ans += string(vals[j], 'b');
            ++j;
            while (i < n and s[i] == '*') {
                ++i;
            }
        }
    }
    reverse(ans.begin(), ans.end());

    cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}