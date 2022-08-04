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
		int N;
		cin >> N;

		vector<int> A(N), B(N);
		FOR(i, N)
			cin >> A[i];
		FOR(i, N)
			cin >> B[i];

		vector<int> bit_count_a(32, 0), bit_count_b(32, 0);
		FOR(i, N){
			for(int i = 0; i < 32; i++){
				int mask = 1<<i;
				if(A[i] & mask)	bit_count_a[i]++;
				if(B[i] & mask)	bit_count_b[i]++;
			}
		}
		int X = 0;
		bool possible = true;
		for(int i = 0; i < 32; i++){
			if(bit_count_b[i] - bit_count_a[i] > 0)
				X ^= 1<<i;
			else if(bit_count_b[i] - bit_count_a[i] < 0)
				possible = false;
		}
		if(possible)
			cout << X << nl;
		else
			cout << -1 << nl;
	}

	return 0;
}