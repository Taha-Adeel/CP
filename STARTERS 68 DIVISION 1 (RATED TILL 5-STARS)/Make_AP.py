T = int(input())
for _ in range(T):
	A, C = map(int, input().split())
	print((A+C)//2 if (A+C)%2 == 0 else -1)