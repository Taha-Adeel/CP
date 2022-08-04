#include <bits/stdc++.h>
#include <cmath>
#include <iomanip>

using namespace std;

#define FOR(a,c)   for (int (a)=0; (a)<(c); ++(a))
#define FAST ios::sync_with_stdio(0); cin.tie(0);
using ll = long long int;
using p_ii = pair<int,int>;
#define PI 3.14159265358979323846
constexpr int MOD{1000000007};
constexpr ll INF{1000000000000000003};

int main(){
	int S, N;
	cin >> N >> S;

	long double R = S/(2.0 * sin(PI/N));
	long double area = PI * R * R;
	std::cout << std::fixed;
	cout << std::setprecision(9) << area;

	return 0;
}