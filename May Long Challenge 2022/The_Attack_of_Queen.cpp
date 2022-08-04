#include <bits/stdc++.h>

using namespace std;

int main(){
	int T;
	cin >> T;
	while(T--){
		int N, X, Y;
		cin >> N >> X >> Y;

		cout << (N - 1) + (N - 1) + min(X - 1, Y - 1) + min(N - X, Y - 1) + min(X - 1, N - Y) + min(N - X, N - Y) << endl;
	}

	return 0;
}