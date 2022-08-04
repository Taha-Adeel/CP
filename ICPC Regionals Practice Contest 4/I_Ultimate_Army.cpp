#include <iostream>
#include<vector>
#define M 1000000
using namespace std;
#include<string.h>

int main()
{
  int n;
  cin>>n;
  char bugs_str[M];
  cin>>bugs_str;
  char all_nodes[n+1];
  for(int i=0;i<=n;i++)
  {
    all_nodes[i]='N';
  }
  int temp =(bugs_str[0]);
  temp-=48;
  all_nodes[temp]='0';
  char prev_char = bugs_str[0];
  vector<char> parent;
  parent.push_back(bugs_str[0]);
  int pointer_for_parent_vec = 0;
  for(int i=1;i<strlen(bugs_str);i++)
  {

     if(bugs_str[i]!='(' && bugs_str[i]!=')')
     {
       int temp = (bugs_str[i]);
       temp-=48;
       all_nodes[temp] =parent[pointer_for_parent_vec];
     }
     if((i+1<strlen(bugs_str)) && bugs_str[i+1]=='(' && bugs_str[i]!=')')
     {
       parent.push_back(bugs_str[i]);
       pointer_for_parent_vec ++ ;

     }
     if(bugs_str[i]==')')
     {

      int back_count=0;
      int j=0;
      while((i+j+1<strlen(bugs_str)) && bugs_str[i+j+1]==')')
      {
        back_count++;j++;
      }
      pointer_for_parent_vec-=back_count;
 
     }


  }
  for(int i=1;i<=n;i++)
  {
    cout<<all_nodes[i]<<" ";
  }

}