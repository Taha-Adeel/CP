#include <bits/stdc++.h>

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0)
template<class T> struct V: vector<T>{using vector<T>::vector;
    void sort()            {std::sort(this->begin(), this->end());}
    void sort_dsc()     {std::sort(this->begin(), this->end(), greater<T>());}
    auto sum()             {T sum = 0; for(auto& i: *this) sum += i; return sum;}
    auto freqs()         {map<T, int> freq; for(auto& i: *this) freq[i]++; return freq;}
    auto indices()        {int n=this->size(); map<T, V<int>> ii; for(int i=0; i<n; i++) ii[(*this)[i]].push_back(i); return ii;}
    auto prefix_sums()     {int n=this->size(); V<T> ps(n+1,0); for(int i=0; i<n; i++) ps[i+1] = ps[i]+(*this)[i]; return ps;}
    friend ostream& operator<<(ostream& out, const V<T>& v) {for(auto& i: v) out << i << ' '; return out;}
    friend istream& operator>>(istream& in, V<T>& v) {for(auto& i: v) in >> i; return in;}
};
#define pY {cout << "YES"; return;}
#define pN {cout << "NO";  return;}
#define display(x) if(x) pY else pN

#define FOR(i, n)                for(int i = 0; i < (int)n; ++i)
#define FOR1(i, n)               for(int i = 1; i <= (int)n; ++i)
#define ROF(i, n)                for(int i = (int)n-1; i >= 0; --i)
#define all(v)                   v.begin(), v.end()
#define rall(v)                  v.rbegin(), v.rend()

#define F  first
#define S  second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
constexpr char nl = '\n';
constexpr int MOD = 1000000007;
using ll  = long long int;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi  = V<int>;
using vll = V<ll>;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/

struct Node{
    bool visited = false;
    bool is_red = false;
    int parent = -1;
    vi adj_list;
    int red_subtree_cnt = 0;
};

void dfs(int u, V<Node>& tree){
    if(tree[u].is_red) tree[u].red_subtree_cnt++;
    tree[u].visited = true;
    for(auto& v: tree[u].adj_list){
        if(tree[v].visited) continue;
        tree[v].parent = u;
        dfs(v, tree);
        tree[u].red_subtree_cnt += tree[v].red_subtree_cnt;
    }
}

// Returns diamter(maximum distance between any two nodes) of the tree
int get_diameter(V<Node>& tree){
    int n = tree.size();
    int diameter = 0;
    function<int(int, int)> dfs = [&](int u, int p){
        int max_depth = 0;
        int second_max_depth = 0;
        for(auto& v: tree[u].adj_list){
            if(v == p) continue;
            int depth = dfs(v, u);
            if(depth > max_depth){
                second_max_depth = max_depth;
                max_depth = depth;
            }
            else if(depth > second_max_depth){
                second_max_depth = depth;
            }
        }
        diameter = max(diameter, max_depth + second_max_depth);
        return max_depth + 1;
    };
    FOR(i, n) if(tree[i].is_red) {dfs(i, -1); break;}
    return diameter;
}

void solve(){
    int n, k; cin >> n >> k;
    V<Node> tree(n);
    FOR(i, k){
        int x; cin >> x; x--;
        tree[x].is_red = true;
    }
    FOR(i, n-1){
        int u, v; cin >> u >> v; u--, v--;
        tree[u].adj_list.pb(v);
        tree[v].adj_list.pb(u);
    }

    dfs(0, tree);

    // // Prune subtrees with no red nodes
    FOR(i, n){
        if(tree[i].red_subtree_cnt == 1 && tree[i].is_red){
            tree[i].adj_list.clear();
            if(tree[i].parent != -1) 
                tree[i].adj_list.pb(tree[i].parent);
        }
        else if(tree[i].red_subtree_cnt == 0){
            if(tree[i].parent != -1){
                auto it = find(all(tree[tree[i].parent].adj_list), i);
                if(it != tree[tree[i].parent].adj_list.end()) tree[tree[i].parent].adj_list.erase(it);
            }
            tree[i].adj_list.clear();
        }
        if(tree[i].red_subtree_cnt == k){
            if(tree[i].parent != -1)
                tree[i].adj_list.erase(find(all(tree[i].adj_list), tree[i].parent)),
                tree[tree[i].parent].adj_list.erase(find(all(tree[tree[i].parent].adj_list), i));
            tree[i].parent = -1;
        }
    }

    cout << (get_diameter(tree) + 1) / 2;
}

int main(){
    FAST;
    int T;
    cin >> T;
    FOR(t, T){
        solve();
        cout << nl;
    }
    
    return 0;
}