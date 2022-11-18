T = int(input())
for _ in range(T):
	N, Q = map(int, input().split())
	A = list(map(int, input().split()))

	ps = [[0]*60 for i in range(N+1)]
	for i in range(N):
		for j in range(60):
			ps[i+1][j] = ps[i][j] + (A[i] >> j & 1)
		
	for q in range(Q):
		k, L1, R1, L2, R2 = map(int, input().split())
		ones1 = ps[R1][k] - ps[L1-1][k]; zeros1 = R1 - L1 + 1 - ones1
		ones2 = ps[R2][k] - ps[L2-1][k]; zeros2 = R2 - L2 + 1 - ones2
		print(ones1*zeros2 + zeros1*ones2)
