import collections

T = int(input())
for _ in range(T):
	N = int(input())
	A = list(map(int, input().split()))
	freqs = collections.Counter(A)
	for k in freqs:
		if freqs[k] > 2:
			print("No")
			break
	else:
		print("Yes")
