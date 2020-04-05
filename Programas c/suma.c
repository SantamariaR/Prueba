/*comentario*/
#include <stdio.h>

#include<math.h>  

#define MAX 1000 

int main()
{
	int i,suma;
	
	suma=0;
	
	for (i=0;i<MAX;i++)
	{
		suma = suma+ (i+1);
	}
	printf("\nla suma es: %d\n\n",suma);
	
	return 1;
}