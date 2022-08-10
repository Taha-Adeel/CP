using ll = long long int;
constexpr int MOD = 1e9 + 7;

// Precompute factorials to be used for nCr calculations
#define MxN 100001
ll factorial[MxN];
void calc_factorials(){
	factorial[0] = 1;
	for(ll i = 1; i <= MxN; i++)
		factorial[i] = (factorial[i - 1] * i) % MOD;
}

// x ^ y (mod MOD) (using binary exponentiation)
ll mod_pow(ll x, ll y) {
	if (y == 0) 
		return 1;
	ll p = mod_pow(x, y/2) % MOD;
	p = (p * p) % MOD;

	return (y % 2 == 0) ? p : (x * p) % MOD;
}

// Using Fermat's Little Theorem (only works for prime MOD)
ll mod_inverse(ll x) {
	return mod_pow(x, MOD-2);
}

// x/y (mod MOD)
ll mod_div(ll x, ll y){
	return (x * mod_inverse(y)) % MOD;
}

// nCr (mod MOD)
ll mod_nCr(ll n, ll r){
	return mod_div(factorial[n], factorial[r] * factorial[n-r]);
}