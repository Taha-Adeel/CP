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
		ll N, K;
		cin >> N >> K;

		if(K == 2 || N == 1)
			cout << "ODD" << nl;
		if(K == 1)
			cout << ((N%2 == 0) ? "EVEN" : "ODD") << nl;
		else
			cout << "EVEN" << nl;
		// vector<int> A(N);
		// FOR(i, N)
		// 	A[i] = i + 1;

		// while(A.size() != 1){
		// 	A.erase(A.begin() + (K-1)%(A.size()));
		// 	FOR(i, A.size())
		// 		cout << A[i] << ' ';
		// 	cout << nl;
		// }
	}

	return 0;
}