T = int(input())
for _ in range(T):
	N, X, C = map(int, input().split())
	A = [max(X-C, a) for a in map(int, input().split())]

	print(sum(A))
