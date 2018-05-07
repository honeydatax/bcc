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
	int tt;
	long l;
	long ll;
	char b=15;
	
	int t=screen13();
	cls1=1;
cls13();
hlinex=320/2+1;
hlinex1=320/2-1;
hlinecolor=b;
for (c=0;c<200;c++)
{
	hliney=c;
	hliney1=c;
	if (c<100){
		hlinex=hlinex-1;
		hlinex1=hlinex1+1;
		}else{
			hlinex=hlinex+1;
		hlinex1=hlinex1-1;
			}
			hlines();
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
	char s[320];
	
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
		yyy=yy1-yy;
		for (xxx=0;xxx<xxa;xxx++){
			s[xxx]=hlinecolor;
			}
			xxx=yy*320+xx;
			movedata(__get_ds(),&s[0],0xA000,xxx,xxa);
		r=-1;
		
		
		}else{
			r=0;
			}
		
		return r;
	}


int rect()
{
	int c;
	int xx ;
int yy;
int xx1;
int yy1;
int xxx;
int yyy;
int xxa;
int r;
	xx=rectx;
	yy=recty;
	yy1=recty1;
	xx1=rectx1;

	if (yy>199) yy=199;
	if (yy1>199) yy1=199;
	if (yy<0) yy=0;
	if (yy1<0) yy1=0;
	if (yy<=yy1) {

hlinex=xx;
hlinex1=xx1;
hlinecolor=rectcolor;

for(c=yy;c<=yy1;c++){
	
hliney=c;
hliney1=c;
hlines();
	
	}
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


