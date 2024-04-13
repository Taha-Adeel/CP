#include <bits/stdc++.h>

using namespace std;

using ll = long long;
constexpr int MOD = 1000000007;

void solve() {
    int n, m; 
    cin >> n >> m;
    vector<ll> a(n);
    for (auto& i: a) cin >> i;

    vector<vector<vector<ll>>> dp(n, vector(m, vector<ll>(2, 0))); // dp[i][j][k] = number of ways such a[i] = j and kth condn is satisfied
    for (int j = 0; j < m; j++) {
        if (a[0] == -1 || a[0] - 1 == j) {
            dp[0][j][0] = 1;
            dp[0][j][1] = 1;
        }
    }
    for (int i = 1; i < n; i++) {
        for (int k = 0; k < 2; k++) {
            if (i % 2 == k) { // => a[i] < a[i-1]
                ll sum = 0;
                for (int j = 0; j < m; j++) {
                    sum += dp[i-1][j][k];
                    sum %= MOD;
                }
                for (int j = 0; j < m; j++) {
                    sum -= dp[i-1][j][k];
                    sum = (sum + MOD) % MOD;
                    dp[i][j][k] = sum;
                }
            } else { // => a[i] > a[i-1]
                ll sum = 0;
                for (int j = 0; j < m; j++) {
                    dp[i][j][k] = sum;
                    sum += dp[i-1][j][k];
                    sum %= MOD;
                }
            }

            if (a[i] != -1) {
                for (int j = 0; j < m; j++) {
                    if (a[i] - 1 != j) {
                        dp[i][j][k] = 0;
                    }
                }
            }
        }
    }

    ll ans = 0;
    for (int j = 0; j < m; j++) {
        ans += dp[n-1][j][0] + dp[n-1][j][1];
        ans %= MOD;
    }

    cout << ans << '\n';
}

int main() {
    solve();

    return 0;
}