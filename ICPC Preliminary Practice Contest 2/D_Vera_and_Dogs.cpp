#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, X;
	cin >> N >> X;
	if(X>=N){
		cout << -1 << endl;
		return 0;
	}

	for(int n=0; n<N; ++n){
		for(int x1=0; x1 < X; ++x1){
			cout << (n*X) + x1 + 1 << ' ';
		}
		for(int x2=0; x2<X; ++x2){
			int temp = (n + x2 - X)%N ;
			cout << ((temp < 0)? (temp+N)*X + x2 + 1 : temp*X + x2 + 1) << ' ';
		}
		cout << endl;
	}

	return 0;
}