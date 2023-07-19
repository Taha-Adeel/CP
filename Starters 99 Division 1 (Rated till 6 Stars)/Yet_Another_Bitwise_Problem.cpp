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
	int n; cin >> n;
	vi a(n); cin >> a;

	multiset<int> s1, s2;
	FOR(i, n) s1.insert(a[i]);

	int mask = (1 << 30), s2_or = 0;
	while(mask > 0){
		int set_cnt = 0;
		for(auto& i: s1)
			if(i & mask) set_cnt++;
		if(set_cnt == 0 || set_cnt == n){
			mask >>= 1;
			continue;
		}
		for(auto it = s1.begin(); it != s1.end();){
			int i = *it;
			if(i & mask)
				it = s1.erase(it),
				s2.insert(i), 
				s2_or |= i;
			else it++;
		}
		mask >>= 1;
		break;
	}
	
	if(s2_or == 0){
		cout << 0;
		return;
	}

	while(mask > 0){
		int bit = (mask & s2_or);
		if(bit == 0){
			int new_num = 0;
			for(auto it = s1.begin(); it != s1.end();){
				int i = *it;
				if((i & mask) != 0)
					it = s1.erase(it),
					new_num |= i;
				else it++;
			}
			if(new_num != 0) s1.insert(new_num);
		}
		else{
			int set_cnt = 0;
			for(auto& i: s1)
				if(i & mask) set_cnt++;
			if(set_cnt == s1.size()){
				mask >>= 1;
				continue;
			}
			for(auto it = s1.begin(); it != s1.end();){
				int i = *it;
				if(i & mask)
					it = s1.erase(it),
					s2.insert(i), 
					s2_or |= i;
				else it++;
			}
		}
		mask >>= 1;
	}
	int s1_or = 0;
	for(auto& i: s1) s1_or |= i;

	cout << (s1_or ^ s2_or);
}

int main(){
	FAST;
	int T;
	cin >> T;
	FOR(t, T){
		solve();
		cout << nl;
		cerr << nl;
	}
	
	return 0;
}