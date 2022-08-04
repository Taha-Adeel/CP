#include <bits/stdc++.h>

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0)
template<class T> struct V: vector<T>{using vector<T>::vector;
	void sort_asc() {sort(this->begin(), this->end());}
	void sort_dsc() {sort(this->begin(), this->end(), greater<T>());}
	long long sum() {long long sum = 0; for(auto& i: *this) sum += i; return sum;}
	map<T, int> freqs() {map<T, int> freq; for(auto& i: *this) freq[i]++; return freq;}
	map<T, vector<int>> indices() {map<T, vector<int>> index; for(int i=0; i<this->size(); i++) index[this->at(i)].push_back(i); return index;}
	friend ostream& operator<<(ostream& out, const V<T>& v) {for(auto& i: v) out << i << ' '; return out;}
	friend istream& operator>>(istream& in, V<T>& v) {for(auto& i: v) in >> i; return in;}
};
void display(bool answer){cout << ((answer)?"Yes":"No");}
#define pY {cout << "Yes"; return;}
#define pN {cout << "No";  return;}

#define FOR(i, n)                for(int i = 0; i < n; ++i)
#define FOR1(i, n)               for(int i = 1; i < n; ++i)
#define FOR_RANGE(i, start, end) for(int i = start; i != end; i += (start<end) ? 1 : -1)
#define FOR_REV(i, n)            for(int i = n-1; i >= 0; --i)

#define F  first
#define S  second
#define pb push_back
constexpr char nl = '\n';
constexpr int MOD = 1000000007;
using ll  = long long int;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi  = V<int>;
using vll = V<ll>;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/

struct node{
	int Ai;
	int Ax;
	int Li, Ri;
	int parent;
	int height = 0;
	ll sum_of_children = 0;
	vi adj_list;
};

void dfs(int root, int parent, V<node>& V){
	V[root].parent = parent;

	ll max_deletion_gain = 0;
	for(auto& v: V[root].adj_list){
		if(v == parent)
			continue;
		V[v].height = V[root].height + 1;
		V[root].sum_of_children += V[v].Ai;
		dfs(v, root, V);
	}
	if(V[root].height % 2){
		V[root].Ax = (V[parent].Ai + V[root].sum_of_children)/V[root].adj_list.size();
		V[root].Ax = max(V[root].Ax, V[root].Li);
		V[root].Ax = min(V[root].Ax, V[root].Ri);
	}
}

void solve(){
	int N;
	cin >> N;
	V<node> V(N);
	FOR(i, N)
		cin >> V[i].Ai >> V[i].Li >> V[i].Ri;
	
	FOR(i, N-1){
		int u, v;
		cin >> u >> v;

		V[u-1].adj_list.push_back(v-1);
		V[v-1].adj_list.push_back(u-1);
	}
	
}

int main(){
	int T;
	cin >> T;
	FOR(t, T){
		solve();
		cout << nl;
	}
	
	return 0;
}