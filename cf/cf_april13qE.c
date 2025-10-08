#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);
        
        int a[200001];

        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }

        int max_sum = 0;

        for (int k = 0; k < n; ++k) {
            int current_sum = 0;

            for (int i = 0; i < n; ++i) {
                current_sum += (a[k] ^ a[i]);
            }

            if (current_sum > max_sum) {
                max_sum = current_sum;
            }
        }

        printf("%d\n", max_sum);
    }

    return 0; 
}
