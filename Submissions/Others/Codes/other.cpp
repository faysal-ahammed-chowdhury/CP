#include<stdio.h>

void banglaNumber(long long int X){
    if(X>9999999){
        printf(" %lld kuti",X/10000000);
        X = X%10000000;
    }
    if(X>99999){
        printf(" %lld lakh",X/100000);
        X = X%100000;
    }
    if(X>999){
        printf(" %lld hajar",X/1000);
        X = X%1000;
    }
    if(X>99){
        printf(" %lld shata",X/100);
        X = X%100;
    }
    if(X<100 && X>0){
        printf(" %lld",X);
    }
}

int main(void){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    long long int N;
    int i=0;

    while(scanf("%lld",&N)!=EOF){
        printf("%4d.",++i);

        if(N == 0){
            printf(" 0\n");
            continue;
        }

        if(N>9999999){
            banglaNumber(N/10000000);
            printf(" kuti");
            N = N%10000000;
        }
        banglaNumber(N);
        printf("\n");
    }

    return 0;
}