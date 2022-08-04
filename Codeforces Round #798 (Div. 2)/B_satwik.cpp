#include <bits/stdc++.h>

using namespace std;

#define FAST 		ios::sync_with_stdio(0); cin.tie(0)
#define FOR(a,c) 	for (int a=0; a<c; ++a)
template<class T> struct v: vector<T>{using vector<T>::vector;
	void sort_asc() {sort(this->begin(), this->end());}
	void sort_dsc() {sort(this->begin(), this->end(), greater<T>());}
	friend ostream& operator << (ostream &outFunc, const v<T> &_v) {for(auto& i: _v) outFunc << i << ' '; return outFunc;}
	friend istream& operator >> (istream &inFunc, v<T> &_v) {for(auto& i: _v) inFunc >> i; return inFunc;}
};

#define f 	first
#define s 	second
constexpr char nl = '\n';
constexpr int MOD = 1000000007;
using ll   = long long int;
using p_ii = pair<int,int>;
using p_ll = pair<ll,ll>;
using v_i  = v<int>;
using v_ll  = v<ll>;

void swap(vector<int>& a,int i, int j)
{
    int temp = a[i];
    a[i] = a[j];    
    a[j] = temp;
}
void smallest(vector<int>& nums, int i,map<int,int>& org_ind) {
        int n = nums.size();
        int smallest = 0;
        if(org_ind[nums[i]] == i || i == n-2)
        {
            smallest = i+1;
        }
        else {smallest = i;}
        FOR(j,i+1,n)
        {
            if(nums[smallest]>nums[j])
            {
                smallest = j;            
            }
        }
        swap(nums,i,smallest);


    }

int main()
{
  int t;
  cin>>t;
  while(t--)
    {
      int n;
      cin>>n;
      if(n==1)
      {
          cout<<-1;
          continue;
      }
      vector<int> a(n);
      for(auto &i: a)
      {
          cin>>i;
      }
      map<int,int> org_ind;
      For(n)
      {
          org_ind[a[i]] = i;
      }
      For(n-1)
      {
          smallest(a,i,org_ind);
      }
      For(n)
      {
          cout<<a[i]<<" ";
      }
      cout<<endl;
  }

}