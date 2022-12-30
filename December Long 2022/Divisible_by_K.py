import math

T = int(input())
for _ in range(T):     
    N, K = map(int, input().split())
    A = list(map(int, input().split()))
    
    for a in A: 
        K //= math.gcd(a, K)
    
    print("YES" if K == 1 else "NO")