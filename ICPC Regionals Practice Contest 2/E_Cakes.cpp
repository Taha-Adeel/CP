#include <iostream>
using namespace std;
int main() {
  int n;
  cin>>n;
  int min=INT_LEAST16_MAX;
  int have[n],need[n];
  for(int i=0;i<n;i++)
  {
    
    cin>>need[i]>>have[i];}
  for(int i=0;i<n;i++){  
    if(have[i]<need[i]) 
    {
      min=0;break;
    }
    else
    {
      if(min>(have[i]/need[i])) min = have[i]/need[i];
    }

  }
  cout<<min;
  return 0;
}