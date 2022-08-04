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
		int n, k;
		string s;
		cin >> n >> k >> s;
		
		int num_ones = 0;
		int left_most = -1;
		int right_most = n;
		FOR(i, n){
			if(s[i] == '1'){
				num_ones++;
				right_most = i;
				if(left_most == -1)
					left_most = i;
			}
		}
		if(num_ones > 0 && n - right_most - 1 <= k){
			s[right_most] = '0';
			s[n - 1] = '1';
			k -= n - right_most - 1;
			if(right_most == left_most)
				left_most = n - 1;
		}

		if(num_ones > 0 && left_most != n - 1 && left_most <= k){
			s[left_most] = 0;
			s[0] = '1';
		}
		int answer = 0;
		if(s[0] == '1'){
			answer += 10;
			num_ones--;	
		}
		if(s[n-1] == '1'){
			answer += 1;
			num_ones--;
		}
		answer += num_ones * 11;

		cout << answer << nl;
	}

	return 0;
}