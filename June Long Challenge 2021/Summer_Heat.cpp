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
        int xa, xb, Xa, Xb;
        cin >> xa >> xb >> Xa >> Xb;
        
        cout << Xa/xa + Xb/xb << '\n';
    }

    return 0;
}