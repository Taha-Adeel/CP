#include <bits/stdc++.h>
using namespace std;

vector<int> getScc(int n, const vector<vector<int>> &gF,
        const vector<vector<int>> &gR) {

    // Topo sort
    vector<bool> vis(n, false);
    vector<int> ord; ord.reserve(n);
    function<void(int)> dfs = [&](int u) {
        if (vis[u]) return;
        vis[u] = true;
        for (auto v: gF[u]) {
            dfs(v);
        }
        ord.push_back(u);
    };
    for (int u = 0; u < n; ++u) {
        dfs(u);
    }
    reverse(ord.begin(), ord.end());

    // Construct
    vector<int> scc(n, -1);
    int nC = 0;
    dfs = [&](int u) {
        if (scc[u] != -1) return;
        scc[u] = nC;
        for (auto v: gR[u]) {
            dfs(v);
        }
    };
    for (int u: ord) {
        if (scc[u] == -1) {
            dfs(u);
            ++nC;
        }
    }
    return scc;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<array<int, 3>> ex(n);
    for (auto &[l, r, i]: ex) {
        cin >> l >> r;
    }
    for (int i = 0; i < n; ++i) {
        ex[i][2] = i;
    }
    sort(ex.begin(), ex.end());

    vector<int> pos(n);
    for (int i = 0; i < n; ++i) {
        pos[ex[i][2]] = i;
    }

    vector<array<int, 2>> req(m);
    for (auto &[i, j]: req) {
        cin >> i >> j;
        --i; --j;
        i = pos[i];
        j = pos[j];
    }

    // Suppose we construct the nodes like a segment tree
    int sgN = 1 << __lg(2*n - 1);
    int sgSz = 2*sgN;

    vector<vector<int>> gF(2*sgSz), gR(2*sgSz);

    auto addCondition = [&](int x, int y) {
        int nX = x + (x < sgSz ? sgSz : -sgSz);
        int nY = y + (y < sgSz ? sgSz : -sgSz);
        gF[nX].push_back(y);
        gR[y].push_back(nX);
        gF[nY].push_back(x);
        gR[x].push_back(nY);
    };

    for (int p = sgN - 1; p > 0; --p) {
        addCondition(p, 2*p + sgSz);
        addCondition(p, 2*p + 1 + sgSz); 
    }

    for (auto [i, j]: req) {
        addCondition(sgN + i, sgN + j);
    }

    auto intersect = [&](int i, int l, int r) {
        l += sgN, r += sgN;
        while (l <= r) {
            if (l % 2 == 1) addCondition(i + sgN + sgSz, l++ + sgSz);
            if (r % 2 == 0) addCondition(i + sgN + sgSz, r-- + sgSz);
            l /= 2; r /= 2;
        }
    };

    // Number of starts before a point
    for (int i = 0; i < n; ++i) {
        int j = lower_bound(ex.begin(), ex.end(),
            array{ex[i][1] + 1, 0, 0}) - ex.begin();
        intersect(i, i + 1, j - 1);
    }

    auto scc = getScc(2*sgSz, gF, gR);

    for (int i = 0; i < sgSz; ++i) {
        if (scc[i] == scc[i + sgSz]) {
            cout << "NO";
            return;
        }
    }

    cout << "YES";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
        std::cout << '\n';
    }
}