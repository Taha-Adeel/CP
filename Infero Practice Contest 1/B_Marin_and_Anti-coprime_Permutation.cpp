#include <bits/stdc++.h>

using namespace std;

#define FOR(a,c)   for (int (a)=0; (a)<(c); ++(a))
#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define nl '\n';
using ll = long long int;
using p_ii = pair<int,int>;
constexpr int MOD{998244353};
constexpr ll INF{1000000000000000003};

ll factorial(ll n){
	ll answer = 1;
	for(ll i=1; i<=n; ++i){
		answer = (answer * i) % MOD;
	}
	return answer;
}

int main(){
	int T;
	cin >> T;
	while(T--){
		ll n;
		cin >> n;

		if(n%2 == 0){
			ll perms = factorial(n/2);
			cout << (perms * perms) % MOD << nl;
		}
		else
			cout << 0 << nl;
	}

	return 0;
}