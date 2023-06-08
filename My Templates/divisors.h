#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i = 0; i < (int)n; ++i)
#define FOR1(i, n) for(int i = 1; i <= (int)n; ++i)
#define V vector
#define pb push_back
#define F first
#define S second

using ll  = long long int;
using vi = vector<int>;
using pii = pair<int,int>;;

// Seive of Eratosthenes
#define MAXN 100010
vi primes;
void seive(){
	int N = sqrt(MAXN) + 1;
	vi is_prime(N+1, 1);
	is_prime[0] = is_prime[1] = 0;
	for(int i=2; i*i<=N; i++) if(is_prime[i])
		for(int j=i*i; j<=N; j+=i)
			is_prime[j] = 0;
	FOR(i, N+1) if(is_prime[i]) primes.pb(i);
}

V<pii> getPrimeFactors(int n){
	V<pii> factors;
	for(auto& p: primes){
		if(p*p > n) break;
		if(n%p == 0){
			int cnt = 0;
			while(n%p == 0){
				n /= p;
				cnt++;
			}
			factors.pb({p, cnt});
		}
	}
	if(n > 1) factors.pb({n, 1});
	return factors;
}

void setDivisors(vi& divisors, int i, int n, const V<pii>& factors){
	if(i == factors.size()){
		divisors.pb(n);
		return;
	}
	int p = factors[i].F, cnt = factors[i].S;
	FOR1(j, cnt){
		setDivisors(divisors, i+1, n, factors);
		n *= p;
	}
	setDivisors(divisors, i+1, n, factors);
}

vi divisors_dp[MAXN];
vi getDivisors(int n){
	if(divisors_dp[n].size()) return divisors_dp[n];
	auto factors = getPrimeFactors(n);
	vi divisors;
	setDivisors(divisors, 0, 1, factors);
	sort(divisors.begin(), divisors.end());
	divisors_dp[n] = divisors;
	return divisors;
}