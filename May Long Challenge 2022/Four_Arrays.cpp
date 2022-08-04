#include <bits/stdc++.h>

using namespace std;

#define FOR(a,c)   for (int (a)=0; (a)<(c); ++(a))
#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define nl '\n'
using ll = long long int;
using p_ii = pair<int,int>;
constexpr int MOD{1000000007};
constexpr ll INF{1000000000000000003};

// You need to use binary search, Fast Fourier Transformation(FFT(For polynomial multiplication))/Complex numbers for this.

int main(){
	int S_a, S_b, S_c, S_d;
	cin >> S_a >> S_b >> S_c >> S_d;
	ll K;
	cin >> K;
	

	vector<int> A(S_a), B(S_b), C(S_c), D(S_d);
	FOR(i, S_a)
		cin >> A[i];
	FOR(i, S_b)
		cin >> B[i];
	FOR(i, S_c)
		cin >> C[i];
	FOR(i, S_d)
		cin >> D[i];

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	sort(C.begin(), C.end());
	sort(D.begin(), D.end());

	vector<tuple<ll, int, int, int, int>> board;

	FOR(i, S_a){
		FOR(j, S_b){
			FOR(k, S_c){
				FOR(l, S_d){
					board.push_back({(A[i] + B[j]) * (C[k] + D[l]), i, j, k, l});
				}
			}
		}
	}
	sort(board.begin(), board.end(), [](tuple<ll, int, int, int, int> a1, tuple<ll, int, int, int, int> a2){return get<0>(a1) < get<0>(a2);});

	for(auto& num: board){
		cout << get<0>(num) << "\t (" << get<1>(num) << "+" << get<2>(num) << ") * (" << get<3>(num) << "+" << get<4>(num) << ") \n";
	}

	// cout << get<0>(board[K - 1]) << nl;
	

	return 0;
}