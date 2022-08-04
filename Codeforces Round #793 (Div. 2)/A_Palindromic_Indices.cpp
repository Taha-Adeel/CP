#include <bits/stdc++.h>

using namespace std;

#define FOR(a,c)   for (int (a)=0; (a)<(c); ++(a))
#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define nl '\n'
using ll = long long int;
using p_ii = pair<int,int>;
constexpr int MOD{1000000007};
constexpr ll INF{1000000000000000003};

int main(){
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		string s;
		cin >> s;

		int answer =-(n%2);
		char rep = s[n/2];
		for(int i = n/2; s[i] == rep; i++){
			answer+=2;
		}

		cout << answer << nl;
	}

	return 0;
}