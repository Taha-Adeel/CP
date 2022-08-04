#include <bits/stdc++.h>

using namespace std;

#define FOR(a,c)   for (int (a)=0; (a)<(c); ++(a))
using ll = long long int;
constexpr int MOD{1000000007};

ll power_modulo(ll a, ll b){
    ll counter = 1;
    ll power = a;

    while(2 * counter <=b){
        power = (power * power)%MOD;
        counter*= 2;
    }
    if(counter == b) return power%MOD;

    power = (power * power_modulo(a, b - counter))%MOD;
    return power%MOD;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        ll N, M;
        cin >> N >> M;
        ll digit_perms = (power_modulo(2, N) - 1)%MOD;
        ll total_tuples = power_modulo(digit_perms, M);
        cout << total_tuples << '\n';
    }
    return 0;
}