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

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    cin >> m >> n;

    vector<vector<int>> gF(2*n), gR(2*n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        char c1, c2;
        cin >> c1 >> u >> c2 >> v;
        --u; --v;
        u += (c1 == '-') * n;
        v += (c2 == '-') * n;
        int nu = u + ((u >= n) ? -n : n);
        int nv = v + ((v >= n) ? -n : n);
        gF[nu].push_back(v);
        gR[v].push_back(nu);
        gF[nv].push_back(u);
        gR[u].push_back(nv);
    }

    auto scc = getScc(2*n, gF, gR);
    for (int u = 0; u < n; ++u) {
        if (scc[u] == scc[u+n]) {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }

    for (int u = 0; u < n; ++u) {
        if (scc[u] > scc[u+n]) {
            cout << '+';
        } else {
            cout << '-';
        }
        cout << ' ';
    }
}
