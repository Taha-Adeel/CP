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

int flip_bits(int num, int digits){
	int answer = 0;
	int bit_mask = 1;
	FOR(i, digits){
		if((bit_mask&num) == 0)
			answer |= bit_mask;
		bit_mask <<= 1;
	}
	return answer;
}

int num_of_bits(int num){
	int answer = 0;
	while(num > 0){
		answer++;
		num >>= 1;
	}

	return answer;
}

void solve(){
	int N;
	cin >> N;

	if(N == 1){
		cout << 1 << nl << 1 << nl;
		return;
	}
	if(N%2 == 1){
		cout << -1 << nl;
		return;
	}
	
	v_i A, B, used(N+1, 0);

	for(int i = N; i > 0; i--){
		if(used[i])
			continue;
		
		int num1 = i;
		int num2 = flip_bits(num1, num_of_bits(num1));

		A.push_back(num1); A.push_back(num2);
		B.push_back(num2); B.push_back(num1);
		used[num1]++; used[num2]++;
	}

	cout << A << nl;
	cout << B << nl;
}

int main(){
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	
	return 0;
}