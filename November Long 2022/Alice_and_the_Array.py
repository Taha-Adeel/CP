MOD = 10**9 + 7

def mod_pow(a, b):
	if b == 0: return 1
	return mod_pow(a*a % MOD, b//2) * (a if b%2 else 1) % MOD

def mod_inv(a):
	return mod_pow(a, MOD-2)

T = int(input())
for _ in range(T):
	N = int(input())
	