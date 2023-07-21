def get_total_cardboard(a, w):
    ans = 0
    for i in a:
        ans += (i + 2 * w) * (i + 2 * w)
    return ans

def solve():
    n, c = map(int, input().split())
    a = list(map(int, input().split()))

    # Binary search for total cardboard == c;
    lo, hi = 0, int(1e9)
    while lo < hi:
        mid = lo + (hi - lo + 1) // 2
        if get_total_cardboard(a, mid) <= c:
            lo = mid
        else:
            hi = mid - 1

    print(lo)

if __name__ == "__main__":
    T = int(input())
    for t in range(T):
        solve()
