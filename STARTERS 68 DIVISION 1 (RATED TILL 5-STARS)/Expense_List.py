T = int(input())
for _ in range(T):
	N, X = map(int, input().split())
	print(1<<(X-N))