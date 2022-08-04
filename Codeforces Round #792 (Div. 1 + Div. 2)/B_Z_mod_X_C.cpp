#include <bits/stdc++.h>

using namespace std;

#define FOR(a,c)   for (int (a)=0; (a)<(c); ++(a))
#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define nl '\n'
using ll = long long int;
using p_ii = pair<int,int>;
constexpr int MOD{1000000007};
constexpr ll INF{1000000000000000003};

int main(){
	int T;
	cin >> T;
	while(T--){
		int a, b, c;
		cin >> a >> b >> c;

		ll x = a + b, y = b;
		ll z = x + c;

		while(z%x != c){
			x += b;
			z = x + c;
		}

		cout << x << ' ' << y << ' ' << z << nl;
	}

	return 0;
}