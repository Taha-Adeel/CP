#include <bits/stdc++.h>

using namespace std;

#define FOR(a,c)   for (int (a)=0; (a)<(c); ++(a))
#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define nl '\n';
using ll = long long int;

int main(){
	int T;
	cin >> T;
	while(T--){
		ll n, B, x, y;
		cin >> n >> B >> x >> y;

		ll ai = 0, sum = 0;

		FOR(i, n){
			ai = (ai + x <= B) ? ai + x : ai - y;
			sum += ai;
		}

		cout << sum << nl;
	}

	return 0;
}