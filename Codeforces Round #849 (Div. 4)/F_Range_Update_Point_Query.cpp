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

// Lazy segment tree to perform range sum updates and point queries
class LazySegmentTree{
private:
	int n;
	vector<ll> tree, lazy;
public:
	LazySegmentTree(int n){
		this->n = n;
		tree.resize(4*n, 0);
		lazy.resize(4*n, 0);
	}

	LazySegmentTree(vector<ll> a){
		n = a.size();
		tree.resize(4*n, 0);
		lazy.resize(4*n, 0);
		build(a, 0, n-1, 1);
	}

	void build(vector<ll> &a, int l, int r, int node){
		if(l == r){
			tree[node] = a[l];
			return;
		}
		int mid = (l+r)/2;
		build(a, l, mid, 2*node);
		build(a, mid+1, r, 2*node+1);
		tree[node] = tree[2*node] + tree[2*node+1];
	}

	void update(int l, int r, int val){
		update(l, r, val, 0, n-1, 1);
	}

	void update(int l, int r, int val, int start, int end, int node){
		if(lazy[node] != 0){
			tree[node] += (end-start+1)*lazy[node];
			if(start != end){
				lazy[2*node] += lazy[node];
				lazy[2*node+1] += lazy[node];
			}
			lazy[node] = 0;
		}
		if(start > end || start > r || end < l) return;
		if(start >= l && end <= r){
			tree[node] += (end-start+1)*val;
			if(start != end){
				lazy[2*node] += val;
				lazy[2*node+1] += val;
			}
			return;
		}
		int mid = (start+end)/2;
		update(l, r, val, start, mid, 2*node);
		update(l, r, val, mid+1, end, 2*node+1);
		tree[node] = tree[2*node] + tree[2*node+1];
	}

	ll query(int l, int r){
		return query(l, r, 0, n-1, 1);
	}

	ll query(int l, int r, int start, int end, int node){
		if(lazy[node] != 0){
			tree[node] += (end-start+1)*lazy[node];
			if(start != end){
				lazy[2*node] += lazy[node];
				lazy[2*node+1] += lazy[node];
			}
			lazy[node] = 0;
		}
		if(start > end || start > r || end < l) return 0;
		if(start >= l && end <= r) return tree[node];
		int mid = (start+end)/2;
		ll p1 = query(l, r, start, mid, 2*node);
		ll p2 = query(l, r, mid+1, end, 2*node+1);
		return p1+p2;
	}
};

int get_sum_of_digits(int x){
	int sum = 0;
	while(x){
		sum += x%10;
		x /= 10;
	}
	return sum;
}

void solve(){
	int n, q;
	cin >> n >> q;
	vi a(n);
	cin >> a;

	vll op_count(n, 0);
	LazySegmentTree tree(op_count);

	FOR(i, q){
		int t, l, r, x;
		cin >> t;
		if(t == 1){
			cin >> l >> r; l--; r--;
			tree.update(l, r, 1);
		}
		else{
			cin >> x; x--;
			int op_count_x = tree.query(x, x);

			int ans = a[x];
			FOR(i, min(op_count_x, 3))
				ans = get_sum_of_digits(ans);
			cout << ans << nl;
		}
	}
}

int main(){
	FAST;
	int T;
	cin >> T;
	FOR(t, T){
		solve();
	}
	
	return 0;
}