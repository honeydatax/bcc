#include <stdio.h>
#include <bios.h>
#include <dos.h>
#include <conio.h>
#include <string.h>

char *print1;
int sleep1;
void sleep();
void print();
void main(){
	int c;
	
	print1="wait 5 seconds\n$\0\0";

	print();
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
		
		
		void print(){
			
			union REGS r1;
	union REGS r;
	int i;
	int ii;
	
	

	r.h.ah=0x9;
	
	r.x.dx=&print1[0];
	
	int86(0x21,&r,&r1);
	
	}