import sys
from io import BytesIO, IOBase
import os
from typing import List

# Fast IO Region
BUFSIZE = 8192


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None

    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self, size_t=None):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()

    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)


class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline(None).decode("ascii")


sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
def input(): return sys.stdin.readline().rstrip("\r\n")
def get_int_array() -> List[int]: return list(map(int, input().split()))

MOD = 998244353

def mod_pow(a, b):
	if b == 0: return 1
	return mod_pow(a*a%MOD, b//2) * (a if b%2 else 1) % MOD

def mod_inv(a):
	return mod_pow(a, MOD-2)

def mod_div(a, b):
	return a * mod_inv(b) % MOD

T = int(input())
for t in range(T):
	N, K = input().split()
	K = int(K)

	if K == 0: 
		print(len(N)); continue

	a, pos = [], 0
	for i in reversed(range(len(N))):
		for j in range(int(N[i])):
			pos += (len(N) - i)
			a.append(pos)
	K -= 1			
	
	ans = 0
	binomial_coeff = 1
	for i in range(len(a)):
		ans += a[-(i+1)] * binomial_coeff
		ans %= MOD
		binomial_coeff = binomial_coeff * mod_div(K+i, i+1) % MOD

	print(ans)