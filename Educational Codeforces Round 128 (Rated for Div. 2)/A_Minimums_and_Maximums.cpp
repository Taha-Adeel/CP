#include <iostream>
 
using namespace std;
 
int main(){
    int T;
    cin >> T;
    while(T--){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        
        int m = max(l1, l2);
        
        if(m <= r1 && m <= r2){
            cout << m << endl;
        }
        else
            cout << l1 + l2 << endl;
    }
    
    
    return 0;
}