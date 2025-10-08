#include <stdio.h>
int main(){
    char target[]="01032025";
    int t;
    scanf("%d",&t);
    //printf("enter the number of digits to pull out\n");
    for (int k = 0; k < t; k++){
    int n;
    scanf("%d",&n);
    int digits[n];
    //printf("enter the number of digits to check\n");
    for (int i=0;i<n;i++){
        scanf("%d",&digits[i]);
    }
    int ti=0;
    for (int i=0;i<n;i++){
        if (digits[i]==target[ti]-'0'){
            ti++;
        }
        if (ti==8){
            printf("%d\n",i+1);
            break;
        }
    }
    if (ti!=8){
        printf("0\n");
    }
}
return 0;
}
