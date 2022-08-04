#include <bits/stdc++.h>

using namespace std;
string worklist;

int main(){
    cin >> worklist;
    int k;
    int l=1, r=worklist.size();
    while (l < r) {
        k = l + (r - l) / 2;

        unordered_map<string, int> freq;
        for (int i = 0; i < worklist.size()-k + 1; ++i){
            ++freq[worklist.substr(i, k)];
        }

        int flag=0;
        for(auto x : freq){
           if(x.second==1) {r=k; flag=1; break;}
        }
        if(flag==1) continue;
        l = k+1;
    }
    k = l;
    unordered_map<string, int> freq;
    for (int i = 0; i < worklist.size()-k + 1; ++i){
        ++freq[worklist.substr(i, k)];
    }
  
    for(int i=0; i < worklist.size()-k + 1; ++i){
        if(freq[worklist.substr(i, k)]==1){
            cout << worklist.substr(i, k) << '\n';
            return 0;
        }
    }    

  return 0;
}