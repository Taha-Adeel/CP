#include <bits/stdc++.h>

using namespace std;

#define FOR(a,c)   for (int (a)=0; (a)<(c); ++(a))
#define nl '\n'

int main(){
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		vector<int> s(n);
		map<int, int> freqs;
		FOR(i, n){
			cin >> s[i];
			freqs[s[i]]++;
		}
		
		bool valid = true;
		vector<int> answer(n);
		int permuted_shoes = 0;
		FOR(i, n){
			if(freqs[s[i]] == 1){
				valid = false;
				break;
			}
			if(i == permuted_shoes){
				answer[i] = i + freqs[s[i]] - 1;
			}
			else{
				answer[i] = i - 1;
				if(i == permuted_shoes + freqs[s[i]] - 1)
					permuted_shoes += freqs[s[i]];
			}
		}

		if(valid){
			FOR(i, n)
				cout << answer[i] + 1 << ' ';
			cout << nl;
		}
		else
			cout << -1 << nl;
	}

	return 0;
}