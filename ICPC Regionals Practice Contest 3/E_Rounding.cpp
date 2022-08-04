#include <bits/stdc++.h>
 
using namespace std;
 
#define FOR(a,c)   for (int (a)=0; (a)<(c); ++(a))
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int P;
    cin >> P;
    string place[P];
    int percent[P];
    double percent_min[P], percent_max[P];
    int total_percent{0};
    int num_of_zero{0}, num_of_hundred{0};
 
    FOR(i, P){
        cin >> place[i] >> percent[i];
        total_percent+=percent[i];
        if(percent[i]==0) ++num_of_zero;
        if(percent[i]==100) ++num_of_hundred;
    }
 
    double error = 100.00 - total_percent;
    if((error > 0 && (P - num_of_hundred) * 0.49 < error) || (error < 0 && (P - num_of_zero) * (-0.5) > error)){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
 
    double min_delta, max_delta;
    if(error > 0){
        min_delta = max(error - ((P-1) * 0.49), -0.50);
        max_delta = 0.49;
    }
    else if(error < 0){
        min_delta = -0.50;
        max_delta = min(error - ((P-1) * (-0.50)),0.49);
    }
    else{
        min_delta = max(error - ((P-1) * 0.49), -0.50);
        max_delta = min(error - ((P-1) * (-0.50)),0.49);
    }
 
    cout << fixed << setprecision(2);
    FOR(i,P){
        percent_min[i]=(percent[i]==0 && min_delta<0)? 0.00  : (percent[i] + min_delta);
        percent_max[i]=(percent[i]==100 && max_delta>0)? 100.00  : (percent[i] + max_delta);
        cout << place[i] << ' ' << percent_min[i] << ' ' << percent_max[i] << '\n';
    }
 
    return 0;
}