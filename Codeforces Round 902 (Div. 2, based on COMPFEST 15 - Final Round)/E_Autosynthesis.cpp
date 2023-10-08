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
#define display(x) if(x) pY else pN

#define FOR(i, n)                for(int i = 0; i < (int)n; ++i)
#define FOR1(i, n)               for(int i = 1; i <= (int)n; ++i)
#define ROF(i, n)            for(int i = (int)n-1; i >= 0; --i)
#define all(v)                   v.begin(), v.end()
#define rall(v)                  v.rbegin(), v.rend()

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
	int child_cnt = 0;
	int color = -1;
};

void solve(){
	int n; cin >> n;
	vi a(n); cin >> a;

	V<Node> graph(n);
	FOR(i, n){
		graph[i].parent = a[i]-1;
		graph[a[i]-1].child_cnt++;
	}

	queue<int> q;
	FOR(i, n) if(graph[i].child_cnt == 0)
		q.push(i);

	while(!q.empty()){
		int u = q.front(); q.pop();
		graph[u].color = 0;
		int v = graph[u].parent;
		if(graph[v].color == 0) {cout << -1; return;}
		if(graph[v].color == -1){
			graph[v].color = 1;
			int w = graph[v].parent;
			if(graph[w].color == -1){
				graph[w].child_cnt--;
				if(graph[w].child_cnt == 0)
					q.push(w);
			}
		}
	}

	// Only cycles left;
	FOR(i, n){
		if(graph[i].color == -1){
			int u = i, c = 0;
			while(graph[u].color == -1)
				graph[u].color = c, 
				u = graph[u].parent, 
				c ^= 1;
			if(c == 1) {cout << -1; return;}
		}
	}

	vi ans;
	FOR(i, n) if(graph[i].color == 0) 
		ans.pb(a[i]);

	cout << ans.size() << nl;
	cout << ans;
}

int main(){
	FAST;
	solve();
	cout << nl;
	
	return 0;
}