#include<iostream>

using namespace std;

int main(){
    int T;
    cin >> T;
    for (int i=0; i<T; ++i){
        int N;
        cin >> N;
        long long int x=1;
        for(int i=0; i<(N-1)/30; ++i){
            x=(x*1073741824)%(1000000000+7);
        }
        for(int i=0; i<(N-1)%30; ++i){
            x=(x*2)%(1000000000+7);
        }
        cout << x << '\n';
    }

    return 0;
}