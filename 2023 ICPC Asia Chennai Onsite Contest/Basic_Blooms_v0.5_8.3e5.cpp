#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 998244353;

vector<int> prefix_sums;

int from_base_x(string num) {
    int base = 90;
    int res = 0;
    for (int i = 0; i < num.size(); ++i) {
        res *= base;
        int digit = num[i];
        if(digit < 0) digit = -digit + 126;
        if(digit >= '?') digit--;
        if(digit >= '\\') digit--;
        res += digit - 35;
    }
    return res;
}

int main() {
    for (int i = 0; i < prefix_sums_brute.size(); i += 5) {
        prefix_sums.push_back(from_base_x(prefix_sums_brute.substr(i, 5)));
    }
    int t;
    cin >> t;
    while (t--) {
        int l, r; cin >> l >> r;
        cout << (prefix_sums[r] - prefix_sums[l - 1] + MOD) % MOD << '\n';
    }
    return 0;
}