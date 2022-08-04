#include <bits/stdc++.h>

using namespace std;

#define nl '\n'
using ll = long long int;
constexpr int MOD{1000000007};

ll power(ll x, ll y){
	if (y == 0)
		return 1;
	ll p = power(x, y/2) % MOD;
	p = (p * p) % MOD;

	return (y % 2 == 0) ? p : (x * p) % MOD;
}

ll mod_div(ll a, ll b){
	a = a % MOD;
	ll inv = power(b, MOD - 2); // From fermats little theorem

	return (a * inv) % MOD;
}

int main(){
	int T;
	cin >> T;
	while(T--){
		int N, L, R;
		cin >> N >> L >> R;
		vector<ll> pascals_triangle_row(N+1);
		vector<ll> num_stones(2*N, 0);

		pascals_triangle_row[0] = 1;
		for(int r = 1; r <= N; r++){
			pascals_triangle_row[r] = (pascals_triangle_row[r-1] * (N - r + 1)) % MOD;
			pascals_triangle_row[r] = mod_div(pascals_triangle_row[r], r);
		}
		for(int i = 0; i <= N; ++i){
			num_stones[2*i] = pascals_triangle_row[i];
		}
		for(int i = L; i <= R; i++){
			cout << num_stones[N+i] << ' ';
		}
		cout << nl;
	}

	return 0;
}