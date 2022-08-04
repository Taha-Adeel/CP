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
		int n;
		cin >> n;
		vector<int> a(n);
		FOR(i, n)
			cin >> a[i];
		int a_max = *max_element(a.begin(), a.end());

		int m;
		cin >> m;
		vector<int> b(m);
		FOR(i, m)
			cin >> b[i];
		int b_max = *max_element(b.begin(), b.end());

		if(a_max > b_max)
			cout << "Alice" << nl << "Alice" << nl;
		else if(a_max < b_max)
			cout << "Bob" << nl << "Bob" << nl;
		else
			cout << "Alice" << nl << "Bob" << nl;

	}

	return 0;
}