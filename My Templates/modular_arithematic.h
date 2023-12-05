#include <vector>
#include <iostream>
using ll = long long int;
constexpr int MOD = 1000000007;
template<int MOD = MOD, int MxN = 1'000'001>
class Z {
	int val;
	static vector<Z> fact;
	static void init_fact() { fact.resize(MxN); fact[0] = 1; for(int i = 1; i < MxN; ++i) fact[i] = fact[i-1] * i; }
public:
	Z(ll v = 0) : val(v%MOD) { if(val < 0) val += MOD; }

	Z pow(ll e) const { Z res = 1; for(Z b = val; e > 0; b = b*b, e /= 2) if(e & 1) res = res*b; return res; }
	Z inv() const { return pow(MOD-2); }
	static Z nCr(int n, int k) { if(k < 0 || k > n) return 0; if(fact.empty()) init_fact(); return fact[n] / (fact[k] * fact[n-k]); }

	Z operator+(const Z& o) const { return Z(val + o.val); }
	Z operator-(const Z& o) const { return Z(val - o.val); }
	Z operator*(const Z& o) const { return Z((ll)val * o.val); }
	Z operator/(const Z& o) const { return *this * o.inv(); }
	Z operator-() const { return Z(-val); }
	Z operator+=(const Z& o) { return *this = *this + o; }
	Z operator-=(const Z& o) { return *this = *this - o; }
	Z operator*=(const Z& o) { return *this = *this * o; }
	Z operator/=(const Z& o) { return *this = *this / o; }
	bool operator==(const Z& o) const { return val == o.val; }
	bool operator!=(const Z& o) const { return val != o.val; }

	friend istream& operator>>(istream& in, Z& z) { ll v; in >> v; z = Z(v); return in; }
	friend ostream& operator<<(ostream& out, const Z& z) { return out << z.val; }
};

// // Returns the gcd and finds the value of x, y s.t. ax + by = gcd(a, b). And x = mod_inverse of a (mod b).
// ll extended_gcd(ll a, ll b, ll& x, ll& y){
// 	if(b == 0) return x = 1, y = 0, a;
// 	ll gcd = extended_gcd(b, a%b, y, x);
// 	y -= (a/b) * x;
// 	return gcd;
// }

// ll mod_inverse(ll n, ll mod = MOD) {
// 	ll x, y;
// 	extended_gcd(n, mod, x, y);
// 	return (x%mod + mod)%mod;
// }