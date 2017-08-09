#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void bisection(float xl, float xr){
     float tol, xm, err;
     int s=0;
     printf("Enter tolerance:\t");
     scanf("%f",&tol);
     do{
     xm = (xl+xr)/2;
     err= fabs((xr-xl)/xm);
     if ((cos(xl)-xl)*(cos(xm)-xm)>0){
                xl=xm;
                }
     else{
          xr=xm;
          }
     //printf("\nError: %f", err);
     //printf("\nNext step \n");
     s++;
     }while(err>tol);
     printf("\nx0=\t%f+\- %f\n",xm,tol);
     printf("Iteracions: %i\n",s);
     
}

int main(int argc, char *argv[])
{
  float x1=0, x2=1;
  bisection(x1,x2);
  int tab[1000];
  int i;
  for(i=0;i<1000;i++){
                      tab[i]=2*i;
                      }
  
  system("PAUSE");	
  return 0;
}
