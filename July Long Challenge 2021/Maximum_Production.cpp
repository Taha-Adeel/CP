#include <bits/stdc++.h>

using namespace std;

int main(){
	int T;
	cin >> T;
	while(T--){
		int d, x, y, z;
		cin >> d >> x >> y >> z;
		cout << max(7*x, d*y + (7-d)*z) << endl;
	}
	
	return 0;
}