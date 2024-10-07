/*
for n = 5 -

         * 

       *   * 

     *       * 

   *           * 

 * * * * * * * * * 

*/

#include <stdio.h>

void printHollowTraingle(int n){

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < 2 * (n - i) - 1; j++) {
            printf(" ");
        }

        for (int k = 0; k < 2 * i + 1; k++) {
            if (k == 0 || k == 2 * i || i == n - 1) {
                printf("*");
            } else {
                printf(" ");
            }
            printf(" ");
        }
        printf("\n");
    }
    
}

int main() {
    int n;
    scanf("%d", &n);
    printHollowTraingle(n);
    return 0;
}


