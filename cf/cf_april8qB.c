#include <stdio.h>
#include <string.h>
#include <math.h>
int isPrime(long long num){
    if (num <2) return 0;
    for (long long i=2;i * i <=num;++i){
        if (num % i ==0) return 0;
    }
    return 1;
}
int main (){
    int t;
    scanf("%d",&t);
    while (t--){
    long long x;
    int k;
    scanf("%lld %d",&x,&k);
    int digits=floor(log10(x))+1;
    if (digits * k <=18){
    long long y =0;
    long long multiplyer = pow(10,digits);
    for (int i=0;i<k;i++){
        y=y*multiplyer + x;
    }
    if (isPrime(y)){
        printf("YES\n");
    }
    else printf("NO\n");
    }else printf("NO\n"); 
    }
return 0;
}
