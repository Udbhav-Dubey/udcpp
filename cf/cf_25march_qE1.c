#include <stdio.h>

int gcd(int a, int b) {
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int is_prime(int num) {
    if (num < 2) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n, pair = 0;
        scanf("%d", &n);

        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                int g = gcd(i, j);
                int l = (i / g) * j;  // Optimized LCM calculation
                int pri = l / g;

                if (is_prime(pri)) {
                    pair++;
                }
            }
        }
        printf("%d\n", pair);
    }

    return 0;
}

