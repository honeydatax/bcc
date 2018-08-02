#include <stdio.h>

int min(number1,number2);

void main()

{
	
	int c;

	printf("min(10,20)=%d",min(10,20));
	
	}
	
	int min(number1,number2){
		int r ;
		if ( number1<number2){
			r=number1;
			}else{
				r=number2;
				}
		return r;
		}
	