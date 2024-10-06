// C PROGRAM TO PRINT THE PASCAL'S TRIANGLE PATTERN
#include <stdio.h>
int main(){
int rows = 5;
//OUTER LOOP FOR ROWS
for(int i=1;i<= rows;i ++)
{
//INNER LOOP 1 FOR LEADING WHITE SPACES
for (int j = 0; j < rows - i; j++) {
printf(" ");
        }
        int C = 1; // coefficient
//INNER LOOP 2 FOR PRINTING NUMBERS
for (int k = 1; k <= i; k++) {
printf("%d ", C);
 C = C * (i - k) / k;
 }
printf("\n");
    }
return 0;
}

/* OUTPUT 
    1 
   1 1 
  1 2 1 
 1 3 3 1 
1 4 6 4 1 
*/
