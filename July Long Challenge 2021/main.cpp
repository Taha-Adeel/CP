#include <bits/stdc++.h>
using namespace std;

int main(){
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;

		vector<int> a(n+2);
		map<int, vector<int>> aj;
		for(int i=0; i<n+2; i++){
			cin >> a[i];
			aj[a[i]%(2*n)].push_back(a[i]);
		}

		for(int i=0; i<n+2; ++i){
			if(!aj[(2*n) - (a[i]%(2*n))].empty()){
				cout << a[i] << ',' << aj[(2*n) - (a[i]%(2*n))].front() << '\n';
				break;
			}
			if(!aj[a[i]%(2*n)].size() >= 2){
				cout << aj[a[i]%(2*n)].at(0) << ',' << aj[a[i]%(2*n)].at(1) << '\n';
				break;
			}
		}
		cout << "-1\n";
	}

	return 0;
}