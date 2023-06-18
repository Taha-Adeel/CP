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

// Lazy segment tree
class LazySegTree{
public:
	int n;
	vi t, lazy;
	LazySegTree(int n): n(n), t(4*n), lazy(4*n) {}
	void push(int v, int tl, int tr){
		if(lazy[v]){
			t[v] += lazy[v];
			if(tl != tr){
				lazy[2*v] += lazy[v];
				lazy[2*v+1] += lazy[v];
			}
			lazy[v] = 0;
		}
	}
	void update(int v, int tl, int tr, int l, int r, int addend){
		push(v, tl, tr);
		if(l > r) return;
		if(tl == l && tr == r){
			lazy[v] += addend;
			push(v, tl, tr);
		}
		else{
			int tm = (tl+tr)/2;
			update(2*v, tl, tm, l, min(r, tm), addend);
			update(2*v+1, tm+1, tr, max(l, tm+1), r, addend);
			t[v] = max(t[2*v], t[2*v+1]);
		}
	}
	int query(int v, int tl, int tr, int l, int r){
		push(v, tl, tr);
		if(l > r) return 0;
		if(tl == l && tr == r) return t[v];
		int tm = (tl+tr)/2;
		return max(query(2*v, tl, tm, l, min(r, tm)), query(2*v+1, tm+1, tr, max(l, tm+1), r));
	}
	void update(int l, int r, int addend){
		update(1, 0, n-1, l, r, addend);
	}
	int query(int l, int r){
		return query(1, 0, n-1, l, r);
	}
};

void solve(){
	
}

int main(){
	solve();
	cout << nl;
	
	return 0;
}