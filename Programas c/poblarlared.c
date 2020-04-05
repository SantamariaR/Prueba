/*queremos hacer una red cuadrada en la cual llenemos de manera aleatoria con 1 y 0*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define SEED 260868
#define N    3
#define PROB 0.5

double myrandom(double prob);

int main()
{
	int    i,j;
	double prob,r;
	int *red;
	red = (int*)malloc((N*N)*sizeof(int));

	prob=PROB;

	srand(SEED);

	for(i=0;i<N;i++)
    {
	   for(j=0;j<N;j++)
       {
          r=myrandom(prob);
	      
	      if(r<prob) *( red + (i*N + j) )=0;
	      
	      else     *( red + ( i*N + j ) )=1;
       

       printf("%i\t",*( red + (i*N) + j));

       }

       printf("\n");
    }

     return 1;
}


double myrandom(double prob)
{
	double r;

	r=(double)rand()/(double)RAND_MAX;

	return r;
}
