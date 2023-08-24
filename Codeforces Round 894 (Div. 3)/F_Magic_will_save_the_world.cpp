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

void solve(){
	ll w, f; cin >> w >> f;
	ll n; cin >> n;
	vll a(n); cin >> a;

	a.sort();
	ll sum = a.sum();

	// Create an array to store results of subproblems
    bool dp[n + 1][sum + 1];

	// Initialize first column as true. 0 sum is possible with all elements.
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

	// Initialize top row, except dp[0][0], as false. With 0 elements, no other sum expect 0 is possible
	for (int i = 1; i <= sum; i++)
        dp[0][i] = false;

	// Fill the partition table in bottom up manner
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            // If i'th element is excluded
            dp[i][j] = dp[i - 1][j];
 
            // If i'th element is included
            if (a[i - 1] <= j)
                dp[i][j] |= dp[i - 1][j - a[i - 1]];
        }
    }

	if(w < f) swap(w, f);
	ll l = sum/(f+w), r = sum/max(f, w) + 1;
	while(l < r){
		ll t = (l+r)/2;

		ll w_magic = w*t, f_magic = f*t;
		bool can_partition = false;

		if(w_magic >= sum) can_partition = true;
		else{
			while(w_magic >= 0){
				if(dp[n][w_magic]) break;
				w_magic--;
			}
			if(sum - w_magic <= f_magic) can_partition = true;
		} 

		if(can_partition) r = t;
		else l = t+1;
	}

	cout << l;
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