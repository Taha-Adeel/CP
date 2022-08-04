#include <iostream>
#include <ext/rope>

int n, k, p, i;
int main() {
	std::cin >> n >> k;

	__gnu_cxx::rope<int> r;
	while(i < n)
		r.push_back(++i);
	
	while (r.size()) {
		p = (p + k) % r.size();
		std::cout << r.at(p) << ' ';
		r.erase(p, 1);
	}
}