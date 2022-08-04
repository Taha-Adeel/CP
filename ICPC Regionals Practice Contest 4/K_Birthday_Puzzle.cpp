#include <iostream>
#include<math.h>
using namespace std;
#define ll long long int

int main()
{
  ll n;ll fin_ans=0;
  cin>>n;
  ll arr[n];
  for(ll i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  for(ll i=0;i<32;i++)
  {
    ll count_z=0;
    for(ll j=0;j<n;j++)
    {
      if((arr[j]>>i)%2==0) count_z++;
    }
    
    ll no_subs_one_at_i = pow(2,n) - pow(2,count_z);
    fin_ans+=no_subs_one_at_i * pow(2,i);
  }
  cout<<fin_ans;
}