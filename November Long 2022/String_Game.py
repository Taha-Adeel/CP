import collections

T = int(input())
for _ in range(T):
	N = int(input())
	S = input()
	freqs = collections.Counter(S)
	for f in freqs.values():
		if f%2 == 1:
			print("NO")
			break
	else:
		print("YES")