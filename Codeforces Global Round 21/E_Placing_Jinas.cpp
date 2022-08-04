#include <bits/stdc++.h>

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0)
template<class T> struct V: vector<T>{using vector<T>::vector;
	void sort_asc() {sort(this->begin(), this->end());}
	void sort_dsc() {sort(this->begin(), this->end(), greater<T>());}
	long long sum() {long long sum = 0; for(auto& i: *this) sum += i; return sum;}
	map<T, int> freqs() {map<T, int> freq; for(auto& i: *this) freq[i]++; return freq;}
	friend ostream& operator<<(ostream& out, const V<T>& v) {for(auto& i: v){out << i << ' ';} return out;}
	friend istream& operator>>(istream& in, V<T>& v) {for(auto& i: v){in >> i;} return in;}
};
void display(bool answer){cout << ((answer)?"Yes":"No");}
#define pY {cout << "Yes"; return;}
#define pN {cout << "No";  return;}

#define FOR(i, n)                for(int i = 0; i < n; ++i)
#define FOR_RANGE(i, start, end) for(int i = start; i != end; i += (start<end) ? 1 : -1)
#define FOR_REV(i, n)            for(int i = n-1; i >= 0; --i)

#define F  first
#define S  second
#define pb push_back
constexpr char nl = '\n';
constexpr int MOD = 1000000007;
using ll  = long long int;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi  = V<int>;
using vll = V<ll>;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/
ll power(ll x, ll y, ll p)
{
    ll res = 1; 
 
    x = x % p; 
 
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
 
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
 
// Returns n^(-1) mod p
ll modInverse(ll n, int p)
{
    return power(n, p - 2, p);
}

ll fac[400006];
 
// Returns nCr % p using Fermat's little
// theorem.
ll nCrModPFermat(ll n, ll r, ll p)
{
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;
 
    return (fac[n] * modInverse(fac[r], p) % p
            * modInverse(fac[n - r], p) % p) % p;
}
 

void solve(){
	int n;
	cin >> n;
	vll a(n+1);
	cin >> a;

	ll ans = 0;
	FOR(i, n+1){
		ans = (ans + nCrModPFermat(a[i]+i, i+1, MOD))%MOD;
	}

	cout << ans;
}

int main(){
    fac[0] = 1;
    for (ll i = 1; i <= 400005; i++)
        fac[i] = (fac[i - 1] * i) % MOD;
	solve();
	cout << nl;
	
	return 0;
}