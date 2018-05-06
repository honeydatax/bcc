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
	char s[50];
	*print1=s;
strcpy(print1,"wait 5 seconds\0");

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
	
	for (i=0;i<1024;i++){
		if (print1[i]>6){
	r.h.ah=0xe;
	r.h.bh=0x0;
	r.h.bh=0x70;
	r.h.al=print1[i];
	

	int86(0x10,&r,&r1);
	}
	if (print1[i]<7)i=1024;
	
	}
	}