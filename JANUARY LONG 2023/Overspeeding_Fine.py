T = int(input())
for t in range(T):
	X = int(input())
	print(0 if X <= 70 else 500 if X <= 100 else 2000)