#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 998244353;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int l, r; cin >> l >> r;
        cout << (prefix_sums[r] - prefix_sums[l - 1] + MOD) % MOD << '\n';
    }
    return 0;
}