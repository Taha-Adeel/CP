T = int(input())
for t in range(T):
	x1, y1, x2, y2 = map(int, input().split())
	d1, d2 = x1**2 + y1**2, x2**2 + y2**2
	print("ALEX" if d1 > d2 else "BOB" if d1 < d2 else "EQUAL")