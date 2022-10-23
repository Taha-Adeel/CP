#include <bits/stdc++.h>

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0)
template<class T> struct V: vector<T>{using vector<T>::vector;
	void sort()			{std::sort(this->begin(), this->end());}
	void sort_dsc() 	{std::sort(this->begin(), this->end(), greater<T>());}
	auto sum() 			{T sum = 0; for(auto& i: *this) sum += i; return sum;}
	auto freqs() 		{map<T, int> freq; for(auto& i: *this) freq[i]++; return freq;}
	auto indices()		{int n=this->size(); map<T, V<int>> ii; for(int i=0; i<n; i++) ii[(*this)[i]].push_back(i); return ii;}
	auto prefix_sums() 	{int n=this->size(); V<T> ps(n+1,0); for(int i=0; i<n; i++) ps[i+1] = ps[i]+(*this)[i]; return ps;}
	friend ostream& operator<<(ostream& out, const V<T>& v) {for(auto& i: v){out << i << ' ';} return out;}
	friend istream& operator>>(istream& in, V<T>& v) {for(auto& i: v){in >> i;} return in;}
};
#define pY {cout << "YES"; return;}
#define pN {cout << "NO";  return;}

#define FOR(i, n)                for(int i = 0; i < (int)n; ++i)
#define FOR1(i, n)               for(int i = 1; i <= (int)n; ++i)
#define FOR_RANGE(i, start, end) for(int i = start; i != end; i += (start<end) ? 1 : -1)
#define FOR_REV(i, n)            for(int i = (int)n-1; i >= 0; --i)
#define all(v)                   v.begin(), v.end()

#define F  first
#define S  second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
constexpr char nl = '\n';
constexpr int MOD = 1000000007;
using ll  = long long int;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi  = V<int>;
using vll = V<ll>;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/

struct Node{
	int parent = -1;
	vi adj_list;
	int ci;
	int good_kids = 0;
};

void dfs(int root, V<Node>& tree){
	for(auto& child: tree[root].adj_list){
		dfs(child, tree);
		tree[root].good_kids += (tree[child].ci != 1);
	}
}

void solve(){
	int n;
	cin >> n;
	V<Node> tree(n);
	FOR(i, n){
		int p, c;
		cin >> p >> c;

		if(p != -1){
			p--;
			tree[i].parent = p;
			tree[i].ci = c;
			tree[p].adj_list.pb(i);
		}
	}

	FOR(i, n)
		if(tree[i].parent == -1)
			dfs(i, tree);

	vi ans;
	FOR(i, n)
		if(tree[i].parent != -1 && tree[i].ci && tree[i].good_kids == 0)
			ans.pb(i+1);
	
	if(ans.size()) cout << ans;
	else cout << -1;
}

int main(){
	solve();
	cout << nl;
	
	return 0;
}