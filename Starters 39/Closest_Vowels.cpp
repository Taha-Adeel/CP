#include <bits/stdc++.h>

using namespace std;

#define FOR(a,c)   for (int (a)=0; (a)<(c); ++(a))
#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define nl '\n'
constexpr int MOD{1000000007};

int main(){
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;

		int answer = 1;
		char c;
		FOR(i, N){
			cin >> c;
			if(c == 'c' || c == 'g' || c == 'l' || c == 'r')
				answer = (answer * 2) % MOD;
		}

		cout << answer << nl;
	}

	return 0;
}