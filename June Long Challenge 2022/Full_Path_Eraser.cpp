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
struct node{
	int value;
	v_i adj_list;

	ll gcd;
	ll gcd_sum;
	ll deletion_gain;// = gcd_sum + max_deletion_gain of children - gcd
};

void gcd_subtree(int root, int parent, v<node>& V){
	V[root].gcd = V[root].value;
	V[root].gcd_sum = 0;
	V[root].deletion_gain = 0;

	ll max_deletion_gain = 0;
	for(auto& v: V[root].adj_list){
		if(v == parent)
			continue;
		gcd_subtree(v, root, V);
		V[root].gcd = gcd(V[root].gcd, V[v].gcd);
		V[root].gcd_sum += V[v].gcd;
		max_deletion_gain = max(max_deletion_gain, V[v].deletion_gain);
	}
	V[root].deletion_gain = V[root].gcd_sum + max_deletion_gain - V[root].gcd;
}

void solve(){
	int N;
	cin >> N;
	v<node> V(N);
	FOR(i, N)
		cin >> V[i].value;
	FOR(i, N-1){
		int u, v;
		cin >> u >> v;

		V[u-1].adj_list.push_back(v-1);
		V[v-1].adj_list.push_back(u-1);
	}

	gcd_subtree(0, 0, V);
	
	cout << V[0].gcd + V[0].deletion_gain << nl;

	return;
}

int main(){
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	
	return 0;
}