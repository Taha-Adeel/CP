#include <bits/stdc++.h>

using namespace std;

#define FAST 		ios::sync_with_stdio(0); cin.tie(0)
#define FOR(a,c) 	for (int a=0; a<c; ++a)
template<class T> struct v: vector<T>{using vector<T>::vector;
	void sort_asc() {sort(this->begin(), this->end());}
	void sort_dsc() {sort(this->begin(), this->end(), greater<T>());}
	friend ostream& operator << (ostream &outFunc, const v<T> &_v) {for(auto& i: _v) outFunc << i << ' '; return outFunc;}
	friend istream& operator >> (istream &inFunc, v<T> &_v) {for(auto& i: _v) inFunc >> i; return inFunc;}
};

#define f 	first
#define s 	second
constexpr char nl = '\n';
constexpr int MOD = 1000000007;
using ll   = long long int;
using p_ii = pair<int,int>;
using p_ll = pair<ll,ll>;
using v_i  = v<int>;
using v_ll  = v<ll>;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/

void solve(){
	int N;
	cin >> N;
	
	int answer = 0;
	int a, b;
	map<int, int> used;
	for(int i = 1; i * i <= N; i++){
		a = i;
		if(N%a == 0){
			b = N - a;
			if(b < a)
				swap(a, b);
			if(b%a == 0 && used[a]==0){
				used[a]++;
				if(a != b)
					answer += 2;
				else
					answer++; 
			}

			a = N/i;
			b = N - a;
			if(b < a)
				swap(a, b);
			if(a == 0)
				continue;
			if(b%a == 0 && used[a]==0){
				used[a]++;
				if(a != b)
					answer += 2;
				else
					answer++; 
			}
		}
	}

	cout << answer << nl;
}

int main(){
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	
	return 0;
}