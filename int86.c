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
	printf("press key\n");
	t=getkey();
	
	printf("the key you press code:%i\n",t);

}

int getkey()
{
	union REGS r1;
	union REGS r;
	r.h.ah=0;
	int86(0x16,&r,&r1);
	return r1.x.ax;
	}



