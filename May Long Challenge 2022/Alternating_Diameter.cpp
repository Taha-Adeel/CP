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
		int B, W;
		cin >> B >> W;
		
		if(B == 0 || W == 0){
			if(B == 1)
				cout << "B" << nl;
			else if(W == 1)
				cout << "W" << nl;
			else
				cout << "-1" << nl;

			continue;
		}

		if(B == 1){
			FOR(i, B)
				cout << 'B';
			FOR(i, W)
				cout << 'W';
		}
		else{
			FOR(i, W)
				cout << 'W';
			FOR(i, B)
				cout << 'B';
		}
		cout << nl;

		for(int i = 2; i <= B + W; i++)
			cout << "1 " << i << nl;
	}

	return 0;
}