#include <stdio.h>
int number1;
int number2;
int min();

void main()

{
	
	int c;
	number1=100;
	number2=200;
	c=min();
	printf("min(%d,%d)=%d",number1,number2,c);
	
	}
	
	int min(){
		int r ;
		if ( number1<number2){
			r=number1;
			}else{
				r=number2;
				}
		return r;
		}
	