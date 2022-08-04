#include<iostream>
#include<iomanip>
using namespace std;
#define ld long double
int main()
{
    ld n,k;
    cin>>n>>k;
    ld d,s;
    cin>>d>>s;
    ld x= ((n*d)-(k*s))/(n-k);
    if(x<=100 && x>=0){
    cout<<setprecision(9)<<x;}
    else cout<<"impossible";return 0;
}