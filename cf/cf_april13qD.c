#include <stdio.h>
#include <string.h>

void solve(char *p, char *s) {
    int i = 0, j = 0;
    int len_p = strlen(p);
    int len_s = strlen(s);

    while (i < len_p && j < len_s) {
        if (s[j] == p[i]) {
            // Match 1 character
            j++;
        } else if (j + 1 < len_s && s[j] == s[j + 1] && s[j] == p[i]) {
            // Match 2 characters
            j += 2;
        } else {
            // If no valid match found
            printf("NO\n");
            return;
        }
        i++;
    }

    // After matching all of p, s must also be fully used
    if (i == len_p && j == len_s) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}

int main() {
    int t;
    scanf("%d", &t);  // Number of test cases

    char p[200005], s[200005];

    while (t--) {
        scanf("%s", p);  // Input the pattern string
        scanf("%s", s);  // Input the sound string
        solve(p, s);     // Solve for each test case
    }

    return 0;
}

