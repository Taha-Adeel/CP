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
	vector<int> P(4);
	FOR(i, 4)
		cin >> P[i];

	int answer = 0;
	for(auto p: P){
		if(p >=10)
			answer++;
	}

	cout << answer << endl;

	return 0;
}