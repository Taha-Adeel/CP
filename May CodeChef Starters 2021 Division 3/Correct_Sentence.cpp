#include <bits/stdc++.h>

using namespace std;

#define FOR(a,c)   for (int (a)=0; (a)<(c); ++(a))
using ll = long long int;
using p_ii = pair<int,int>;
constexpr int MOD{1000000007};
constexpr ll INF{1000000000000000003};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--){
       int K;
       cin >> K; 
       string word[10];
       bool check{true};
       FOR(i,K){
           cin >> word[i];
           if(word[i][0]<='m' && word[i][0]>='a'){
               FOR(j, word[i].size()){
                   if(!(word[i][j]<='m' && word[i][j]>='a')){
                       check = false;
                       break;
                   }
               }
           }
           else if(word[i][0]<='Z' && word[i][0]>='N'){
               FOR(j, word[i].size()){
                   if(!(word[i][j]<='Z' && word[i][j]>='N')){
                       check = false;
                       break;
                   }
               }
           }
           else check = false; 
       }
       if(check) cout << "YES\n";
       else cout << "NO\n";
    }

    return 0;
}