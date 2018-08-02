#include <stdio.h>

int max(number1,number2);

void main()

{
	
	int c;

	printf("max(10,20)=%d",max(10,20));
	
	}
	
	int max(number1,number2){
		int r ;
		if ( number1>number2){
			r=number1;
			}else{
				r=number2;
				}
		return r;
		}
	