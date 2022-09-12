#include <bits/stdc++.h>
using namespace std;
#define L long long
L h, a, r, d, n, i;
int main() {
	cin >> n;
	string s;
	cin >> s;
	L A[n];
	L p = -1, q = -1, u = -1, v = -1;
	for (; i < n; i++) {
		cin >> A[i];
		if (s[i] == 'h' && q == -1)
			p = i, h += A[i];
		else if (p != -1 && s[i] == 'a' && u == -1)
			q = i, a += A[i];
		else if (q != -1 && s[i] == 'r' && v == -1)
			u = i, r += A[i];
		else if (u != -1 && s[i] == 'd')
			v = i, d += A[i];
	}
	cout << min({h, a, r, d});
}