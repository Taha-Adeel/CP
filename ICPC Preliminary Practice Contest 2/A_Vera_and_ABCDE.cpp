#include <bits/stdc++.h>

using namespace std;

int main(){
	int N;
	string s;
	cin >> N;
	cin >> s;

	unordered_map<char, array<string,5>> map;

	map['A'] = {"***","*.*","***","*.*","*.*"};
	map['B'] = {"***","*.*","***","*.*","***"};
	map['C'] = {"***","*..","*..","*..","***"};
	map['D'] = {"***","*.*","*.*","*.*","***"};
	map['E'] = {"***","*..","***","*..","***"};

	for(int j=0; j<5; j++){
		for(int i=0; i<N; ++i){
			cout << (map[s[i]])[j];
		}
		cout << endl;
	}
	
	return 0;
}