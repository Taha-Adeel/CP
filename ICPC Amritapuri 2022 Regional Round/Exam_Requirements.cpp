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

    vector<array<int, 2>> ex(n);
    for (auto &[l, r]: ex) {
        cin >> l >> r;
    }

    vector<array<int, 2>> req;
    vector<vector<int>> g(n);
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v;
        --u, --v;
        if (ex[u][0] > ex[v][0]) swap(u, v);
        if (ex[v][0] <= ex[u][1]) {
            g[u].push_back(v);
            g[v].push_back(u);
        } else {
            req.push_back({u, v});
        }
    }

    vector<int> d(n, -1), f(n, -1);
    bool ok = true;
    int cur = -1;
    function<void(int)> dfs = [&](int u) {
        f[u] = cur;
        for (int v: g[u]) {
            if (not ok) return;
            if (d[v] == -1) {
                d[v] = d[u] + 1;
                dfs(v);
            } else if ((d[u]^d[v]) % 2 == 0) {
                ok = false;
                return;
            }
        }
    };
    for (int u = 0; u < n and ok; ++u) {
        if (d[u] == -1) {
            d[u] = 0;
            cur = u;
            dfs(u);
        }
    }

    // cerr << "f: ";
    // for (auto u = 0; u < n; ++u) {
    //     cerr << f[u] << ' ';
    // }
    // cerr << '\n';

    // cerr << "d: ";
    // for (auto u = 0; u < n; ++u) {
    //     cerr << d[u] << ' ';
    // }
    // cerr << '\n';

    // cerr << "p: ";
    // for (auto u = 0; u < n; ++u) {
    //     cerr << p[u] << ' ';
    // }
    // cerr << '\n';

    if (not ok) {
        cout << "NO";
        return;
    }

    vector<vector<int>> gF(2*n), gR(2*n);
    for (auto [u, v]: req) {
        u = f[u] + ((d[u] & 1) ? n : 0);
        v = f[v] + ((d[v] & 1) ? n : 0);
        int nu = u + ((u >= n) ? -n : n);
        int nv = v + ((v >= n) ? -n : n);
        // cerr << (u + nu - n) / 2 << ' ' << (v + nv - n) / 2 << '\n';
        gF[nu].push_back(v);
        gR[v].push_back(nu);
        gF[nv].push_back(u);
        gR[u].push_back(nv);
    }

    auto scc = getScc(2*n, gF, gR);
    for (int u = 0; u < n; ++u) {
        if (scc[u] == scc[u+n]) {
            ok = false;
            break;
        }
    }

    cout << (ok ? "YES" : "NO");
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