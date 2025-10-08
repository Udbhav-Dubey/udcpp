#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <float.h>
int main (){
int t;
scanf("%d",&t);
while (t--){
    char s[105];
    scanf("%s",s);
    int n=strlen(s);
    double min_cost=DBL_MAX;
    int max_len=1;
    for (int i=0;i<n;i++){
        long long val=0;
        int sum=0;
        for (int j=i;j<n;j++){
            val=val * 10 + (s[j]-'0');
            sum +=(s[j]-'0');
        
        if (sum==0)continue;
        double cost=(double)val/sum;
        if (cost<min_cost){
            min_cost=cost;
            max_len=j-i+1;
        }
    }
}
printf("%d\n",n-max_len);
}
return 0;
}

