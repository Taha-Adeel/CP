#include <bits/stdc++.h>

using namespace std;

#define FOR(a,c)   for (int (a)=0; (a)<(c); ++(a))
#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define nl '\n'
using ll = long long int;

ll get_sqrt(ll n){
	for(int i = 1; i <= sqrt(n) + 1; i++){
		if(i * i == n)
			return i;
	}
	return -1;
}

int main(){
	int T;
	cin >> T;
	FOR(t, T){
		int N, X, Y;
		cin >> N >> X >> Y;


		int total_sum = (N * (N + 1))/2;
		if((X * total_sum)%(X + Y) == 0){
			ll S_x =  (X * total_sum)/(X + Y);

			int i = 1, j = N+1;
			while(i <= N){
				ll det = 1 + 4 * (2 * S_x + i * i - i);
				if(get_sqrt(det) != -1){
					if((-1 + get_sqrt(det))%2 == 0){
						j = (-1 + get_sqrt(det))/2;
						break;
					}
				}
				i++;
			}
			if(i > N || j > N)
				cout << "Case #" << t + 1 << ": IMPOSSIBLE" << nl;
			else{
				cout << "Case #" << t + 1 << ": POSSIBLE" << nl;
				cout << j - i + 1 << nl;
				for(int n = i; n <= j; n++)
					cout << n << ' ';
				cout << nl;
			}
		}
		else
			cout << "Case #" << t + 1 << ": IMPOSSIBLE" << nl;
	}

	return 0;
}