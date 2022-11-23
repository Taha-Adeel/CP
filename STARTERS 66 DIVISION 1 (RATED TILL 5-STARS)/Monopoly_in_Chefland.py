T = int(input())
for i in range(T):
	R1, R2, R3 = map(int, input().split())
	sum = R1 + R2 + R3
	if max(R1, R2, R3) > sum - max(R1, R2, R3):
		print("Yes")
	else:
		print("No")