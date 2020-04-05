/*Vamos a identificar grupos de clusters en una tira de NxN.
Voy a usar el programita poblarlared2 para generar la matriz de unos y ceros.
Creo que no me reconoce las funciones min y max*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define SEED 260868 /*no tengo muy en claro ésto*/
#define N    3
#define PROB 0.5

double myrandom(double prob);

int minimo(int s1,int s2);

int maximo(int s1,int s2);

int main()
{
	int    i,s,s1,s2,frag,min,max;
	
	double prob,r;
	
	int *red,*clase;
	
	s =0;

	s1=0;

	s2=0;
	
	red  = (int*)malloc((N*N)*sizeof(int));
	
	clase= (int*)malloc((N*N)*sizeof(int));

    prob=PROB;

	srand(SEED);

	for(i=0;i<N*N;i++) /*generamos la tira de 1 y 0*/
    {
        r=myrandom(prob);
	      
	    if(r<prob) *( red + i )=0;
	      
	    else       *( red + i )=1;
       

        printf("%i",*( red + i ));
    }
    
  
     for(i=0;i<N;i++)
     {
        
        if (s) /*funcion actualizar*/
        {
    
         while (*(clase+s)<0) 

         s=-(*(clase+s));
    
         *(red+i)=s;
    
         *(clase+s)=s;
        }
       
        else
        {
         *(red+i)=frag;
       
         *(clase+frag)=frag; /* por seguridad!*/
       
         frag++;
        }

       /*funcion etiqueta_falsa*/
     
       s1= *(red + i - N); /*vecino de arriba*/

       s2= *(red + i - 1); /*vecino de la izquierda*/

       while (*(clase+s1)<0) s1=-(*(clase+s1)); /*etiqueta s1 verdadera*/
     
       while (*(clase+s2)<0) s2=-(*(clase+s2)); /*etiqueta s2 verdadera*/
     
       min=minimo(s1,s2);
     
       max=maximo(s1,s2);
     
       *(red+i)=min;
     
       *(clase+min)=min;
     
       if (min<max) *(clase+max)=-min; 
     
       else *(clase+max)=min;    
     
     } 
     
     /*Repasa toda la tira corrigiendo los valores incorrectos*/
     
       for(i=0;i<N*N;i++)
      {
         s=*(red+i);
         
         while (*(clase+s)<0) 

         	s=-(*(clase+s));
            
            *(red+i)=*(clase+s);
      
      }
   
             printf("%i\n",*( clase + s ));

      return 1;
}

int minimo(int s1,int s2)
{
   int min;

   min=(int) min(int s1,int s2);

   return min;
}

int maximo(int s1,int s2)
{
   int max;

   max=(int) max(int s1,int s2);

   return max;
}

double myrandom(double prob)
{
	double r;

	r=(double)rand()/(double)RAND_MAX;

	return r;
}
