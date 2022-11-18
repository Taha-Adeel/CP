T = int(input())
for _ in range(T):
	N, K = map(int, input().split())
	A = list(map(int, input().split()))

	print("No" if K not in A or (N > 1 and A.index(K) == N-1) else "Yes")