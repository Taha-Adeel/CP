T = int(input())
for _ in range(T):
	A, B = map(int, input().split())
	print("Alice" if A+B in {2, 3, 5, 7, 11} else "Bob")