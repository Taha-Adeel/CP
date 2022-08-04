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
        int N, M, K;
        cin >> N >> M >> K;
        int L[K];
        map<int, int> freq;
        int counter{0};
        FOR(i,K){
            cin >> L[i];
            if(L[i]<=N)
                ++freq[L[i]];
        }
        for(auto x:freq){
            if(x.second > 1 ){
                counter++;
            }
        }
        cout << counter;  
        for(auto x:freq){
            if(x.second > 1 ){
                cout << " " << x.first;
            }
        }
        cout << endl;     
    }

    return 0;
}