#include <iostream>
using namespace std;

#define nl '\n'
#define FOR(i, n)                for(int i = 0; i < (int)n; ++i)

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    
    string ans = s;
    int i = 0;
    for(; i < n - 2; i++){
        if(s[i] == '1') {i++; break;}
    	if(i == n-3){cout << ans; return;}
    }
    for(;i < n; i++){
        ans[i] = '0';
    }
    
    cout << ans;
}

int main() {
	// your code goes here
	int t;
	cin >> t;
	// while(t--){
	//     solve();
	//     cout << nl;
	// }
	cout << t << nl;
	FOR(i, t){
		cout << i + 1 << nl;
	}
	return 0;
}
