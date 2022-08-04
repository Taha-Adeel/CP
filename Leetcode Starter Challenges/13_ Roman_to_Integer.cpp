#include <bits/stdc++.h>

using namespace std;

#define FOR(a,c)   for (int (a)=0; (a)<(c); ++(a))
#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define nl '\n'
using ll = long long int;
using p_ii = pair<int,int>;
constexpr int MOD{1000000007};
constexpr ll INF{1000000000000000003};

class Solution {
public:
    int romanToInt(string s) {
       map<char, int> value;
        value['I'] = 1;
        value['V'] = 5;
        value['X'] = 10;
        value['L'] = 50;
        value['C'] = 100;
        value['D'] = 500;
        value['M'] = 1000;
        
        int s_value = 0;
        for(int i = 0; i < s.length(); i++){
            switch(s[i]){
				case 'I':
					if(i < s.length()-1 && (s[i+1] == 'V' || s[i+1] == 'X'))
						s_value -= value[s[i]];
					else
						s_value += value[s[i]];
					break;
				case 'X':
					if(i < s.length()-1 && (s[i+1] == 'L' || s[i+1] == 'C'))
						s_value -= value[s[i]];
					else
						s_value += value[s[i]];
					break;
				case 'C':
					if(i < s.length()-1 && (s[i+1] == 'D' || s[i+1] == 'M'))
						s_value -= value[s[i]];
					else
						s_value += value[s[i]];
					break;
				default:
					s_value += value[s[i]];
			}
        }

		return s_value;
    }
};

int main(){
	int T;
	cin >> T;
	while(T--){
		
	}

	return 0;
}