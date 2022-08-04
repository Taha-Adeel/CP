#include <bits/stdc++.h>

using namespace std;

bool isPrime(int x){
	if(x == 1)
		return false;
	bool isprime = true;
	for(int i = 2; i*i <= x; ++i){
		if(x%i == 0){
			isprime = false;
			break;
		}
	}
	return isprime;
}

int main(){
	int n;
	cin >> n;
	
	if(n==2)
		cout << -1 << '\n';
	else{
		if(isPrime(n-2)){
			cout << 2 << ' ' << n-2 << '\n';
		}
		else
			cout << -1 << '\n';
	}

	return 0;
}