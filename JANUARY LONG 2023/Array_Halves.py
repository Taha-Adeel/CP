T = int(input())
for t in range(T):
	N = int(input())
	A = list(map(int, input().split()))

	ai, bi = [], []
	for i in range(N):
		if A[i] > N: ai.append(i)
		if A[i+N] <= N: bi.append(i+N)
	
	ans = 0
	for i in range(len(ai)):
		ans += bi[i] - ai[i]
	print(ans)