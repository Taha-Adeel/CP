#include <bits/stdc++.h>

using namespace std;

#define FOR(a,c)   for (int (a)=0; (a)<(c); ++(a))
#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define nl '\n'
using ll = long long int;

int main(){
	int T;
	cin >> T;
	while(T--){
		int l, r, k;
		cin >> l >> r >> k;

		int total = r - l + 1;
		int even = total/2 + ((l%2==0 && r%2==0) ? 1 : 0);
		int odd = total - even;
		if(odd <= k || (even == 0 && l != 1)) 
			cout << "YES" << nl;
		else
			cout << "NO" << nl;
	}

	return 0;
}