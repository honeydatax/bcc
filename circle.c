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
void pixelset(pixelsetx,pixelsety,pixelsetcolor);

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
int xxx;	
int yyy;
int p;
int a;

xxx=0;
yyy=circler;


p=1-(yyy);
do{
pixelset(circlex+xxx,circley+yyy,circlecolor);	
pixelset(circlex+yyy,circley+xxx,circlecolor);	
pixelset(circlex+xxx,circley-yyy,circlecolor);	
pixelset(circlex+yyy,circley-xxx,circlecolor);	
pixelset(circlex-xxx,circley-yyy,circlecolor);	
pixelset(circlex-xxx,circley+yyy,circlecolor);	
pixelset(circlex-yyy,circley+xxx,circlecolor);	
pixelset(circlex-yyy,circley-xxx,circlecolor);	

if (p<0){
xxx=xxx+1;
yyy=yyy;
p=p+(2*xxx)+2;
}else

{
xxx=xxx+1;
yyy=yyy-1;
p=p+(2*(xxx-yyy))+1;
}



}while(xxx<yyy+1);




}


void pixelset(pixelsetx,pixelsety,pixelsetcolor){


	int ir;
	int xx ;
int yy;
int xx1;
int yy1;
int xxx;
int yyy;
int r;
	
	int xxa;
	xx=pixelsetx;
	yy=pixelsety;
	if (xx>319 && yy>199 && xx<0 && yy<0) goto pixelsetexit;
	
		
	
			
	xxx=yy*320+xx;
	ir=screenptr;
	movedata(__get_ds(),&ir,__get_cs(),0x80,2);
	ir=xxx;
	movedata(__get_ds(),&ir,__get_cs(),0x82,2);
	movedata(__get_ds(),&pixelsetcolor,__get_cs(),0x84,2);
	asm "push ds";
	asm "push cs";
	asm "pop ds";
	asm "mov di,[0x82]";
	asm "mov dx,[0x84]";
	asm "mov ax,[0x80]";
	asm "push ax";
	asm "pop ds";
	asm "mov al,dl";
	asm "xor dx,dx";


asm "mov [di],al";

	asm "pop ds";
pixelsetexit:			
;

		
		
		}



