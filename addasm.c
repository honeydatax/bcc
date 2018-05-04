#include <stdio.h>
#include <bios.h>

int addasm1;
int addasm2;
int adds();
void main(){
	int c;
	addasm1=100;
	addasm2=200;
	c=adds();
	printf("%d+%d=%d\n",addasm1,addasm2,c);
	}
	
	int adds(){
		int r;
		
		movedata(__get_ds(),&addasm1,__get_cs(),0x80,2);
		movedata(__get_ds(),&addasm2,__get_cs(),0x82,2);
		asm "push ds";
		asm "push cs";
		asm "pop ds";
		asm "mov ax,[0x80]";
		asm "mov cx,[0x82]";
		asm "add ax,cx";
		asm "mov [0x80],ax";
		asm "pop ds";
		
	    movedata(__get_cs(),0x80,__get_ds(),&r,2);
		
		return r;
		}