T = int(input())
for t in range(T):
	N = int(input())
	A = list(map(int, input().split()))
	B = list(map(int, input().split()))

	min_arr = [min(A[i], B[i]) for i in range(N)]
	max_arr = [max(A[i], B[i]) for i in range(N)]

	pairs = sorted(zip(min_arr, max_arr), key=lambda x: x[0])

	if(max(min_arr) > min(max_arr)):
		print(max(min_arr) - min(max_arr))
		continue

	ans = min(max(min_arr) - min(min_arr), max(max_arr) - min(max_arr))
	cur_max = max(min_arr)
	for i in range(N-1):
		cur_max = max(cur_max, pairs[i][1])
		ans = min(ans, cur_max - pairs[i+1][0])
	
	print(ans)