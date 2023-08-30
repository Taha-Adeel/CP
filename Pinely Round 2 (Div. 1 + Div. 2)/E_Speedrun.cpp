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
	friend ostream& operator<<(ostream& out, const V<T>& v) {for(auto& i: v) out << i << ' '; return out;}
	friend istream& operator>>(istream& in, V<T>& v) {for(auto& i: v) in >> i; return in;}
};
#define pY {cout << "YES"; return;}
#define pN {cout << "NO";  return;}
#define display(x) if(x) pY else pN

#define FOR(i, n)                for(int i = 0; i < (int)n; ++i)
#define FOR1(i, n)               for(int i = 1; i <= (int)n; ++i)
#define ROF(i, n)                for(int i = (int)n-1; i >= 0; --i)
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

struct Quests{
	pll time = {0, -1}; // {day, hour}
	int pre_reqs_done_cnt = 0;
	vi adj_list;
	vi pre_reqs;
};

void dfs(int root, V<Quests>& graph){
	if(graph[root].pre_reqs_done_cnt < graph[root].pre_reqs.size()) return;

	pll max_pre_req_time = {0, -1};
	for(auto& pre_req: graph[root].pre_reqs)
		max_pre_req_time = max(max_pre_req_time, graph[pre_req].time);
	
	if(graph[root].time.S >= max_pre_req_time.S) graph[root].time.F = max_pre_req_time.F;
	else graph[root].time.F = max_pre_req_time.F + 1;

	for(auto& adj: graph[root].adj_list){
		graph[adj].pre_reqs_done_cnt++;
		dfs(adj, graph);
	}
}

void solve(){
	int n, m, k; cin >> n >> m >> k;
	V<Quests> graph(n); FOR(i, n) cin >> graph[i].time.S;
	FOR(i, m){
		int a, b; cin >> a >> b; a--, b--;
		graph[a].adj_list.pb(b);
		graph[b].pre_reqs.pb(a);
	}

	for(auto& quest: graph){
		if(quest.pre_reqs.empty()){
			dfs(&quest - &graph[0], graph);
		}
	}

	pll max_time = {-1, -1}, min_time = {INT_MAX, INT_MAX};
	FOR(i, n)
		max_time = max(max_time, graph[i].time),
		min_time = min(min_time, graph[i].time);
	cout << max_time.F * k + max_time.S - min_time.F * k - min_time.S;
}

int main(){
	FAST;
	int T;
	cin >> T;
	FOR(t, T){
		solve();
		cout << nl;
	}
	
	return 0;
}