#include <bits/stdc++.h>

using namespace std;

#define nl '\n'

int main(){
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;

		string binary_string;
		cin >> binary_string;

		int mismatches = 0;
		for(int i = 0; i < N/2; i++){
			if(binary_string[i] != binary_string[(N-1) - i]){
				mismatches++;
			}
		}

		int answer = mismatches/2 + mismatches%2;
		cout << answer << nl;
	}

	return 0;
}