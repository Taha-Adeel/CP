// Wrong code
#include <bits/stdc++.h>

using namespace std;

#define FOR(a,c)   for (int (a)=0; (a)<(c); ++(a))
#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define nl '\n'
using ll = long long int;
using p_ii = pair<int,int>;
constexpr int MOD{1000000007};
constexpr ll INF{1000000000000000003};

struct Cell{
	int predecessor;
	int value;
	int successor;
};

int main(){
	int T;
	cin >> T;
	while(T--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> grid(n, vector<int>(m));

		FOR(i, n){
			FOR(j, m){
				cin >> grid[i][j];
			}
		}
		vector<Cell> invalid_cells;
		map<int, int> invalid_columns;
		for(int i = 0; i < n; ++i){
			for(int j = 1; j < m; ++j){
				if(grid[i][j] < grid[i][j-1]){
					Cell invalid_cell;
					invalid_cell.value = grid[i][j];
					invalid_cell.predecessor = grid[i][j-1];
					if(j == m - 1)
						invalid_cell.successor = INT_MAX;
					else
						invalid_cell.successor = grid[i][j+1];
					
					invalid_cells.push_back(invalid_cell);
					invalid_columns[j]++;
				}
			}
		}
		if(invalid_columns.size() == 0){
			cout << "1 1" << nl;
			continue;
		}
		else if(invalid_columns.size() == 2){
			int j1, j2, counter = 0;
			for(auto c: invalid_columns){
				if(counter == 0)
					j1 = c.first;
				else
					j2 = c.first;
				counter++;
			}
			FOR(i, n){
				swap(grid[i][j1], grid[i][j2]);
			}
			bool good = true;
			for(int i = 0; i < n; ++i){
				for(int j = 1; j < m; ++j){
					if(grid[i][j] < grid[i][j-1]){
						good = false;
					}
				}
			}
			if(good)
				cout << j1 << ' ' << j2 << nl;
			else
				cout << -1 << nl;
		}
		else if(invalid_columns.size() > 2){
			cout << -1 << nl;
		}
		else{
			int j1;
			for(auto c: invalid_columns)
				j1 = c.first;
			bool bad = true;
			FOR(j, j1){
				FOR(i, n){
					swap(grid[i][j1], grid[i][j]);
				}
				bool good = true;
				for(int i = 0; i < n; ++i){
					for(int j = 1; j < m; ++j){
						if(grid[i][j] < grid[i][j-1]){
							good = false;
						}
					}
				}
				if(good){
					cout << j1 << ' ' << j + 1 << nl;
					bad = false;
					break;
				}
			}
			if(bad)
				cout << -1 << nl;
		}

	}

	return 0;
}