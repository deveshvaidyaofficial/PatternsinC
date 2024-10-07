#include<stdio.h>
int main()
{
int i,j;
for (i = 5; i >= 0; i--)
{
 for (j = 1; j <= i; j++)
 printf("%d",j);
 printf("\n");
}
for(int x = 1; x <= 5; x++)
{
 for(int y = 1; y <= x; y++)
 printf("%d",y);
 printf("\n");
}
}
