#include <ext/rope>

int n, k, p, i;
main() {
	__gnu_cxx::rope<int> r;
	for (scanf("%d %d", &n, &k); i < n;)
		r += ++i;
	
	for (;n = r.size(); r.erase(p, 1))
		printf("%d ", r[(p += k) %= n]);
}