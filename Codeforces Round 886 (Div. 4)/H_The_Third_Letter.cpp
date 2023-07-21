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

struct Node{
	V<pll> adj_list;
	ll dist_from_root = -1;
};

void solve(){
	ll n, m; cin >> n >> m;
	V<Node> nodes(n);
	vll a(m), b(m), d(m); 
	FOR(i, m){
		cin >> a[i] >> b[i] >> d[i];
		a[i]--, b[i]--;
		nodes[a[i]].adj_list.pb({b[i], d[i]});
		nodes[b[i]].adj_list.pb({a[i], -d[i]});
	}

	queue<ll> q;
	FOR(i, n) if(nodes[i].dist_from_root == -1){
		nodes[i].dist_from_root = 0;
		q.push(i);
		while(!q.empty()){
			ll cur = q.front(); q.pop();
			for(auto& [nei, dist]: nodes[cur].adj_list){
				if(nodes[nei].dist_from_root == -1){
					nodes[nei].dist_from_root = nodes[cur].dist_from_root + dist;
					q.push(nei);
				}
				else{
					if(nodes[nei].dist_from_root != nodes[cur].dist_from_root + dist){
						cout << "NO";
						return;
					}
				}
			}
		}
	}

	cout << "YES";
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