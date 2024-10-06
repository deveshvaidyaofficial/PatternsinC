// C PROGRAM TO PRINT THE FLOYD'S TRIANGLE PATTERN
#include<stdio.h>
int main()
{
  int rows = 4;
  int n = 1;
      //OUTER LOOP TO PRINT ALL ROWS
for (int i = 0; i < rows; i++) {
          // INNER LOOP TO PRINT NUMBER IN EACH ROW 
        for (int j = 0; j <= i; j++) {
            printf("%d ", n++);
        }
        printf("\n");
}
  return 0;
}
