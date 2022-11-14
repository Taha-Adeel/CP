T = int(input())
for _ in range(T):
	N = int(input())
	C = list(map(int, input().split()))
	sum_c = sum(C)%998244353
	print(sum_c*(sum_c -1)%998244353)
