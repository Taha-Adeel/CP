#include<bits/stdc++.h>

using namespace std;

int main(){
    int T;
    cin >> T;
    for(int t=0; t<T; ++t){
        int N , M;
        cin >> N >> M;
        
        int counter{0};
        for(int a=1; a<min(N,M/2); a++){
            for(int b=a+1; b<=min(N,M); b++){
                if(M%a==(M%b)%a){
                    //cout << '(' << a << ',' << b << ")\n";
                    counter++;
                }
            }
        }
        if(N>M){
            counter = counter + (N-M)*M + ((N-M-1)*(N-M))/2;
        }
        cout << counter << '\n'; 
    }
    return 0;
}