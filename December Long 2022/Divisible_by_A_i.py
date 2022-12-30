import math

T = int(input())
for t in range(T):
	N = int(input())
	A = list(map(int, input().split()))

	total_gcd = math.gcd(*A)
	print(*[a//total_gcd for a in A])