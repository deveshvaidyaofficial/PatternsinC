#include <stdio.h>

void diamond_pattern(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++)
            printf(" ");
        for (int k = 0; k <= i; k++)
            printf("* ");
        printf("\n");
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++)
            printf(" ");
        for (int k = 0; k < n - i; k++)
            printf("* ");
        printf("\n");
    }
}

int main() {
    int n = 5;
    diamond_pattern(n);
    return 0;
}

// Output:
//     * 
//    * * 
//   * * * 
//  * * * * 
// * * * * *
//  * * * *
//   * * *
//    * *
//     *
