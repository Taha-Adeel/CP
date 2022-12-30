T = int(input())
for _ in range(T):
	A = input(); B = input()
	N = len(A)

	A_1s, A_0s, B_1s, B_0s = A.count('1'), A.count('0'), B.count('1'), B.count('0')
	ans = '1'*min(A_1s, B_0s) + '1'*min(A_0s, B_1s)
	ans += '0'*(N - len(ans))
	print(ans)