#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);  
    
    while (t--) {
        int k;
        scanf("%d", &k);         
        if (k % 2 == 1)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}

