#include <stdio.h>
int main()
{
int i,j,k;
for(i=5;i>=1;i--)
{
for(j=1;j<=5;j++)
{
if(j<=i)
printf("%c",'A' + j-1);
else
printf(" ");
}
for(j=4;j>=1;j--)
{
if(j<=i)
printf("%c",'A' + j-1);
else
printf(" ");
} 
printf("\n");
	}
}	
/*OUTPUT 
ABCDEDCBA
ABCD DCBA
ABC   CBA
AB     BA
A       A
*/
