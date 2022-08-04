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
		vector<int> lakes = {6, 2, 10, 8, 6};

		vector<int> suffix_sums(lakes.size());
		suffix_sums[lakes.size()-1] = 0;
		for(int i = lakes.size() - 2; i >= 0; ++i){
			suffix_sums[i] = suffix_sums[i + 1] + lakes[i];
		}

		int min_operations = 0;
		for(int i = 0; i < lakes.size(); ++i){
			if(lakes[i] > suffix_sums[i]){
				if(i == lakes.size()-1){

				}
				else if( i == lakes.size() - 2){
					if(lakes.size() == 2){
						min_operations += 1;
						// return;
					}
					else{
						lakes[i - 1] += lakes[i] + lakes[i + 1];
						min_operations += 2;
						lakes.erase(lakes.end());
						lakes.erase(lakes.end());
						suffix_sums[lakes.size()-1] = 0;
						for(int i = lakes.size() - 2; i >= 0; ++i){
							suffix_sums[i] = suffix_sums[i + 1] + lakes[i];
						}
					}
				}
				else{
					lakes[i] += suffix_sums[i];
				}
			}
		}
	}

	return 0;
}