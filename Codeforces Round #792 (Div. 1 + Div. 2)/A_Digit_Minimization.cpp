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
		string num;
		cin >> num;
		
		int answer;
		if(num.size() == 2){
			answer = num[1] - '0';
		}
		else{
			answer = num[0] - '0';
			for(auto digit: num){
				if(answer > digit - '0')
					answer = digit - '0';
			}
		}

		cout << answer << nl;
	}

	return 0;
}