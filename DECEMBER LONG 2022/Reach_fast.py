T = int(input())
for _ in range(T):
	X, Y, K = map(int, input().split())
	print((abs(Y-X) + K-1)//K)