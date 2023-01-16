T = int(input())
for t in range(T):
	N = int(input())
	A = list(map(int, input().split()))
	A += list(map(int, input().split()))
	A.sort()
	ans = 1e9+5
	for i in range(N+1):
		ans = min(ans, A[i+N-1] - A[i])
	print(ans)