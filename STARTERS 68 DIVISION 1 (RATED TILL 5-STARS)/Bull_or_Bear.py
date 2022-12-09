T = int(input())
for _ in range(T):
	X, Y = map(int, input().split())
	print("PROFIT" if X < Y else "LOSS" if X > Y else "NEUTRAL")