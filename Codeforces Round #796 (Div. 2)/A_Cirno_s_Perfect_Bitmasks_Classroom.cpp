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
		int x;
		cin >> x;
		int y = 1; 
		while((y&x) == 0)
			y <<= 1;

		if((y ^ x) > 0)
			cout << y << nl;
		else if(y != 1)
			cout << (y | 1) << nl;
		else if (y == 1){
			cout << 3 << nl;
		}
	}

	return 0;
}