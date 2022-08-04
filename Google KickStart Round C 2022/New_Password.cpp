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
	FOR(i, T){
		int N;
		cin >> N;

		string old_password;
		cin >> old_password;

		bool e = false, E = false, d = false, s = false, len = false;

		FOR(i, N){
			if(old_password[i] >= 'a' && old_password[i] <= 'z')
				e = true;
			else if(old_password[i] >= 'A' && old_password[i] <= 'Z')
				E = true;
			else if(old_password[i] >= '0' && old_password[i] <= '9')
				d = true;
			else if(old_password[i] == '#' || old_password[i] == '@' || old_password[i] == '*' || old_password[i] == '&')
				s = true;
		}
		string new_password = old_password;
		if(!e)
			new_password += "a";
		if(!E)
			new_password += "A";
		if(!d)
			new_password += "0";
		if(!s)
			new_password += "#";
		while(new_password.length() < 7)
			new_password += '0';

		cout << "Case #" << i + 1 << ": " << new_password << nl;
	}

	return 0;
}