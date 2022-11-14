factorials = [1]
MOD = 10**9 + 7
for i in range(1, 1000001):
	factorials.append((factorials[-1]*i)%MOD)

T = int(input())
for _ in range(T):
	N = int(input())
	A = list(map(int, input().split()))
	ans = 0;
	for a in A:
		ans = (ans + factorials[a])%MOD

	print(ans)
	