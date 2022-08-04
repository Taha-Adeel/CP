#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
set<ll>s;
int main()
{
	
	ll num;
	cin>>num;
	ll a,b,c,d;
	for(int i=1;i*i<=num;i++)
	{
        	
		if((num-i*i)%(2*i)==0)
		{
			a=(num-i*i)/(2*i);
			c=a*a;
			d=num+c;
			if(c==0||d==0)
			{continue;} 
			s.insert(c);
			s.insert(-d);
		}
		
		c=num-i*i;
		a=sqrt(c);
		if(a*a==c)
		{
			if(i*i!=0&&a!=0)
			{
				s.insert(-i*i);
				s.insert(-c);	
			}					
		}
	
	}
	cout<<s.size()<<endl;
	set<ll>::iterator it=s.begin();
	for(;it!=s.end();it++)
	{
		cout<<*it<<" ";
	}
	return 0;
} 