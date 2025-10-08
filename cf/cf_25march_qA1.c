#include <stdio.h>

int main() {
    char target[] = "01032025";
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);
        int digits[n];

        for (int i = 0; i < n; i++) {
            scanf("%d", &digits[i]);
        }

        int ti = 0;
        for (int i = 0; i < n; i++) {
            if (digits[i] == target[ti] - '0') {
                ti++;
            }
            if (ti == 8) {
                printf("YES\n");
                goto next_case;
            }
        }
        printf("NO\n");

    next_case:;
    }

    return 0;
}

