T = int(input())
for _ in range(T):
	n, a, b = map(int, input().split())
	if a + b < n:
		print(a*(n-a) + ((n-a-b)*(n-a-b-1))//2 + (n-a-b)*b)
	else:
		print((a-(a+b-n))*(b-(a+b-n)))