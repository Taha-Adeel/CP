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

int query(int l, int r){
	cout << 1 << ' ' << l+1 << ' ' << r+1 << endl;
	int sum; cin >> sum;
	return sum;
}

bool ans(int l, int r){
	cout << 2 << ' ' << l+1 << ' ' << r+1 << endl;
	cin >> l;
	return l == 1;
}

void solve(){
	int n, k;
	cin >> n >> k;

	int total = query(0, n-1);
	int l = 0, r = n-1;
	while(l < r){
		int m = (l+r)/2;
		if(query(0, m) < 2*(m+1)) r = m;
		else l = m+1;
	}
	if(k%2 == 0 && k <= 2*l) ans(0, (k/2)-1);
	else if(k%2 == 1 && k <= 2*l+1) ans(l - k/2, l);
	else if(k <= total - 2*l){
		int l2 = l, r2 = n-1, sum;
		while(l2 < r2){
			int m = (l2+r2)/2;
			sum = query(l, m);
			if(sum < k) l2 = m+1;
			else r2 = m;
		}
		if(sum > k) ans(l+1, l2);
		else ans(l, l2);
	}
	else if((k - (total-2*l)) % 2 == 0)
		ans(l - (k - (total-2*l))/2, n-1); 
	else{
		int last_one;
		int l2 = l, r2 = n-1, sum;
		while(l2 < r2){
			int m = (l2+r2)/2;
			sum = query(m, n-1);
			if(sum < 2*(n-m)) l2 = m;
			else r2 = m-1;
		}
		int sum_between = query(l, l2);
		if((k - sum_between) % 2 == 0) ans(l - (k - sum_between)/2, l2);
		else ans(l - (k - sum_between)/2, l2-1);
	}
}

int main(){
	int T;
	cin >> T;
	FOR(t, T){
		solve();
	}
	
	return 0;
}