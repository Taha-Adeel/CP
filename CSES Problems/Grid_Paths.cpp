#include <iostream>

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0)

constexpr char nl = '\n';
using ll  = long long int;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/

string path;
bool visited[7][7];
ll answer = 0;

bool empty(int x, int y){
	return x >= 0 && x < 7 && y >=0 && y < 7 && !visited[x][y];
}

void dfs(int x, int y, int len){
	if(x == 6 && y == 0){
		if(len == 48)
			answer++;
		return;
	}
	visited[x][y] = 1;
	if(path[len] == '?' || path[len] == 'D'){
		if(x < 6 && !visited[x + 1][y]){
			if(!(!empty(x+2, y) && empty(x+1, y+1) && empty(x+1, y-1)))
				dfs(x + 1, y, len + 1);
		}
	}
	if(path[len] == '?' || path[len] == 'U'){
		if(x > 0 && !visited[x - 1][y]){
			if(!(!empty(x-2, y) && empty(x-1, y+1) && empty(x-1, y-1)))
				dfs(x - 1, y, len + 1);
		}
	}
	if(path[len] == '?' || path[len] == 'L'){
		if(y > 0 && !visited[x][y - 1]){
			if(!(!empty(x, y-2) && empty(x+1, y-1) && empty(x-1, y-1)))
				dfs(x, y - 1, len + 1);
		}
	}
	if(path[len] == '?' || path[len] == 'R'){
		if(y < 6 && !visited[x][y + 1]){
			if(!(!empty(x, y+2) && empty(x+1, y+1) && empty(x-1, y+1)))
				dfs(x, y + 1, len + 1);
		}
	}
	
	visited[x][y] = 0;
}

void solve(){
	cin >> path;

	dfs(0, 0, 0);

	cout << answer;
}

int main(){
	solve();
	cout << nl;
	
	return 0;
}