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

void makeCombiUtil(V<vi>& ans, vi& tmp, int n, int left, int k){
    if (k == 0) {
        ans.push_back(tmp);
        return;
    }
 
    for (int i = left; i <= n; ++i){
        tmp.push_back(i-1);
        makeCombiUtil(ans, tmp, n, i + 1, k - 1);
        tmp.pop_back();
    }
}

auto makeCombi(int n, int k){
    V<vi> ans;
    vi tmp;
	if(k > n) return ans;
    makeCombiUtil(ans, tmp, n, 1, k);
    return ans;
}

ll get_no_common_substrings(const string& a, const string& b){
	ll ans = 0, n = a.size(), eq_prefix_len = 0;
	FOR(i, n){
		if(a[i] == b[i]) ans += ++eq_prefix_len;
		else eq_prefix_len = 0;
	}

	return ans;
}

void solve(){
	ll n, k;
	cin >> n >> k;
	string a, b;
	cin >> a >> b;

	set<char> a_chars; for(auto& c: a) a_chars.insert(c);
	V<char> a_chars_v; for(auto& c: a_chars) a_chars_v.push_back(c);

	ll ans = get_no_common_substrings(a, b);
	if(k >= a_chars.size()){cout << get_no_common_substrings(a, a); return;}
	for(auto& c: makeCombi(a_chars.size(), k)){
		V<bool> mask(26, false);
		for(auto& i: c) mask[a_chars_v[i] - 'a'] = true;

		string a_masked = a;
		FOR(i, n) if(mask[a[i]-'a']) 
			a_masked[i] = b[i];

		ans = max(ans, get_no_common_substrings(a_masked, b));
	}

	cout << ans;
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