import collections

MOD = 10**9 + 7
def mod_pow(a, b):
	if(b == 0): return 1
	return mod_pow(a*a%MOD, b//2) if b%2 == 0 else a*mod_pow(a*a%MOD, b//2)%MOD

T = int(input())
for _ in range(T):
	N, K = map(int, input().split())
	A = list(map(int, input().split()))
	
	freqs = collections.Counter([a%K for a in A])
	ans = freqs[0]+1
	for i in range(1, (K+1)//2):
		ans = (ans * (mod_pow(2, freqs[i]) + mod_pow(2, freqs[K-i]) - 1)) % MOD
	if K%2 == 0:
		ans = (ans * (freqs[K//2]+1)) % MOD
	print(ans)