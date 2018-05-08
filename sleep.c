#include <stdio.h>
#include <bios.h>
#include <dos.h>
#include <conio.h>
#include <string.h>

int x;
int y;
char color;
int print1;
char cls1;
int sleep1;
void sleep();
void print();
void cls3();
void main(){
	int c;
	char ss[50];
	char *s="wait 5 seconds";
	strcpy(ss,s);
	
	print1=&ss;
	cls1=0x17;
	color=cls1;
cls3();
x=0;
y=0;
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
			
			int i;
	i=0xb800;
	movedata(__get_ds(),&i,__get_cs(),0x80,2);
	i=(y*80+x)*2;
	movedata(__get_ds(),&i,__get_cs(),0x82,2);
	i=(int)color;
	i=i<<8;
	i=i+32;
	movedata(__get_ds(),&i,__get_cs(),0x84,2);
	i=print1;
	movedata(__get_ds(),&i,__get_cs(),0x86,2);
	i=__get_ds();
	movedata(__get_ds(),&i,__get_cs(),0x88,2);
	asm "push ds";
	asm "push cs";
	asm "pop ds";
	asm "mov di,[0x82]";
	asm "mov si,[0x86]";
	asm "mov dx,[0x84]";
	asm "mov cx,[0x88]";
	asm "mov ax,[0x80]";
	asm "push ax";
	asm "pop ds";
	asm "xor dl,dl";
	
	asm "mov ah,dh";

asm "label8:";
asm "push ds";
asm "mov ds,cx";
asm "mov al,[si]";
asm "pop ds";
asm "mov [di],ax";
asm "inc si";
asm "inc di";
asm "inc di";
asm "cmp al,dl";
	asm "jnz label8";
	asm "pop ds";
	
	
	}
	
	void cls3()
{
	int i;
	i=0xb800;
	movedata(__get_ds(),&i,__get_cs(),0x80,2);
	i=80*25*2-2;
	movedata(__get_ds(),&i,__get_cs(),0x82,2);
	i=(int)cls1;
	i=i<<8;
	i=i+32;
	movedata(__get_ds(),&i,__get_cs(),0x84,2);
	asm "push ds";
	asm "push cs";
	asm "pop ds";
	asm "mov bx,[0x82]";
	asm "mov cx,[0x84]";
	asm "mov ax,[0x80]";
	asm "push ax";
	asm "pop ds";
	asm "xor dx,dx";
	asm "dec dx";
	asm "dec dx";
	asm "mov ax,cx";

asm "label1:";
asm "mov [bx],ax";
asm "dec bx";
asm "dec bx";
asm "cmp bx,dx";
	asm "jnz label1";
	asm "pop ds";
	
	}

	
	
	