T = int(input())
for t in range(T):
	N = int(input())
	A = list(map(int, input().split()))

	cur_excess, cur_sum, ans = 0, 0, 0
	for i in range(N):
		cur_sum += A[i]
		if(A[i] > ans):
			old_ai = A[i]
			A[i] = max(A[i] - cur_excess, ans);
			cur_excess -= old_ai - A[i]
			if(A[i] > ans): 
				ans = (cur_sum+i)//(i+1)
				cur_excess = (i+1)*ans - cur_sum
		else:
			cur_excess += ans - A[i]

	print(ans)