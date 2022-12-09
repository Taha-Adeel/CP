T = int(input())
for _ in range(T):
	N = int(input())
	A = list(map(int, input().split()))

	A.sort()
	ans = []
	for i in range(N):
		ans.append(A[2*i] if i%2==0 else A[N//2 + i])