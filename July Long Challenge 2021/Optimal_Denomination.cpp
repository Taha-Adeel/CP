#include <bits/stdc++.h>

using namespace std;

#define FOR(a,c)   for (int (a)=0; (a)<(c); ++(a))
#define FAST ios::sync_with_stdio(0); cin.tie(0)

long long int gcd(long long int a, long long int b){
    if(b == 0)
        return a;
    return gcd(b, a%b);     
}

int main(){
	FAST;

	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		vector<long long int> A(N);
		long long int total{0};
		FOR(i,N){
			cin >> A[i];
			total+=A[i];
		}

		vector<long long int> gl(N), gr(N);
		gl[0]=A[0];
		gr[0]=A[N-1];
		for(int i=1; i<N; ++i){
			gl[i]=gcd(gl[i-1], A[i]);
			gr[i]=gcd(gr[i-1], A[N-i-1]);
		}

		vector<int> notes;
		long long int answer = (total-A[0]+gr[N-2])/gr[N-2];
		for(int i=1; i<N-1; i++){
			long long int GCD = gcd(gl[i-1], gr[N-i-2]);
			answer = min((total-A[i]+GCD)/GCD, answer);
		}
		answer = min((total-A[N-1]+gl[N-2])/gl[N-2], answer);
		cout << answer << endl;
	}

	return 0;
}