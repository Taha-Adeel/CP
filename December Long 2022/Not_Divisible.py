# TLE Code. Optimized logic uses FFT

T = int(input())
for t in range(T):
	N = int(input())
	A = list(map(int, input().split()))

	d = N
	while True:
		mod_d = set()
		for a in A:
			mod_d.add(a % d)
		if len(mod_d) == N:
			break
		d += 1
	print(d)