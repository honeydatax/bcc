#include <conio.h>
#include <bios.h>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <varargs.h>
#include <stdlib.h>

int hlinex;
int hliney;
int hlinex1;
int hliney1;
char hlinecolor;
int rectx;
int recty;
int rectx1;
int recty1;
char rectcolor;
char cls1;
int sleep1;


int screen13();
int hlines();
int rect();
void cls13();

void sleep();

void main(){
	int c;
	int d;
	long l;
	long ll;
	char b=1;
	
	int t=screen13();
rectx=0;
recty=0;
rectx1=319;
recty1=199;
rectcolor=15;
rect();
hlinex=0;
hlinex1=1;
hlinecolor=b;
l=0;
for(c=0;c<200;c++){
hliney=c;
hliney1=c;
hlines();
l=l+16;
ll=l/10;
d=ll;

hlinex1=d;
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

int hlines()
{

	int ir;
	int xx ;
int yy;
int xx1;
int yy1;
int xxx;
int yyy;
int r;
	
	int xxa;
	xx=hlinex;
	yy=hliney;
	xx1=hlinex1;
	yy1=hliney1;
	if (xx>319) xx=319;
	if (xx1>319) xx1=319;
	if (yy>199) yy=199;
	if (yy1>199) yy1=199;
	if (xx<0) xx=0;
	if (xx1<0) xx1=0;
	if (yy<0) yy=0;
	if (yy1<0) yy1=0;
	if (xx<=xx1 && yy==yy1) {
		xxa=xx1-xx;
		if (xxa<1) xxa=1;
		yyy=yy1-yy;
		
	
			
	xxx=yy*320+xx;
	ir=0xa000;
	movedata(__get_ds(),&ir,__get_cs(),0x80,2);
	ir=xxx;
	movedata(__get_ds(),&ir,__get_cs(),0x82,2);
	ir=xxa;
	movedata(__get_ds(),&ir,__get_cs(),0x84,2);
	movedata(__get_ds(),&hlinecolor,__get_cs(),0x86,1);
	asm "push ds";
	asm "push cs";
	asm "pop ds";
	asm "mov bx,[0x82]";
	asm "mov dx,[0x86]";
	
	asm "mov cx,[0x84]";
	asm "mov ax,[0x80]";
	asm "push ax";
	asm "pop ds";
	asm "mov al,dl";
	asm "xor dx,dx";
asm "label2:";
asm "mov [bx],al";
asm "inc bx";
asm "dec cx";
asm "cmp cx,dx";
	asm "jnz label2";
	asm "pop ds";
			
			
		r=-1;
		
		
		}else{
			r=0;
			}
		
		return r;
	}


int rect()
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
	ir=0xa000;
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
	asm "pop ds";
	asm "mov al,dl";
	asm "xor dx,dx";
	asm "push cx";
	asm "label4:";
	asm "pop cx";
	asm "push cx";
asm "label5:";
asm "mov [di],al";
asm "inc di";
asm "dec cx";
asm "cmp cx,dx";
	asm "jnz label5";
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
		
void cls13()
{
	int i;
	i=0xa000;
	movedata(__get_ds(),&i,__get_cs(),0x80,2);
	i=320*200;
	movedata(__get_ds(),&i,__get_cs(),0x82,2);
	movedata(__get_ds(),&cls1,__get_cs(),0x84,1);
	asm "push ds";
	asm "push cs";
	asm "pop ds";
	asm "mov bx,[0x82]";
	asm "mov cx,[0x84]";
	asm "mov ax,[0x80]";
	asm "push ax";
	asm "pop ds";
	asm "mov al,cl";
	
asm "label1:";
asm "mov [bx],al";
asm "dec bx";
asm "cmp bx,0";
	asm "jnz label1";
	asm "pop ds";
	
	}


