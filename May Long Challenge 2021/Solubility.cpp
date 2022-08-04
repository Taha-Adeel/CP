#include<iostream>

int main(){
    int T;
    std::cin >> T;
    for(int i=0; i<T; i++){
        int X,A,B;
        std::cin >> X >> A >> B;
        std::cout << (A + (100-X)*B)*10 << '\n';
    }
}