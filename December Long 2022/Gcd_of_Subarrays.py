T = int(input())
for _ in range(T):
	N, K = map(int, input().split())

	A = [1]*N
	A[-1] = K - (N*(N+1))//2 + 1
	if A[-1] > 0: print(*A)
	else: print(-1)