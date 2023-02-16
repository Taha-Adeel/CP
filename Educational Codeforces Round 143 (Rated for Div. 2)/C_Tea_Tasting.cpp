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

// Lazy segment tree to perform range sum updates and queries
class LazySegmentTree{
private:
	int n;
	vector<ll> tree, lazy;

	void build(const vector<ll>& a, int v, int tl, int tr){
		if(tl == tr){
			tree[v] = a[tl];
		}
		else{
			int tm = (tl + tr) / 2;
			build(a, v*2, tl, tm);
			build(a, v*2+1, tm+1, tr);
			tree[v] = tree[v*2] + tree[v*2+1];
		}
	}

	void push(int v, int tl, int tr){
		if(lazy[v] != 0){
			tree[v] += lazy[v] * (tr - tl + 1);
			if(tl != tr){
				lazy[v*2] += lazy[v];
				lazy[v*2+1] += lazy[v];
			}
			lazy[v] = 0;
		}
	}

	void update(int v, int tl, int tr, int l, int r, ll val){
		push(v, tl, tr);
		if(l > r) return;
		if(l == tl && r == tr){
			lazy[v] += val;
			push(v, tl, tr);
		}
		else{
			int tm = (tl + tr) / 2;
			update(v*2, tl, tm, l, min(r, tm), val);
			update(v*2+1, tm+1, tr, max(l, tm+1), r, val);
			tree[v] = tree[v*2] + tree[v*2+1];
		}
	}

	ll query(int v, int tl, int tr, int l, int r){
		push(v, tl, tr);
		if(l > r) return 0;
		if(l == tl && r == tr) return tree[v];
		int tm = (tl + tr) / 2;
		return query(v*2, tl, tm, l, min(r, tm)) + query(v*2+1, tm+1, tr, max(l, tm+1), r);
	}

public:
	LazySegmentTree(const vector<ll>& a){
		n = a.size();
		tree.resize(4*n);
		lazy.resize(4*n);
		build(a, 1, 0, n-1);
	}

	void update(int l, int r, ll val){
		update(1, 0, n-1, l, r, val);
	}

	ll query(int l, int r){
		return query(1, 0, n-1, l, r);
	}
};

void solve(){
	int n;
	cin >> n;
	vll a(n), b(n);
	cin >> a >> b;

	vll ps_b = b.prefix_sums(), ans(n, 0);
	LazySegmentTree drinks(vll(n, 0));

	FOR(i, n){
		int l = i, r = n-1;
		// Perform binary search to find greatest index j such that ps_b[j+1] - ps_b[i] <= a[i]
		while(l < r){
			int m = (l + r + 1) / 2;
			if(ps_b[m+1] - ps_b[i] <= a[i]) l = m;
			else r = m-1;
		}
		if(l == i && b[i] > a[i]){
			ans[i] += a[i];
			continue;
		}
		drinks.update(i, l, 1);
		if(l+1 < n) ans[l+1] += a[i] - (ps_b[l+1] - ps_b[i]);
	}

	FOR(i, n)
		ans[i] += drinks.query(i, i) * b[i];
	cout << ans;
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