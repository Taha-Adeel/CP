#include <bits/stdc++.h>

using namespace std;

int main(){
	int S, X;
	cin >> S >> X;

	int max{0};

	for(int size = S; S>0;++max){
		S = S/X;
	}

	cout << max << '\n';

	return 0;
}