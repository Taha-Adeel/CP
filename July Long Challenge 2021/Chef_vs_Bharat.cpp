#include <bits/stdc++.h>

using namespace std;

using ll = long long int;
constexpr int MOD{1000000007};

ll power_modulo(ll a, ll b){
	if(b==0) return 1;
    ll counter = 1;
    ll power = a;

    while(2 * counter <=b){
        power = (power * power)%MOD;
        counter*= 2;
    }
    if(counter == b) return power%MOD;

    power = (power * power_modulo(a, b - counter))%MOD;
    return power%MOD;
}

int main(){
	vector<ll> A(100001), sum(100001);
	for(int i=1; i<=100000; ++i){
		int no_digits_in_i = floor(log10(i) + 1);
		int no_digits_in_A_i = 2 * no_digits_in_i - 1;
		A[i] = i * power_modulo(10, no_digits_in_i - 1);
		for(int j=0; j<no_digits_in_i - 1; ++j){
			A[i] += ((i/power_modulo(10, no_digits_in_i - 1 - j))%10)*power_modulo(10, j);
		}
		sum[i] = sum[i-1] + A[i];
	}

	int Q;
	cin >> Q;
	while(Q--){
		int L, R;
		cin >> L >> R;

		cout << power_modulo(A[L], sum[R]-sum[L]) << endl;
	}
	return 0;
}