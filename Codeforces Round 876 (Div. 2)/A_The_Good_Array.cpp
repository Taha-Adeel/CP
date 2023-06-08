#include <bits/stdc++.h>

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0)

using ll  = long long int;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/

void solve(){
	int n,k; cin >> n >> k;
	vector<int> a(n, 0);
	a[0] = 1; a[n-1] = 1;
	for(int i = 2; i <= n; i++){
		if(i % k == 1){
			a[i-1] = 1;
		}
	}
	int cnt = 0;
	for(int i = n; i > 0; i--){
		cnt += a[i-1];
		if((n-i+1) % k == 0){
			if(cnt < (n-i+1+k-1)/k){
				a[i-1] = 1;
				cnt++;
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		ans += a[i];
	}
	cout << ans;
}

int main(){
	FAST;
	int T;
	cin >> T;
	for(int i = 0; i < T; i++){
		solve();
		cout << '\n';
	}
	
	return 0;
}