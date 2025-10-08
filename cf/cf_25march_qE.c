#include<stdio.h>
int main (){
    int pair ++;
    int t;
    int gcd;
    int lcm;
    int pri
    scanf("%d",&t);
    while (t--){
        int n;
        scanf("%d",&n);
        for (int i=1;i<n;i++){
            for (int j=i+1;j<n;j++){
                for (int k=1;k<=i;k++ ){
		if ((i%k==0) && (i%k==0)){
			gcd = k;
		}
			}            
            
        for (int k=j;k<=(i*j);k++ ){
		if ((k%i==0) && (k%i==0)){
			lcm = k;
			break;
		}
			}
            pri=lcm/gcd;
            for (int q=2;i<pri;q++){
		if (numb%q==0){flag=1;break;}
	}
	if (flag ==1 ) {break;
	if (flag ==0 ) {
        pair++;
    }
            } 
        }
         


    }
return 0;
}
