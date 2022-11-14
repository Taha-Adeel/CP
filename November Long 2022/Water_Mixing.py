T = int(input())
for _ in range(T):
	A, B, X, Y = map(int, input().split())
	if A-Y <= B <= A+X:
		print("YES")
	else:
		print("NO")