#include <stdio.h>
#include <stdlib.h>

//昇順ソート
int qs(const void *n1, const void *n2){
    if(*(int *)n1 > *(int *)n2){
        return -1;
    }else if(*(int *)n1 < *(int *)n2){
        return 1;
    }else{
        return 0;
    }
}

//gcd計算
int gcd(int *x, int *y){
    int px = *x;
    int py = *y;
    while(1){
        int q = px % py;
        if(q==0){
            return py;
        }else{
            px = py;
            py = q;
        }
    }
}

int main(void){
    char str[4];
    int N;
    long count = 0;
    fgets(str, sizeof(str), stdin);
    sscanf(str, "%d", &N);

    for(int a=1; a<N+1; a++){
        for(int b=1; b<N+1; b++){
            for(int c=1; c<N+1; c++){
                int L[3];
                int M[2];
                L[0]=a;L[1]=b;L[2]=c;
                qsort(L, sizeof(L)/sizeof(int), sizeof(int), qs);
                int Fgcd = gcd(&L[0], &L[1]);
                M[0]=Fgcd;M[1]=L[2];
                qsort(M, sizeof(M)/sizeof(int), sizeof(int), qs);
                count += gcd(&M[0], &M[1]);
            }
        }
    }
    printf("%lu\n",count);
}