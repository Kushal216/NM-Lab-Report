//Program to implement bisection method
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float f(float x){
	return x*x-4*cos(x);
	}

int main(){
	int i=0;
	float a,b,c,E,Era;
	char sign;
	
	RESTART:
	printf("\nf(x)=x^2-4cos(x)\n\nEnter Two initial guesses for the function : ");
	scanf("%f%f",&a,&b);
	
	if(f(a)*f(b)>0){
		printf("\nYour guesses are not fit for bisection method please choose another two points : \n\n");
		goto RESTART;
		}
	
	printf("\nEnter the precision required : ");
	scanf("%f",&E);
	
	printf("Using Bisection Method : \n");
		
	printf("%-3c| %6c%5c %6c%5c %7s%4c %7s%4c %6c%5c %7s%4c %s\n",'k','a','|','b','|',"f(a)",'|',"f(b)",'|','c','|',"f(c)",'|',"f(a)*f(c)");
	do{		
		c=(a+b)/2;
		sign=((f(a)*f(c))<0)?'-':'+';
					
		printf("%-3d| %10f| %10f| %10f| %10f| %10f| %10f| %4c\n",i++,a,b,f(a),f(b),c,f(c),sign);
		
		if((f(a)*f(c))==0){
			c=(f(a))?c:a;
			break;
		}
				
		if(sign=='-')
			b=c;
		else
			a=c;
			
		Era=fabs((a-b)/b);	
		}	
		while(Era>E);
		
		printf("\nThe approximated value of the root of the given function is : \n x = %f ",c);
		
		
	printf("\n\nLab No. : 1(a)\nName : Sunil Bhattarai\nRoll No. : 63/080\tSection : B\n");	
	return 0;	
	}
