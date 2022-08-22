#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



/*
 * Complete the 'getPathXORAND' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. WEIGHTED_INTEGER_GRAPH tree
 *  2. 2D_INTEGER_ARRAY queries
 */

/*
 * For the weighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] and <name>_to[i]. The weight of the edge is <name>_weight[i].
 *
 */

#define V vector
#define F first
#define S second
#define FOR(i, n) for(int i = 0; i < (int)n; i++)
using vi = V<int>;
using pii = pair<int, int>;
using ll = long long;
 
struct Node{
    int parent = -1;
    int depth = 0;
    vi set_bit_count = vi(21, 0);
    vi unset_bit_count = vi(21, 0);
    V<pii> adj_list;
};

void dfs(int root, V<Node>& tree){
    for(auto& e: tree[root].adj_list){
        if(e.F == tree[root].parent) continue;
        for(int i = 0; i < 21; i++)
            tree[e.F].set_bit_count[i] = tree[root].set_bit_count[i] + ((e.S&(1<<i)?1:0));
        for(int i = 0; i < 21; i++)
            tree[e.F].unset_bit_count[i] = tree[root].unset_bit_count[i] + ((e.S&(1<<i)?0:1));
        tree[e.F].parent = root;
        tree[e.F].depth = tree[root].depth + 1;
        dfs(e.F, tree);
    }
}

int LCA(int u, int v, const V<Node>& tree){
    if(u == v) return u;
    if(tree[u].depth < tree[v].depth) swap(u, v);
    return LCA(tree[u].parent, v, tree);
}

vector<int> getPathXORAND(int n, vector<int> u, vector<int> v, vector<int> w, vector<vector<int>> queries) {
    V<Node> tree(n);
    FOR(i, n-1){
        tree[--u[i]].adj_list.push_back({--v[i], w[i]});
        tree[v[i]].adj_list.push_back({u[i], w[i]});
    }
    
    dfs(0, tree);
    
    vector<int> ans_vec;
    for(auto& q: queries){
        ll ans = 0, u = q[0]-1, v = q[1] - 1;
        ll lca = LCA(u, v, tree);
        for(int i = 0; i < 21; i++){
            int set_bit_count = tree[u].set_bit_count[i] + tree[v].set_bit_count[i] - 2 * tree[lca].set_bit_count[i];
            int unset_bit_count = tree[u].unset_bit_count[i] + tree[v].unset_bit_count[i] - 2 * tree[lca].unset_bit_count[i];
            if(set_bit_count > 0) ans += (1<<i);
            if(set_bit_count%2) ans += (1<<i);
            if(unset_bit_count == 0 && set_bit_count > 0) ans += (1<<i);
        }
        ans_vec.push_back(ans);
    }
    
    return ans_vec;
}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    string tree_nodes_edges_temp;
    getline(cin, tree_nodes_edges_temp);

    vector<string> tree_nodes_edges = split(rtrim(tree_nodes_edges_temp));

    int tree_nodes = stoi(tree_nodes_edges[0]);
    int tree_edges = stoi(tree_nodes_edges[1]);

    vector<int> tree_from(tree_edges);
    vector<int> tree_to(tree_edges);
    vector<int> tree_weight(tree_edges);

    for (int i = 0; i < tree_edges; i++) {
        string tree_from_to_weight_temp;
        getline(cin, tree_from_to_weight_temp);

        vector<string> tree_from_to_weight = split(rtrim(tree_from_to_weight_temp));

        int tree_from_temp = stoi(tree_from_to_weight[0]);
        int tree_to_temp = stoi(tree_from_to_weight[1]);
        int tree_weight_temp = stoi(tree_from_to_weight[2]);

        tree_from[i] = tree_from_temp;
        tree_to[i] = tree_to_temp;
        tree_weight[i] = tree_weight_temp;
    }

    string queries_rows_temp;
    getline(cin, queries_rows_temp);

    int queries_rows = stoi(ltrim(rtrim(queries_rows_temp)));

    string queries_columns_temp;
    getline(cin, queries_columns_temp);

    int queries_columns = stoi(ltrim(rtrim(queries_columns_temp)));

    vector<vector<int>> queries(queries_rows);

    for (int i = 0; i < queries_rows; i++) {
        queries[i].resize(queries_columns);

        string queries_row_temp_temp;
        getline(cin, queries_row_temp_temp);

        vector<string> queries_row_temp = split(rtrim(queries_row_temp_temp));

        for (int j = 0; j < queries_columns; j++) {
            int queries_row_item = stoi(queries_row_temp[j]);

            queries[i][j] = queries_row_item;
        }
    }

    vector<int> result = getPathXORAND(tree_nodes, tree_from, tree_to, tree_weight, queries);

    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

    // fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
