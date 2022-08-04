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
	ll n, x;
	cin >> n >> x;

	string x_s = to_string(x);
	int count = 0;
	while(count < 50 && x_s.size() < n){
		int max_digit = *max_element(x_s.begin(), x_s.end()) - '0';
		x *= max_digit;
		x_s = to_string(x);
		count++;
	}
	if(x_s.size() == n){
		if(count < 9)
		cout << count << nl;
	}
	else
		cout << -1 << nl;

	return 0;
}