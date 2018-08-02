#include <conio.h>
#include <bios.h>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <varargs.h>
#include <stdlib.h>


int screenptr;
int screen13();
int rect(rectx,recty,rectx1,recty1,rectcolor);
void cls13(cls1);
int getptr();

void refresh();


void main(){
	int c;
	int d;
	long l;
	long ll;
	char b=1;
int rectx;
int recty;
int rectx1;
int recty1;
int rectcolor;
	
	int t=screen13();
screenptr=getptr();

	cls13(15);
	
rectx=10;
recty=10;
rectx1=50;
recty1=50;
rectcolor=1;
for(c=0;c<14;c++){
	
rect(rectx,recty,rectx1,recty1,rectcolor);
rectx+=10;
recty+=10;
rectx1+=10;
recty1+=10;
rectcolor++;
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

int rect(rectx,recty,rectx1,recty1,rectcolor)
{
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
	
	int xxa;
	xx=rectx;
	yy=recty;
	xx1=rectx1;
	yy1=recty1;
	if (xx>319) xx=319;
	if (xx1>319) xx1=319;
	if (yy>199) yy=199;
	if (yy1>199) yy1=199;
	if (xx<0) xx=0;
	if (xx1<0) xx1=0;
	if (yy<0) yy=0;
	if (yy1<0) yy1=0;
	if (xx<=xx1 && yy<=yy1) {
		xxa=xx1-xx;
		if (xxa<1) xxa=1;
		yyy=yy1-yy;
		nx=320-xxa;
	
			
	xxx=yy*320+xx;
	ir=screenptr;
	movedata(__get_ds(),&ir,__get_cs(),0x80,2);
	ir=xxx;
	movedata(__get_ds(),&ir,__get_cs(),0x82,2);
	ir=xxa;
	movedata(__get_ds(),&ir,__get_cs(),0x84,2);
	ir=nx;
	movedata(__get_ds(),&ir,__get_cs(),0x86,2);
	ir=yyy;
	movedata(__get_ds(),&ir,__get_cs(),0x88,2);
	movedata(__get_ds(),&rectcolor,__get_cs(),0x8a,1);
	asm "push ds";
	asm "push cs";
	asm "pop ds";
	asm "mov di,[0x82]";
	asm "mov si,[0x86]";
	asm "mov dx,[0x8a]";
	asm "mov bx,[0x88]";
	asm "mov cx,[0x84]";
	asm "mov ax,[0x80]";
	asm "push ax";
	asm "pop es";
	asm "mov al,dl";
	asm "xor dx,dx";
	asm "push cx";
	asm "label4:";
	asm "pop cx";
	asm "push cx";
asm "label5:";
asm "cld";
asm "rep";
asm "stosb";
	asm "clc";
	asm "add di,si";
asm "dec bx";
asm "cmp bx,dx";
	asm "jnz label4";
	asm "pop ax";
	asm "pop ds";
			
			
		r=-1;
		
		
		}else{
			r=0;
			}
		
		return r;
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
