MOD = 998244353

T = int(input())
for _ in range(T):
	N = int(input())
	A = list(map(int, input().split()))

	A.sort()
	oneCount = A.count(1)
	for i in range(N): 
		if A[i]%2 == 0 and oneCount > 0:
			A[i] += 1
			oneCount -= 1

	ans = 1
	for a in A: 
		ans = (ans*a)%MOD
	print(ans)