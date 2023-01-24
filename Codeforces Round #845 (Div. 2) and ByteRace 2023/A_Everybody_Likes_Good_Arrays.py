T = int(input())
for t in range(T):
	N = int(input())
	A = list(map(int, input().split()))
	
	ans = 0
	for i in range(N-1):
		if A[i+1] % 2 == A[i]%2:
			ans += 1
	print(ans)