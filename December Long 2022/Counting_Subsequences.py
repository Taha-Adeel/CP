MOD = 1000000007

T = int(input())
for t in range(T):
	N = int(input())
	A = list(map(int, input().split()))

	dp = [0]*(N+1) # dp[i] = number of subsequences starting with A[i]
	for i in reversed(range(N)):
		dp[A[i]] = 1
		for a in A:
			if a != A[i] and a & A[i] == a:
				dp[A[i]] += dp[a]
				dp[A[i]] %= MOD

	print(sum(dp))