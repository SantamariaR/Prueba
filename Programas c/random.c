#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define SEED 260868 /* No tengo muy en claro para que usamos ésto*/
#define PROB 0.5
#define N    1000

double myrandom(double prob);

int main()
{
	int    i,low,high;
	double prob,r;

	low = 0;
	high= 0;

	prob=PROB;

	srand(SEED);

	for (i=0;i<N;i++)
	{
		r = myrandom(prob);

		if (r<prob) low++;
		else high++;
	}

	printf("prob.low=%lf\tprob.high=%lf\n",(double)low/(double)N,(double)high/(double)N);

return 1;
}

double myrandom(double prob)
{
	double r;

	r=(double)rand()/(double)RAND_MAX;

	return r;
}