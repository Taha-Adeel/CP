#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int A, B, C;

    cin >> A >> B >> C;
    
    int LCM= A*B*C;  
    int wa{ LCM/A}, wb{LCM/B}, wc{LCM/C};
    
    int w[3000], a[3000]{}, b[3000]{}, c[3000]{};
    a[0]=1;b[0]=1;c[0]=1;
    int k;
    int i, i_last{0};

    for(k=0;a[k]<=A && b[k]<=B && c[k]<=C ;k++){
        i=std::min(std::min(a[k]*wa, b[k]*wb), c[k]*wc);
        w[k]=i-i_last;
        if(i==a[k]*wa) a[k+1]=a[k]+1;
        if(i==b[k]*wb) b[k+1]=b[k]+1;
        if(i==c[k]*wc) c[k+1]=c[k]+1;

        if(a[k+1]==0) a[k+1]=a[k];
        if(b[k+1]==0) b[k+1]=b[k];
        if(c[k+1]==0) c[k+1]=c[k];
        i_last=i;
    };
    
    cout << k << '\n';
    for(int j=0; j<k; j++){
        cout << w[j] <<' ' << a[j] <<' ' << b[j]<< ' ' << c[j] << '\n';
    }

    return 0;
}