#include <conio.h>
#include <bios.h>
#include <stdio.h>
#include <dos.h>
#include <varargs.h>
#include <stdlib.h>


int screenptr;
int screen13();
void cls13(cls1);
int getptr();
void refresh();
void circle(circlex,circley,circler,circlecolor);

void main(){
	int c;
	int d;
	long l;
	long ll;
	char b=1;
int a;	
	int t=screen13();
screenptr=getptr();

	cls13(4);

for (a=5;a<100;a=a+10){ 
circle(160,100,a,1);
} 
refresh();
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

void cls13(cls1)
{
	int i;
	i=screenptr;
	movedata(__get_ds(),&i,__get_cs(),0x80,2);
	i=320*200+1;
	movedata(__get_ds(),&i,__get_cs(),0x82,2);
	movedata(__get_ds(),&cls1,__get_cs(),0x84,1);
	asm "push ds";
	asm "push cs";
	asm "pop ds";
	asm "mov cx,[0x82]";
	asm "mov dx,[0x84]";
	asm "mov ax,[0x80]";
	asm "push ax";
	asm "pop es";
	asm "mov al,dl";
	asm "xor dx,dx";
	asm "mov di,dx";	
asm "label1:";
asm "cld";
asm "rep";
asm "stosb";
	
	asm "pop ds";
	
	}






	int getptr(){
		
		int r;
		
		asm "push ds";
		asm "push cs";
		asm "pop ds";
		asm "mov ax,ss";
		asm "mov [0x80],ax";
		asm "pop ds";
		
	    movedata(__get_cs(),0x80,__get_ds(),&r,2);
		return r+0x2000;
		
		}

void refresh()
{
	int i;
i=0xa000;

	movedata(__get_ds(),&i,__get_cs(),0x80,2);
	i=320*200+1;
	movedata(__get_ds(),&i,__get_cs(),0x82,2);
	i=screenptr;
	movedata(__get_ds(),&i,__get_cs(),0x84,2);
	asm "push ds";
	asm "push cs";
	asm "pop ds";
	asm "mov bx,[0x84]";
	asm "mov cx,[0x82]";
	asm "mov ax,[0x80]";
	asm "push ax";
	asm "pop es";
	asm "push bx";
	asm "pop ds";
	asm "xor dx,dx";
	asm "mov si,dx";
	asm "mov di,dx";
	asm "mov al,cl";
	
asm "label10:";
asm "cld";
asm "rep";
asm "movsb";
	asm "pop ds";
	
	}


void circle(circlex,circley,circler,circlecolor){

	int ir;
	int ny;
	int nx;
	int xx ;
int yy;
int xx1;
int yy1;
int xxx;
int yyy;
int r;
int n1;
int n2;
int n3;
int n4;
	
	int xxa;
	xx=circlex;
	yy=circley;
	xx1=circler;
	yy1=circlecolor;

	ir=screenptr;
	movedata(__get_ds(),&ir,__get_cs(),0x80,2);
	ir=xx;
	movedata(__get_ds(),&ir,__get_cs(),0x82,2);
	ir=yy;
	movedata(__get_ds(),&ir,__get_cs(),0x84,2);
	ir=xx1;
	movedata(__get_ds(),&ir,__get_cs(),0x86,2);
	ir=yy1;
	movedata(__get_ds(),&ir,__get_cs(),0x88,2);
	ir=-1;
	movedata(__get_ds(),&ir,__get_cs(),0x8a,2);
	ir=0;
	movedata(__get_ds(),&ir,__get_cs(),0x8c,2);
	ir=199;
	movedata(__get_ds(),&ir,__get_cs(),0x8e,2);
	ir=200;
	movedata(__get_ds(),&ir,__get_cs(),0x90,2);
	ir=319;
	movedata(__get_ds(),&ir,__get_cs(),0x92,2);
	ir=320;
	movedata(__get_ds(),&ir,__get_cs(),0x94,2);
	ir=24;
	movedata(__get_ds(),&ir,__get_cs(),0x96,2);
	ir=50;
	movedata(__get_ds(),&ir,__get_cs(),0x98,2);



	asm "push bp";
	asm "push es";
	asm "push ds";
	asm "push cs";
	asm "pop ds";
/* get stask point */
	asm "mov si,sp";
	asm "mov bp,sp";

/* load data to stack */
	asm "mov ax,[0x80]";
	asm "push ax";
	asm "mov ax,[0x82]";
	asm "push ax";
	asm "mov ax,[0x84]";
	asm "push ax";
	asm "mov ax,[0x86]";
	asm "push ax";
	asm "mov ax,[0x88]";
	asm "push ax";
	asm "mov ax,[0x8a]";
	asm "push ax";
	asm "mov ax,[0x8c]";
	asm "push ax";
	asm "mov ax,[0x8e]";
	asm "push ax";
	asm "mov ax,[0x90]";
	asm "push ax";
	asm "mov ax,[0x92]";
	asm "push ax";
	asm "mov ax,[0x94]";
	asm "push ax";
	asm "mov ax,[0x96]";
	asm "push ax";
	asm "mov ax,[0x98]";
	asm "push ax";
	asm "clc";
	asm "sub bp,ax";
	asm "mov sp,bp";

	asm "mov ax,[bp+0x30]";
	asm "mov ds,ax";
	asm "mov es,ax";

	asm "mov bx,[bp+0x24]";
	asm "mov [bp+0x8],bx";
	asm "mov ax,[bp+0x2a]";
	asm "mov [bp+0xa],ax";
	asm "inc bx";
	asm "clc";
	asm "sub bx,ax";
	asm "mov [bp+0x6],bx";
	asm "label71:";

/* 0 +x +y */
	asm "mov ax,[bp+0x2e]";
	asm "mov bx,[bp+0x8]";
	asm "clc";
	asm "add ax,bx";
	asm "mov [bp+0x0],ax";
	asm "mov ax,[bp+0x2c]";
	asm "mov bx,[bp+0xa]";
	asm "clc";
	asm "add ax,bx";
	asm "mov [bp+0x2],ax";
	asm "call label80";

/*1 +y +x */

	asm "mov ax,[bp+0x2e]";
	asm "mov bx,[bp+0xa]";
	asm "clc";
	asm "add ax,bx";
	asm "mov [bp+0x0],ax";
	asm "mov ax,[bp+0x2c]";
	asm "mov bx,[bp+0x8]";
	asm "clc";
	asm "add ax,bx";
	asm "mov [bp+0x2],ax";
	asm "call label80";
	asm "jmp label79";
	asm "label90:";
	asm "jmp label71";
	asm "label79:";

/*2 +x -y */


	asm "mov ax,[bp+0x2e]";
	asm "mov bx,[bp+0x8]";
	asm "clc";
	asm "add ax,bx";
	asm "mov [bp+0x0],ax";
	asm "mov ax,[bp+0x2c]";
	asm "mov bx,[bp+0xa]";
	asm "clc";
	asm "sub ax,bx";
	asm "mov [bp+0x2],ax";
	asm "call label80";

/*3 +y -x */

	asm "mov ax,[bp+0x2e]";
	asm "mov bx,[bp+0xa]";
	asm "clc";
	asm "add ax,bx";
	asm "mov [bp+0x0],ax";
	asm "mov ax,[bp+0x2c]";
	asm "mov bx,[bp+0x8]";
	asm "clc";
	asm "sub ax,bx";
	asm "mov [bp+0x2],ax";
	asm "call label80";

/*4 +x +y */
	asm "mov ax,[bp+0x2e]";
	asm "mov bx,[bp+0x8]";
	asm "clc";
	asm "sub ax,bx";
	asm "mov [bp+0x0],ax";
	asm "mov ax,[bp+0x2c]";
	asm "mov bx,[bp+0xa]";
	asm "clc";
	asm "sub ax,bx";
	asm "mov [bp+0x2],ax";
	asm "call label80";
	asm "jmp label92";
	asm "label94:";
	asm "jmp label90";
	asm "label92:";

/*5 -x +y */
	asm "mov ax,[bp+0x2e]";
	asm "mov bx,[bp+0x8]";
	asm "clc";
	asm "sub ax,bx";
	asm "mov [bp+0x0],ax";
	asm "mov ax,[bp+0x2c]";
	asm "mov bx,[bp+0xa]";
	asm "clc";
	asm "add ax,bx";
	asm "mov [bp+0x2],ax";
	asm "call label80";

/*6 -y +x */
	asm "mov ax,[bp+0x2e]";
	asm "mov bx,[bp+0xa]";
	asm "clc";
	asm "sub ax,bx";
	asm "mov [bp+0x0],ax";
	asm "mov ax,[bp+0x2c]";
	asm "mov bx,[bp+0x8]";
	asm "clc";
	asm "add ax,bx";
	asm "mov [bp+0x2],ax";
	asm "call label80";

/*7 -y -x */

	asm "mov ax,[bp+0x2e]";
	asm "mov bx,[bp+0xa]";
	asm "clc";
	asm "sub ax,bx";
	asm "mov [bp+0x0],ax";
	asm "mov ax,[bp+0x2c]";
	asm "mov bx,[bp+0x8]";
	asm "clc";
	asm "sub ax,bx";
	asm "mov [bp+0x2],ax";
	asm "call label80";


	asm "mov bx,[bp+0x8]";
	asm "mov ax,[bp+0x24]";
	asm "inc ax";
	asm "clc";
	asm "add bx,ax";
	asm "mov [bp+0x8],bx";

	asm "mov bx,[bp+0x6]";
	asm "mov dx,[bp+0x24]";
	asm "cmp bx,dx";
	asm "jl label75";
	asm "jmp label72";
	asm "label76:";
	asm "jmp label94";
	asm "label75:";
	asm "mov bx,[bp+0x8]";
	asm "mov ax,bx";
	asm "clc";
	asm "add ax,bx";
	asm "mov bx,[bp+0x6]";
	asm "clc";
	asm "add bx,ax";
	asm "mov ax,[bp+0x24]";
	asm "inc ax";
	asm "inc ax";
	asm "clc";
	asm "add bx,ax";
	asm "mov [bp+0x6],bx";

	asm "jmp label73";
	asm "label72:";
	asm "mov bx,[bp+0x24]";
	asm "inc bx";
	asm "mov ax,[bp+0xa]";
	asm "clc";
	asm "sub ax,bx";
	asm "mov [bp+0xa],ax";
	asm "mov bx,[bp+0x8]";
	asm "clc";
	asm "sub bx,ax";
	asm "mov ax,bx";
	asm "clc";
	asm "add ax,bx";
	asm "mov bx,[bp+0x6]";
	asm "clc";
	asm "add bx,ax";
	asm "mov ax,[bp+0x24]";
	asm "inc ax";
	asm "clc";
	asm "add bx,ax";
	asm "mov [bp+0x6],bx";

	asm "label73:";
	asm "mov bx,[bp+0x24]";
	asm "inc bx";
	asm "mov ax,[bp+0xa]";
	asm "clc";
	asm "add ax,bx";
	asm "mov bx,ax";
	asm "mov ax,[bp+0x8]";
	asm "cmp ax,bx";
	asm "jl label76";
	asm "jmp label81";

	asm "label80:";
	asm "mov ax,[bp+0x0]";
	asm "mov bx,[bp+0x24]";
	asm "cmp ax,bx";
	asm "jl label82";
	asm "mov ax,[bp+0x2]";
	asm "cmp ax,bx";
	asm "jl label82";
	asm "mov bx,[bp+0x22]";
	asm "cmp ax,bx";
	asm "ja label82";
	asm "mov ax,[bp+0x0]";
	asm "mov bx,[bp+0x1e]";
	asm "ja label82";
	asm "mov ax,[bp+0x2]";
	asm "mov bx,[bp+0x1c]";
	asm "xor dx,dx";
	asm "xor cx,cx";
	asm "clc";
	asm "mul bx";
	asm "mov bx,[bp+0x0]";
	asm "clc";
	asm "add bx,ax";
	asm "mov al,[bp+0x28]";
	asm "mov [bx],al";
	asm "label82:";
	asm "ret";

	asm "label81:";
	asm "mov sp,si"; /*restore sp */

	asm "pop ds"; /* restore var from return */
	asm "pop es";
	asm "pop bp";			



	}







