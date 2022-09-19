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
#define pN {cout << "-1";  return;}

#define FOR(i, n)                for(int i = 0; i < (int)n; ++i)
#define FOR1(i, n)               for(int i = 1; i < (int)n; ++i)
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

void solve(){
	int n, x, y;
	cin >> n >> x >> y;

	if(x == y) pN
	int a = (n-1-n*y)/(x-y), b = n-a;
	if((n-1-n*y)%(x-y) || (a < 0 || b < 0)) pN
	set<int> nums;
	FOR1(i, n) nums.insert(i+1);

	int cur_num = 1, cur_wins = 0; 
	FOR(i, n-1){
		if(i <= a*x){
			if(cur_wins < x){
				cout << cur_num << ' ';
				cur_wins++;
				nums.erase(nums.begin());
			}
			else{
				cur_wins = 1;
				cur_num = *nums.begin();
				cout << cur_num << ' ';
				nums.erase(nums.begin());
			}
		}
		else{
			if(cur_wins < y){
				cout << cur_num << ' ';
				cur_wins++;
				nums.erase(nums.begin());
			}
			else{
				cur_wins = 1;
				cur_num = *nums.begin();
				cout << cur_num << ' ';
				nums.erase(nums.begin());
			}
		}
	}
	// cout << a << ' ' << b;
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