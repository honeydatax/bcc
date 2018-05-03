#include <stdio.h>
int number1;
int number2;
int adds();

void main()

{
	
	int c;
	number1=100;
	number2=200;
	c=adds();
	printf("%d+%d=%d",number1,number2,c);
	
	}
	
	int adds(){
		
		return number1+number2;
		}
	