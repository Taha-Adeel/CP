#include<stdio.h>

int main(){
    int T;
    scanf("%d",&T);
    for (int i=0; i<T; i++){
        int N,x,k;
        scanf("%d %d %d",&N,&x,&k);
        if(!(x%k) || !((N+1-x)%k)) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}