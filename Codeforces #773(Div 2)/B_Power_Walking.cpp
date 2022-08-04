#include <bits/stdc++.h>

using namespace std;

#define FOR(a,c)   for (int (a)=0; (a)<(c); ++(a))

int main(){
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		map<int, int> freq;
		int threshold = 1;
		FOR(i, n){
			int a_i;
			cin >> a_i;
			if(++freq[a_i] > 1)
				threshold++;
		}
		int answer = freq.size();
		for(int k = 0; k < n; ++k){
			if(k > n - threshold)
				answer++;
			
			cout << answer << ' ';
		}
		cout << '\n';
	}

	return 0;
}