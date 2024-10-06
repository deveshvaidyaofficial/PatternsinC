#include <stdio.h>

void pyramid_pattern(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++)
            printf(" ");
        for (int k = 0; k <= i; k++)
            printf("* ");
        printf("\n");
    }
}

int main() {
    int n = 5;
    pyramid_pattern(n);
    return 0;
}
