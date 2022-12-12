T = int(input())
for _ in range(T):
	X, Y = map(int, input().split())
	print("YES" if X >= 2*Y else "NO")