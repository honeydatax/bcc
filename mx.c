#include <stdio.h>
int number1;
int number2;
int max();

void main()

{
	
	int c;
	number1=100;
	number2=200;
	c=max();
	printf("max(%d,%d)=%d",number1,number2,c);
	
	}
	
	int max(){
		int r ;
		if ( number1>number2){
			r=number1;
			}else{
				r=number2;
				}
		return r;
		}
	