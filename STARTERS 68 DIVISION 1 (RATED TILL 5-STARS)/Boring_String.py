from string import ascii_lowercase as a_to_z

T = int(input())
for _ in range(T):
	N = int(input())
	S = input()
	ans = curLen = 1
	for i in range(1, N):
		if S[i] == S[i-1]: curLen += 1
		if S[i] != S[i-1] or i == N-1:
			if curLen > ans: ans = curLen
			curLen = 1

	for ch in a_to_z:
		if S.count(ch*ans) > 1:
			print(ans)
			break
	else:
		print(ans-1)