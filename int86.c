#include <conio.h>
#include <bios.h>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <varargs.h>
#include <stdlib.h>


int getkey();
void main(){
	
	int t;
	t=getkey();
	
	printf("%i",t);

}

int getkey()
{
	struct REGS r1;
	struct SREGS r;
	r1.h.ah=0;
	int86(0x16,&r,&r1);
	return r1.x.ax;
	}



