#include <bits/stdc++.h>

using namespace std;

using ll = long long int;

int main(){

	int T;
	cin >> T;
	while(T--){
		ll n, x;
		cin >> n >> x;

		bool n_odd = false;
		ll k{0};

		if(n%2 == 1){
			if(x==0){
				cout << -1 << '\n';
				continue;
			}
			else{
				--n;
				--x;
				n_odd = true;
			}
		}
		
		std::vector<ll> a;
		ll bit_place{0};
		for(ll mask = 1; mask <= n; mask = mask<<1, ++bit_place){
			ll digit = mask & n;
			if(digit){
				if(bit_place%2 == 1){
					a.push_back(digit);
					++k;
				}
				else if(bit_place%2 == 0){
					a.push_back(digit/2);
					++k;
					a.push_back(digit/2);
					++k;
				}
			}
		}

		int terms_reduced{0};
		bool A1_less_than_x = false;
		ll sum = 0;
		for(int i=0; i < a.size(); ++i){
			sum+=a[i];
			if(sum <= x){
				++terms_reduced;
				A1_less_than_x = true;
			}
			else
				break;			
		}

		if(A1_less_than_x || n_odd)
			cout << k - terms_reduced + 1<< '\n';
		else
			cout << k << '\n';
	}

	return 0;
}