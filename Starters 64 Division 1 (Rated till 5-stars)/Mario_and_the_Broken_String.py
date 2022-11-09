T = int(input())
for i in range(T):
	N = int(input())
	S = input()
	if S[:N//2] == S[N//2:]: print("YES")
	else: print("NO")