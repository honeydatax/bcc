#include <stdio.h>
#include <bios.h>
#include <dos.h>
#include <conio.h>


int sound1;
int sound2;
int delay1;
void delay();
void sounds();

void main(){
	int c;
	
	sound1=523;
	sound2=16;
	sounds();
	sound1=587;
	sounds();
	sound1=659;
	sounds();
	sound1=689;
	sounds();
	sound1=784;
	sounds();
	sound1=880;
	sounds();
	sound1=988;
	sounds();
	sound1=1046;
	sounds();
	
	}
	
void delay(){
	unsigned long l;
	unsigned long ll;
	unsigned long lll;
	
	int i;
	lll=(long) delay1;
	i=0x40;
	movedata(__get_ds(),&i,__get_cs(),0x80,2);
	    asm "push ds";
	asm  "push cs";
		asm "pop ds";
		asm "mov ax,[0x80]";
		asm "mov ds,ax";
		
		asm "mov ax, [0x6C]";
		asm "push ax";
		asm "mov ax, [0x6E]";
		asm  "push cs";
		asm "pop ds";
		asm "mov [0x82],ax";
		asm "pop ax";
		asm "mov [0x80],ax";
		
		asm "pop ds";
	movedata(__get_cs(),0x80,__get_ds(),&l,4);
	l=l+lll;
	do{
	i=0x40;
	movedata(__get_ds(),&i,__get_cs(),0x80,2);
	    asm "push ds";
	asm  "push cs";
		asm "pop ds";
		asm "mov ax,[0x80]";
		asm "mov ds,ax";
		
		asm "mov ax, [0x6C]";
		asm "push ax";
		asm "mov ax, [0x6E]";
		asm  "push cs";
		asm "pop ds";
		asm "mov [0x82],ax";
		asm "pop ax";
		asm "mov [0x80],ax";
		
		asm "pop ds";
	movedata(__get_cs(),0x80,__get_ds(),&ll,4);
	}
	while (ll<l) ;
	}
	
	void sounds(){
		int r;
		long f1;
		long f2;
		int i1;
		int i2;
		int i;
		 f1 = 1193181 /sound1;
		f2=f1;
		f1=f1 & 0xffff0000;
		f1=f1>>16;
		f2=f2 & 0xffff;
		i1=(int) f1;
		i2=(int)f2;
		
		movedata(__get_ds(),&i1,__get_cs(),0x80,2);
		movedata(__get_ds(),&i2,__get_cs(),0x82,2);
		
	i=0x61;
	movedata(__get_ds(),&i,__get_cs(),0x84,2);
	i=0x43;
	movedata(__get_ds(),&i,__get_cs(),0x86,2);
	i=0xb6;
	movedata(__get_ds(),&i,__get_cs(),0x88,2);
	i=3;
	movedata(__get_ds(),&i,__get_cs(),0x8a,2);
	i=0xfc;
	movedata(__get_ds(),&i,__get_cs(),0x8c,2);
		asm "push ds";
		
		asm "push cs";
		asm "pop ds";
		
		asm "mov dx,[0x84]";
		asm "mov ah,[0x8a]";
		asm "in al,dx";
		
		asm "or al,ah";
		asm "out dx,al";
		asm "mov dx,[0x86]";
		asm "mov al,[0x88]";
		asm "out dx,al";
		asm "dec dx";
		asm "mov ax,[0x82]";
		asm "out dx,al";
		asm "mov al,ah";
		asm "out dx,al";
		asm "pop ds";
		
		delay1=sound2;
		delay();
		
		i=0x61;
	movedata(__get_ds(),&i,__get_cs(),0x84,2);
	i=0x43;
	movedata(__get_ds(),&i,__get_cs(),0x86,2);
	i=0xb6;
	movedata(__get_ds(),&i,__get_cs(),0x88,2);
	i=3;
	movedata(__get_ds(),&i,__get_cs(),0x8a,2);
	i=0xfc;
	movedata(__get_ds(),&i,__get_cs(),0x8c,2);
		
		asm "push ds";
		asm "push cs";
		asm "pop ds";
		
	    asm "mov dx,[0x84]";
		asm "in al,dx";
		asm "and al,[0x8c]";
		asm "out dx,al";
		
		asm "pop ds";
		
		
		}