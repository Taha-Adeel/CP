#include <bits/stdc++.h>

using namespace std;

#define FOR(a,c)   for (int (a)=0; (a)<(c); ++(a))

int main(){

    int T;
    cin >> T;
    while(T--){
        int N, M;
        cin >> N >> M;
        vector<int> A(N,0), B(M,0);
        vector<int> C(N, -1);
        int last_forward = -1;
        int last_backward = -1;
        FOR(i, N){
            cin >> A[i];
            if(A[i] == 1){
                last_forward = i;
            }
            if(last_forward != -1)
                C[i] = i - last_forward;
        }
        for(int i = N-1; i>=0; --i){
            if(A[i] == 2){
                last_backward = i;
            }
            if(C[i] == -1 && last_backward == -1){C[i]=-1;}
            else if(C[i] == -1) C[i] = last_backward - i;
            else if(last_backward !=-1) C[i] = std::min(C[i], last_backward - i);
        }
        C[0]=0;
        FOR(i, M){
            cin >> B[i];
        }
        FOR(i, M){
            cout << C[B[i]-1] << ' ';
        }
        cout << endl;
    }

    return 0;
}