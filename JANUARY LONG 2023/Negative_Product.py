T = int(input())
for t in range(T):
	a, b, c = map(int, input().split())
	print("YES" if min(a*b, b*c, c*a) < 0 else "NO")