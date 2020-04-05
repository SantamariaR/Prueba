/*va a ser una fila con N*N columnas*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define SEED 260868 /*no tengo muy en claro ésto*/
#define N    3
#define PROB 0.5

double myrandom(double prob);

int main()
{
	int    i;
	double prob,r;
	int *red;
	red = (int*)malloc((N*N)*sizeof(int));

	prob=PROB;

	srand(SEED);

	for(i=0;i<N*N;i++)
    {
          r=myrandom(prob);
	      
	      if(r<prob) *( red + i )=0;
	      
	      else       *( red + i )=1;
       

       printf("%i",*( red + i ));

    }

     return 1;
}


double myrandom(double prob)
{
	double r;

	r=(double)rand()/(double)RAND_MAX;

	return r;
}