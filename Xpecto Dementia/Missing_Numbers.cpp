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
		int N, K, X;
		cin >> N >> K >> X;

		vector<int> A(N - K);
		int rem_xor = 0;
		
		FOR(i, N - K){
			cin >> A[i];
			rem_xor ^= A[i];
		}
		int pointer = 1;
		int a = 0;
		FOR(i, 30){
			if((pointer & X) && !(pointer & rem_xor))
				a++;
			else if(!(pointer & X) && (pointer & rem_xor))
				a++;
			pointer <<= 1;
		}
		ll answer = 1;
		// Below part inaccurate
		FOR(i, a - 1){
			answer = (answer * K) % MOD;
		}
		cout << answer << nl;
	}

	return 0;
}