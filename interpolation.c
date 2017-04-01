#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
   char line[50];
   int i,j,n, N_old, N_new,y; double x_old[20] ;
   double x_new[20],f_new[20], f_old[20],sum,pf;	/*pf correspoding to lambda*/
   FILE *inptr, *fptr;
   
   inptr= fopen("sample_data.dat", "r");
   fptr= fopen("interpolate.dat","w");
   fgets(line,sizeof(line), inptr);
   n=0;
   while(fgets(line,sizeof(line), inptr)!= NULL )
   {
      sscanf(line,"%lf %lf", &x_old[n],&f_old[n]);
      n++;
   }
   N_old= n;
   for(int m=1; m<n; m++)
   { printf("E= %lf \t cross section %lf \n ", x_old[m], f_old[m] ); }
   for ( y=0; y <=200 ; y +=2)
   {
   
   for( i=1; i<n ;i++ )
   {
      sum=0.0;
      pf=1.0;
    for( j=1;j<n; j++)
    {
      if( j!= i)
      pf *= (double )(y - x_old[j]) / ((double) x_old[i] - x_old[j] );
      
    } 
      sum += f_old[i]* pf;
     }
     fprintf(fptr,"%d \t %lf \n ", y, sum);
    
    }
     fclose(inptr);
     fclose(fptr);
    return(0);
    }
