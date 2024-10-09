#include <stdio.h>
int main()
{
    int rows = 4;
    for (int i = 0; i < rows; i++) {
        for (int k = 0; k <= 2*i; k++) {
            printf(" * ");
        }
        printf("\n");
    }
    return 0;
}
/* OUTPUT FOR THE CODE 
 * 
 *  *  *
 *  *  *  *  *
 *  *  *  *  *  *  *
*/
