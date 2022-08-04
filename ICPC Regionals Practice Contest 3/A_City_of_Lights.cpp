#include <bits/stdc++.h>

using namespace std;

#define FOR(a,c)   for (int (a)=0; (a)<(c); ++(a))

int max(int *arr, int size){
    int _max=-1;
    for(int i=0; i<size; ++i){
        if(arr[i] > _max) _max = arr[i];
    }
    return _max;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, k{};
    cin >> N >> k;
    bool power[N]{0};
    int Q[100];
    int counter[100]{};
    FOR(i, k){
        cin >> Q[i];
        for(int n=1; n*Q[i]<=N; ++n){
            power[n*Q[i]-1]= !power[n*Q[i]-1];
        }
        for(int j=0; j<N; ++j){
            counter[i]+=static_cast<int>(power[j]);
        }
    }
    cout << max(counter, k) << '\n';    

    return 0;
}