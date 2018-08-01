#include <stdio.h>
#include <bios.h>

int adds(addasm1,addasm2);
void main(){
	printf("10+10=%d\n",adds(10,10));
	}
	
	int adds(addasm1,addasm2){
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