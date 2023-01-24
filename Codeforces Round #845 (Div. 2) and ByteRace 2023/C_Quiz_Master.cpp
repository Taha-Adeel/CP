#include <bits/stdc++.h>

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0)
template<class T> struct V: vector<T>{using vector<T>::vector;
	auto sort()			{std::sort(this->begin(), this->end()); return *this;}
	auto sort_dsc() 	{std::sort(this->begin(), this->end(), greater<T>());}
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

vi get_divisors(int n){
    vi divisors;
    for(int i = 1; i*i < n; i++)
        if(n%i == 0) 
            divisors.push_back(i),
            divisors.push_back(n/i);
    if(floor(sqrt(n)) == ceil(sqrt(n)))
        divisors.push_back(sqrt(n));
    
    return divisors.sort();
}
 
bool can_delete(map<int, int>& div_freqs, vi& divs, int m){
    bool ans = true;
    for(auto& d: divs) if(d <= m)
        ans &= (div_freqs[d] > 1);
    return ans;
}
 
void solve(){
    int n, m;
    cin >> n >> m;
    vi a(n);
    cin >> a;
    
    a.sort();
    map<int, int> div_freqs;
	V<vi> divs(n);
    int ans = INT_MAX;
    int l = 0, r = 0;
    while(r < n){
		divs[r] = get_divisors(a[r]);
        for(auto& d: divs[r]) if(d <= m)
            div_freqs[d]++;
        while(can_delete(div_freqs, divs[l], m)){
            for(auto& d: divs[l]) if(d <= m)
                div_freqs[d]--;
            l++;
        }
        if(div_freqs.size() == m)
            ans = min(ans, a[r] - a[l]);
        r++;
    }

    if(ans == INT_MAX) cout << -1;
    else cout << ans;
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