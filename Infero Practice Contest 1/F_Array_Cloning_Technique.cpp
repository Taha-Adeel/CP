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

		map<int, int> freq;
		int max_freq = 0;
		FOR(i, n){
			int temp;
			cin >> temp;

			freq[temp]++;
			if(freq[temp] > max_freq)
				max_freq = freq[temp];
		}
		int answer = 0;
		int size = max_freq;
		int spare_digits = 0;
		while(size < n){
			answer++;
			spare_digits += size;
			while(spare_digits>0 && size < n)<%
				spare_digits--;
				answer++;
				size++;
			}
		}
		cout << answer << nl;
	}

	return 0;
}