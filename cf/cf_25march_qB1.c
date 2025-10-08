#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, x;
        scanf("%d %d", &n, &x);
        int a[n];

        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        qsort(a, n, sizeof(int), compare);

        int sep = 0, rem = 0;

        for (int i = n - 1; i >= 0; i--) {
            rem++;
            if (a[i] * rem >= x) {  
                sep++;
                rem = 0;
            }
        }

        printf("%d\n", sep);
    }
    return 0;
}
