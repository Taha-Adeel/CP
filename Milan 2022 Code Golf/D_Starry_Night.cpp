#import <bits/stdc++.h>
using namespace std;
long long n, s, i, d = 2e9;
main ()
{
    cin>>n;
    s = 2*n;
    long long a[s];
    for(; i<s;) cin>>a[i++];
    sort(a,a+s);
	for(i = 1; i < n; i++)
		d = min(d, a[i+n-1]-a[i]);
    cout<<min((a[n-1] - a[0])*(a[s-1] - a[n]), (a[s-1]-a[0])*d);
}