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
		ll N, M, A, B, P, S;
		cin >> N >> M >> A >> B >> P >> S;

		ll x = 0, y = 0;

		N += 2 * P;
		M += 2 * P;

		if(N >= A && M >= B){
			x = (N - A)/S + 1;
			y = (M - B)/S + 1;
		}

		cout << x << ' ' << y << nl;
	}

	return 0;
}