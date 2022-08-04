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
		ll n, k;
		cin >> n >> k;

		vector<ll> a(n);
		FOR(i, n)
			cin >> a[i];
			
		if(k <= n){
			ll cur_sum = 0;
			FOR(i, k)
				cur_sum += a[i];
			ll max_sum = cur_sum;
			for(int i = 0; i + k < n; i++){
				cur_sum = cur_sum - a[i] + a[i + k];
				if(cur_sum > max_sum)
					max_sum = cur_sum;
			}
			cout << max_sum + (k*(k-1))/2 << nl;
		}
		else{
			ll answer = 0;
			FOR(i, n){
				answer += a[i];
			}
			answer += (k - (n - 1) - 1);
			answer += (n - 1) * (k - n);
			answer += (n * (n - 1))/2;

			cout << answer << nl;
		}
	}

	return 0;
}