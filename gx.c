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




int screen13();
int hlines();
int rect();

void main(){
	int c;
	char b=1;
	
	int t=screen13();
rectx=0;
recty=0;
rectx1=319;
recty1=199;
rectcolor=15;
rect();
hlinex=320/2;
hlinex1=320/2;
hlinecolor=b;

for(c=0;c<200;c=c+5){
hliney=c;
hliney1=c;
hlines();
hlinex=hlinex-2;
hlinex1=hlinex1+2;
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
	if (xx>299) xx=319;
	if (xx1>299) xx1=319;
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
