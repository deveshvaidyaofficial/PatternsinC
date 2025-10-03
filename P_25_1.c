/*    A 
   B C 
  D E F 
 G H I J 
K L M N O */
#include <stdio.h>

int main() {
    int i, j, space;
    char ch;

    for(i = 1; i <= 4; i++) {
        for(space = 4; space > i; space--)
            printf(" ");
        ch = 'A';
        for(j = 1; j <= (2*i -1); j++) {
            printf("%c", ch);
            ch++;
        }
        printf("\n");
    }
    for(i = 3; i >= 1; i--) {
        for(space = 4; space > i; space--)
            printf(" ");
        ch = 'A';
        for(j = 1; j <= (2*i -1); j++) {
            printf("%c", ch);
            ch++;
        }
        printf("\n");
    }
    return 0;
}
#include <stdio.h>

int main() {
    int i, j, space;
    char ch;

    for(i = 1; i <= 4; i++) {
        for(space = 4; space > i; space--)
            printf(" ");
        ch = 'A';
        for(j = 1; j <= (2*i -1); j++) {
            printf("%c", ch);
            ch++;
        }
        printf("\n");
    }
    for(i = 3; i >= 1; i--) {
        for(space = 4; space > i; space--)
            printf(" ");
        ch = 'A';
        for(j = 1; j <= (2*i -1); j++) {
            printf("%c", ch);
            ch++;
        }
        printf("\n");
    }
    return 0;
}
#include <stdio.h>

int main() {
    int i, j, space;
    char ch;

    for(i = 1; i <= 4; i++) {
        for(space = 4; space > i; space--)
            printf(" ");
        ch = 'A';
        for(j = 1; j <= (2*i -1); j++) {
            printf("%c", ch);
            ch++;
        }
        printf("\n");
    }
    for(i = 3; i >= 1; i--) {
        for(space = 4; space > i; space--)
            printf(" ");
        ch = 'A';
        for(j = 1; j <= (2*i -1); j++) {
            printf("%c", ch);
            ch++;
        }
        printf("\n");
    }
    return 0;
}
