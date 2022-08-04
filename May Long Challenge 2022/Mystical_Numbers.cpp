#include <bits/stdc++.h>
using namespace std;
#define FOR(a,c)   for (int (a)=0; (a)<(c); ++(a))
#define nl '\n'
using ll = long long int;

int main(){
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		vector<int> A(N);
		vector<array<int, 32>> num(N+1, array<int, 32>{0});
		FOR(i, N){
			cin >> A[i];
			int msb_pos = 0;
			while(A[i] != 0){
				msb_pos++;
				A[i] /= 2;			}
			for(int m = 0; m < 32; m++){
				if(m == msb_pos)
					num[i+1][msb_pos] = num[i][msb_pos] + 1;
				else
					num[i+1][m] = num[i][m];			}		}
		int Q;
		cin >> Q;
		FOR(i, Q){
			int L, R, X;
			cin >> L >> R >> X;
			int msb_pos = 0;
			while(X != 0){
				msb_pos++;
				X /= 2;			}
			int count = (R - L + 1) - (num[R][msb_pos] - num[L-1][msb_pos]);
			cout << count << nl;		}	}
	return 0;
}