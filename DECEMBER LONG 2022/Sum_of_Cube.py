MOD = 998244353

T = int(input())
for t in range(T):
	N = int(input())
	A = list(map(int, input().split()))

	ps = [0]*(N+1)
	for i in range(N): ps[i+1] = ps[i] + A[i]

	aj_sum, aj2_sum, ak_ps_sum = [0]*(N+2), [0]*(N+1), [0]*(N+2)
	for j in reversed(range(N)): 
		aj_sum[j] = aj_sum[j+1] + (N-j) * A[j]
		aj2_sum[j] = aj2_sum[j+1] + (N-j) * A[j] * A[j]
		ak_ps_sum[j] = ak_ps_sum[j+1] + (N-j) * A[j] * ps[j]

	ans = 0
	for i in range(N):
		ans += (N-i) * (i+1) * A[i] * A[i] * A[i]
		ans += 3 * (i+1) * A[i] * (A[i]*aj_sum[i+1] + aj2_sum[i+1])
		ans += 6 * (i+1) * A[i] * (ak_ps_sum[i+2] - ps[i+1] * aj_sum[i+2])
		ans %= MOD

	print(ans)