#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t,counter,flag;
	cin>>t;
	while(t--){
        int n;
	    counter =0;
	    flag=0;
	    cin>>n;
        vector<int> g1(n);
	    for(int i=0; i< n; i++){
	        cin>>g1[i];
	    }
	    map<int, int> m;
        for (int i = 0; i < n; i++){
            m[g1[i]]++;
        }
        for (auto i : m){
             if(i.first != i.second){
                 flag =1;
             }
        }
        if( flag ==0){
            cout<<"yes"<<endl;
        }
        else{
            cout<<"no"<<endl;
        }	    
	}
	return 0;
}