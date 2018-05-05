#include <stdio.h>
#include <bios.h>
#include <dos.h>
#include <conio.h>

int sleep1;
void sleep();
void main(){
	int c;
	printf("wait 5 seconds");
	sleep1=5*18;
	sleep();
	
	}
	
	void sleep(){
		unsigned long i;
		unsigned long ii;
		unsigned long iii;
		iii=(long) sleep1;
		movedata(0x40,0x6c,__get_ds(),&i,4);
		i=iii+i;
		do
		{
			movedata(0x40,0x6c,__get_ds(),&ii,4);
			}while (ii<i) ;
	
		
		
		}