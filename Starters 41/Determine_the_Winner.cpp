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
		int Pa, Pb, Qa, Qb;
		cin >> Pa >> Pb >> Qa >> Qb;

		int P = max(Pa, Pb);
		int Q = max(Qa, Qb);

		if(P < Q)
			cout << 'P' << nl;
		else if(P > Q)
			cout << 'Q' << nl;
		else
			cout << "TIE" << nl;
	}

	return 0;
}