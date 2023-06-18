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

void print(ll a, ll b){
	cout << a << " + " << b << " = " << a+b;
}

// Find kth equation such that a+b=c, where a, b, c are A, B, C digit numbers respectively.
void solve(){
	ll A, B, C, k; cin >> A >> B >> C >> k; // A, B, C in [1, 6] 

	if(C < max(A, B)) {cout << -1; return;} 

	if(A == B){
		if(C == A){
			ll d = 8; FOR(i, A-1) d *= 10;
			ll max_k = (d*(d+1))/2;
			if(k > max_k) {cout << -1; return;}

			ll a = 1, b = 1; FOR(i, A-1) a *= 10, b *= 10;
			while(k - d > 0){
				k -= d; a++, d--;
			}
			b += k-1;
			print(a, b);
		}
		else if(C == A+1){
			ll a = 1, b = 9; FOR(i, A-1) a *= 10, b *= 10;
			ll d = a, b0 = b, c0 = a+b;
			while(k - d > 0 && a < c0){
				k -= d;
				a++;
				if(d < b0) d++, b--;
			}
			b += k-1;
			if(a >= c0) {cout << -1; return;}
			print(a, b);
		}
		else {cout << -1; return;}
	}
	else {
		if(A > B){
			if(C == A){
				ll a = 1, b = 1; FOR(i, A-1) a *= 10; FOR(i, B-1) b *= 10;
				ll a_max = 1; FOR(i, A) a_max *= 10;
				ll d = 9; FOR(i, B-1) d *= 10;
				while(k - d > 0 && a < a_max){
					k -= d;
					a++;
					if(a+d >= a_max) d--;
				}
				b += k-1;
				if(a >= a_max) {cout << -1; return;}
				print(a, b);
			}
			else if(C == A+1){
				ll c_min = 1; FOR(i, C-1) c_min *= 10;
				ll b = 1; FOR(i, B) b *= 10; b--;
				ll a = c_min - b;
				ll d = 1;

				while(k - d > 0 && a < c_min){
					k -= d;
					a++;
					d++, b--;
				}
				b += k-1;
				if(a >= c_min) {cout << -1; return;}
				print(a, b);
			}
			else {cout << -1; return;}
		}
		else {
			if(C == B){
				cout << -2; return;
			}
			else if(C == B+1){
				ll a = 1; FOR(i, A-1); a *= 10;
				ll a_max = 1; FOR(i, A) a_max *= 10;
				ll c_min = 1; FOR(i, C-1) c_min *= 10;
				ll b = c_min - a;
				ll b_max = 1; FOR(i, B) b_max *= 10;
				ll d = b_max - b;

				while(k - d > 0 && a < a_max){
					k -= d;
					a++;
					b--, d++;
				}
				b += k-1;
				if(a >= a_max) {cout << -1; return;}
				print(a, b);
			}
			else {cout << -1; return;}
		}
	}
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