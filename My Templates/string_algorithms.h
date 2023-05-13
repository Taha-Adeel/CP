#include <string>
#include <vector>

using namespace std;
using vi = vector<int>;

/* String Searching Algorithms */

// Knuth-Morris-Pratt Algorithm. 
// Returns pi_s s.t pi_s[i] = largest k < i s.t s[0...(k-1)] == s[(i-(k-1))...i]
vi kmp_algo(string& s) {
	int n = s.size();
	vi pi_s(n, 0);
	for(int i = 1, j = 0; i < n; i++) {
		while(j > 0 && s[j] != s[i])
			j = pi_s[j - 1];

		if(s[i] == s[j]) j++;
		pi_s[i] = j;
	}
	return pi_s;
}

// Returns z s.t z[i] = largest  k < n s.t s[0...(k-1)] == s[(i)...(i+(k-1))]
vi z_function(string& s) {
	int n = s.size();
	vi z(n, 0);
	for(int i = 1, l = 0, r = 0; i < n; ++i){
		if(i <= r)
			z[i] = min(r - i + 1, z[i - l]);
		while(i + z[i] < n && s[z[i]] == s[i + z[i]])
			++z[i];
		if(i + z[i] - 1 > r)
			l = i, r = i + z[i] - 1;
	}
	return z;
}

vi z_function_trivial(string& s) {
	int n = s.size();
	vi z(n, 0);
	for(int i = 1; i < n; ++i)
		while(i + z[i] < n && s[z[i]] == s[i + z[i]])
			++z[i];
	return z;
}