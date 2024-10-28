#include <stdio.h>

int main(int argc, char* argv[])
{
    if(argc<2){
        printf("Enter a char in CLI\n");
        return 1;
    }

    int rows = 5;

    // first outer loop to iterate through each row
    for (int i = 0; i < rows; i++) {

        // first inner loop to print white spaces
        for (int j = 0; j < rows - i - 1; j++) {
            printf(" ");
        }

        // second inner loop to print the specific chars in each row
        for (int k = 0; k < rows; k++) {
            printf("%c ", argv[1][0]);
        }
        printf("\n");
    }
    return 0;
}
