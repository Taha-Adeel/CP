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
#define pN {cout << "IMPOSSIBLE";  return;}

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
	int set_size = 1;
};

void solve(){
	int n, m;
	cin >> n >> m;
	V<Node> graph(n);
	int connected_components = n, largest_size = 1;
	auto ds = [&](int a){
		while(graph[a].parent != -1)
			a = graph[a].parent;
		return a;
	};
	auto merge = [&](int a, int b){
		int ds_a = ds(a), ds_b = ds(b);
		if(graph[ds_a].set_size < graph[ds_b].set_size) swap(a, b), swap(ds_a, ds_b);

		graph[ds_b].parent = ds_a;
		graph[ds_a].set_size += graph[ds_b].set_size;
		largest_size = max(largest_size, graph[ds_a].set_size);
	};

	FOR(i, m){
		int a, b;
		cin >> a >> b; a--, b--;

		if(ds(a) != ds(b)){
			merge(a, b);
			connected_components--;
		}
		cout << connected_components << ' ' << largest_size << nl;
	}
}

int main(){
	solve();
	
	return 0;
}