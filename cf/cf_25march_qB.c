#include <stdio.h>
int main (){
    int t;
    scanf("%d",&t);
    while (t--){
        int n,x;
        scanf("%d",&n);
        scanf("%d",&x);
        int a[n];
        for (int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        int sep=0,rem=0,rems=0;
        int remy[n];
        for (int i=0;i<n;i++){
            remy[i]=0;
        }
        for (int i=0;i<n;i++){
            if (a[i]>=x){sep++;}
            else {remy[i]=a[i];
                    rem++;
                }
        }
    
        for (int i=0;i<rem+1;i++){
            rems+=remy[i];
        }
        if (rems>x){
            printf("%d",sep+1);
        }
        else {
            printf("%d",sep);
        }}
return 0;
}
