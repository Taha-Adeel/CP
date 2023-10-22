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
    int component = -1;
    int captures = 0;
};

void solve(){
    int r, c; cin >> r >> c;
    V<string> grid(r); cin >> grid;

    V<V<Node>> nodes(r, V<Node>(c));
    auto adj = [&](int i, int j){
        V<pii> res;
        if(i-1 >= 0) res.pb({i-1, j});
        if(i+1 < r) res.pb({i+1, j});
        if(j-1 >= 0) res.pb({i, j-1});
        if(j+1 < c) res.pb({i, j+1});
        return res;
    };
    auto bfs = [&](int i, int j, int component){
        set<pii> surrounding_empty_cells;
        queue<pii> q;
        q.push({i, j});
        nodes[i][j].component = component;
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            for(auto [nx, ny]: adj(x, y)){
                if(grid[nx][ny] == 'W' && nodes[nx][ny].component == -1){
                    nodes[nx][ny].component = component;
                    q.push({nx, ny});
                }
                else if(grid[nx][ny] == '.' && nodes[nx][ny].component == -1)
                    surrounding_empty_cells.insert({nx, ny});
            }
            if(surrounding_empty_cells.size() > 1)
                break;
        }
        return surrounding_empty_cells;
    };

    map<pii, vi> m_empty_cells;
    FOR(i, r) FOR(j, c){
        if(grid[i][j] == 'W' && nodes[i][j].component == -1){
            int component = i*c + j;
            auto surrounding_empty_cells = bfs(i, j, component);
            if(surrounding_empty_cells.size() == 1){
                auto [x, y] = *surrounding_empty_cells.begin();
                m_empty_cells[{x, y}].pb(component);
            }
        }
    }

    map<int, int> m_component_size;
    FOR(i, r) FOR(j, c) if(grid[i][j] == 'W' && nodes[i][j].component != -1)
        m_component_size[nodes[i][j].component]++;

    for(auto [empty_cell, components]: m_empty_cells){
        int x, y; tie(x, y) = empty_cell;
        for(auto c: components)
            nodes[x][y].captures += m_component_size[c];
    }

    int ans = 0;
    FOR(i, r) FOR(j, c) 
        ans = max(ans, nodes[i][j].captures);
    cout << ans;
}

int main(){
    FAST;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    FOR(t, T){
        cout << "Case #" << t+1 << ": ";
        solve();
        cout << nl;
    }
    
    return 0;
}