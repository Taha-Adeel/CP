#include <bits/stdc++.h>

using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        long long int D, d, P, Q;
        cin >> D >> d >> P >> Q;
        long long int total = 0;
        total+= P * D;
        total+= d * Q * (((D/d - 1) * (D/d))/2);
        total+= (D%d) * Q * (D/d);
        
        cout << total << '\n';
    }

    return 0;
}