import heapq
import sys

MOD = 998244353
N = 1_000_000

nums = [0] * N
prefix_sums = [0] * (N + 1)

class Num:
    def __init__(self, base):
        self.value = 1
        self.base_value = 1
        self.mod_value = 1
        self.mod_base_value = 1
        self.base = base
        self.digit = 1

    def increment(self):
        self.digit += 1
        self.value += self.base_value
        self.mod_value = (self.mod_value + self.mod_base_value) % MOD
        if self.digit == self.base:
            self.digit = 1
            self.value += 1
            self.base_value = self.value
            self.mod_value = (self.mod_value + 1) % MOD
            self.mod_base_value = self.mod_value

    def __gt__(self, other):
        return self.value > other.value

def precompute():
    nums = [0] * N
    prefix_sums = [0] * (N + 1)
    prev_num = 0
    pq = []
    for base in range(2, 17):
        heapq.heappush(pq, Num(base))

    i = 0
    while i < N:
        num = heapq.heappop(pq)
        if num.value > prev_num:
            nums[i] = num.mod_value
            prev_num = num.value
            i += 1
        num.increment()
        heapq.heappush(pq, num)

    for i in range(1, N + 1):
        prefix_sums[i] = (prefix_sums[i - 1] + nums[i - 1]) % MOD
        
    return prefix_sums

def main():
    prefix_sums = precompute()
    t = int(sys.stdin.readline())
    for _ in range(t):
        l, r = map(int, sys.stdin.readline().split())
        print((prefix_sums[r] - prefix_sums[l - 1] + MOD) % MOD)

if __name__ == "__main__":
    main()