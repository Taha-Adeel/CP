#include <bits/stdc++.h>

using namespace std;

#define FOR(a,c)   for (int (a)=0; (a)<(c); ++(a))

int main(){
	int T;
	cin >> T;
	while(T--){
		int N, K;
		cin >> N >> K;
		vector<int> A(N);
		FOR(i,N){
			cin >> A[i];
		}
		int max = *max_element(A.begin(), A.end());
		int answer = 0;
		for(int i=0; 1<<i <= max; i++){
			int count = 0;
			for(auto a: A){
				count+=(a>>i)&1;
			}
			answer += count/K + (count % K != 0);
		}
		cout << answer << endl;
	}

	return 0;
}