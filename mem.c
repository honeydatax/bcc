#include <stdio.h>
#include <bios.h>
#include <dos.h>
#include <conio.h>
#include <string.h>

long address1;
long address2;
long size;
void moves();

void main()
{
	long l;
	
	char ss[50];
	char *s="i m   l o v e   m a r i n a .          ";
	l=(long)&ss;
	strcpy(ss,s);
	address1=__get_ds();
	address1=address1<<4;
	address1=address1+l;
	address2=0xb800;
	address2=address2<<4;
	address2=address2+160*4;
	size=32;
	moves();
	}
	
	
void moves(){
	long l;
	long ll;
	

	l=address1;
	movedata(__get_ds(),&l,__get_cs(),0x80,4);
	l=address2;
	movedata(__get_ds(),&l,__get_cs(),0x84,4);
	l=size;
	movedata(__get_ds(),&l,__get_cs(),0x88,4);
	asm "push ds";
	asm "push cs";
	asm "pop ds";
	asm "mov edi,[0x84]";
	asm "mov ecx,[0x88]";
	asm "mov esi,[0x80]";
	asm "xor dx,dx";
	
	asm "push dx";
	asm "pop ds";
	asm "xor edx,edx";

asm "label9:";
asm "mov al,[esi]";
asm "mov [edi],al";
asm "inc esi";
asm "inc edi";
asm "dec ecx";
asm "cmp ecx,edx";
	asm "jnz label9";
	asm "pop ds";
	
	
     
    
	
	
	}
	
	
	