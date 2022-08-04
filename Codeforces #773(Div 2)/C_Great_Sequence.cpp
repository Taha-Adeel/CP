#include <bits/stdc++.h>

using namespace std;

#define FOR(a,c)   for (int (a)=0; (a)<(c); ++(a))
#define FAST ios::sync_with_stdio(0); cin.tie(0);
using ll = long long int;

int main(){
	int T;
	cin >> T;
	while(T--){
		int n, x;
		cin >> n >> x;
		map<ll, int> freq;
		FOR(i, n){
			int a_i;
			cin >> a_i;
			freq[a_i]++;
		}
		int answer = 0;
		for(auto& a: freq){
			while(a.second != 0){
				a.second--;
				if(freq.find(a.first * x) != freq.end() && freq[a.first * x] != 0)
					freq[a.first * x]--;
				else
					answer++;
			}
		}
		cout << answer<< '\n';
	}

	return 0;
}