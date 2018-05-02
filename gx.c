#include <conio.h>
#include <bios.h>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <varargs.h>
#include <stdlib.h>



int screen13();

void main(){
	unsigned int c;
	char b=1;
	char *p=b;
	int t=screen13();
for (c=0;c<(300*200);c++){
movedata(__get_ds(),&p,0xA000,c,1);
}

}

int screen13()
{
	union REGS r1;
	union REGS r;
	r.h.ah=0;
	r.h.al=0x13;
	int86(0x10,&r,&r1);
	return r1.x.ax;
	}



