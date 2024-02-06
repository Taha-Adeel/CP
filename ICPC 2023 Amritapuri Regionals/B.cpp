#include <bits/stdc++.h>
using namespace std;

array<array<int, 2>, 45> fn() {
    array<int, 10> a;
    iota(a.begin(), a.end(), 0);
    array<array<int, 2>, 45> res;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 5; ++j) {
            res[i*5 + j] = {a[j], a[9-j]};
        }
        for (int j = 9; j > 1; --j) {
            swap(a[j], a[j-1]);
        }
    }
    return res;
}
auto matches = fn();

int k;
array<int, 10> sc;

bool isPossible() {
    if (k == 45) {
        int g = 0;
        for (int i = 1; i < 10; ++i) {
            g += sc[i] > sc[0];
        }
        return g < 4;
    }

    auto [t1, t2] = matches[k];
    k++;

    if (t1 == 0) {
        sc[t1]++;
        auto res = isPossible();
        sc[t1]--;
        k--;
        return res;
    }

    sc[t1]++;
    if (isPossible()) {
        k--;
        sc[t1]--;
        return true;
    }
    sc[t1]--;
    sc[t2]++;
    auto res = isPossible();
    sc[t2]--;
    k--;
    return res;
}

void solve() {
    cin >> k;

    string s;
    cin >> s;

    fill(sc.begin(), sc.end(), 0);
    for (int i = 0; i < k; ++i) {
        auto [t1, t2] = matches[i];
        if (s[i] == '1') {
            sc[t1]++;
        } else {
            sc[t2]++;
        }
    }

    if (isPossible()) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
        cout << '\n';
    }
}