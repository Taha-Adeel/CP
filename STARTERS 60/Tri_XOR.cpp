#include <bits/stdc++.h>

using namespace std;
#define int long long

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
using ll  = int;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi  = V<int>;
using vll = V<ll>;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/


void solve(){
	int n;
	cin >> n;
	vll a(n);
	cin >> a;

	V<vi> ans;
	for(ll mask = 1; mask <= INT_MAX; mask <<= 1){
		vi nums;
		FOR(i, n)
			if(a[i] & mask) nums.pb(i);
		
		for(int i = 0; i + 2 < nums.size(); i+= 3){
			int x = a[nums[i]], y = a[nums[i+1]], z = a[nums[i+2]];
			ans.pb({x, y, z});
			a[nums[i]] = x^y; a[nums[i+1]] = y^z; a[nums[i+2]] = z^x;
		}
		if(nums.size()%3 == 1){
			int xi = nums.back();
			int yi = 0; while(yi == xi) yi++;
			int zi = 0; while(zi == xi || zi == yi) zi++;
			int x = a[xi], y = a[yi], z = a[zi];
			ans.pb({x, y, z});
			a[xi] = x^y; a[yi] = y^z; a[zi] = z^x;

			int yii = 0, zii = yi; while(yii == nums.back() || yii == zi || yii == zii) yii++;
			x = a[xi], y = a[yii], z = a[zii];
			ans.pb({x, y, z});
			a[xi] = x^y; a[yii] = y^z; a[zii] = z^x;

			x = a[xi], y = a[yi], z = a[zi];
			ans.pb({x, y, z});
			a[xi] = x^y; a[yi] = y^z; a[zi] = z^x;
		}
		else if(nums.size()%3 == 2){
			int xi = nums.back();
			int yi = 0; while(yi == xi || yi == nums[nums.size()-2]) yi++;
			int zi = 0; while(zi == xi || zi == nums[nums.size()-2] || zi == yi) zi++;
			int x = a[xi], y = a[yi], z = a[zi];
			ans.pb({x, y, z});
			a[xi] = x^y; a[yi] = y^z; a[zi] = z^x;

			yi = nums[nums.size()-2];
			x = a[xi], y = a[yi], z = a[zi];
			ans.pb({x, y, z});
			a[xi] = x^y; a[yi] = y^z; a[zi] = z^x;
		}
	}

	cout << ans.size() << nl;
	for(auto& move: ans)
		cout << move << nl;
}

signed main(){
	FAST;
	int T;
	cin >> T;
	FOR(t, T){
		solve();
	}
	
	return 0;
}