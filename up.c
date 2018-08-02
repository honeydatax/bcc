#include <conio.h>
#include <bios.h>
#include <stdio.h>
#include <dos.h>
#include <varargs.h>
#include <stdlib.h>
#include <string.h>


int screenptr;
int screen13();
void cls13(cls1);
int getptr();
void refresh();
void pixelset(pixelsetx,pixelsety,pixelsetcolor);
void fillcircle(fillcirclex,fillcircley,fillcircler,fillcirclecolor);
void lineup(lineupx,lineupy,lineupx1,lineupy1,lineupcolor);
int hlines(hlinex,hliney,hlinex1,hliney1,hlinecolor);

void main(){
	int c;
	int d;
	long l;
	long ll;
	char *b="IM LOVE MARINA.";

int a;
int e;	
	int t=screen13();


screenptr=getptr();
	;
	cls13(4);
e=4;


for (a=10;a<300;a=a+50){
fillcircle(a,10,2,1);
}

for (a=40;a<300;a=a+50){
fillcircle(a,80,2,1);
}

for (a=10;a<300;a=a+50){
lineup(0,199,a,10,1);
}

for (a=40;a<300;a=a+50){
lineup(0,199,a,80,1);
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

int hlines(hlinex,hliney,hlinex1,hliney1,hlinecolor)
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
	ir=screenptr;
	movedata(__get_ds(),&ir,__get_cs(),0x80,2);
	ir=xxx;
	movedata(__get_ds(),&ir,__get_cs(),0x82,2);
	ir=xxa;
	movedata(__get_ds(),&ir,__get_cs(),0x84,2);
	movedata(__get_ds(),&hlinecolor,__get_cs(),0x86,1);
	asm "push ds";
	asm "push cs";
	asm "pop ds";
	asm "mov di,[0x82]";
	asm "mov dx,[0x86]";
	
	asm "mov cx,[0x84]";
	asm "mov ax,[0x80]";
	asm "push ax";
	asm "pop es";
	asm "mov al,dl";
	asm "xor dx,dx";

asm "label2:";
asm "cld";
asm "rep";
asm "stosb";
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

void fillcircle(fillcirclex,fillcircley,fillcircler,fillcirclecolor)
{
int xxx;	
int yyy;
int p;
int a;





xxx=0;
yyy=fillcircler;


p=1-(yyy);
do{
hlines(fillcirclex-xxx,fillcircley+yyy,fillcirclex+xxx,fillcircley+yyy,fillcirclecolor);	
hlines(fillcirclex-yyy,fillcircley+xxx,fillcirclex+yyy,fillcircley+xxx,fillcirclecolor);	
hlines(fillcirclex-xxx,fillcircley-yyy,fillcirclex+xxx,fillcircley-yyy,fillcirclecolor);	
hlines(fillcirclex-yyy,fillcircley-xxx,fillcirclex+yyy,fillcircley-xxx,fillcirclecolor);	




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



void lineup(lineupx,lineupy,lineupx1,lineupy1,lineupcolor){
int xxx1;
int yyy1;
int xxx;
int yyy;
int xx;
int yy;
int xx1;
int yy1;
int diferent;
int n;
int m;
long l1;
long l2;
long l3;
long l4;

xx=lineupx;
yy=lineupy;
xx1=lineupx1;
yy1=lineupy1;

xxx1=xx;
yyy1=yy;

xxx=xx1-xx;
yyy=yy-yy1;
diferent=xxx;
if (xxx<yyy) diferent=yyy;
l1=1000;
l2=1000;

if (xxx<yyy){
l1=xxx;
l1=l1*1000;
l3=yyy;
l1=l1/l3;
}
if (xxx>yyy){
l2=yyy;
l2=l2*1000;
l3=xxx;
l2=l2/l3;
}


l3=0;
l4=0;
if(xxx>-1 && yyy>-1){
pixelset(xxx1,yyy1,lineupcolor);
for (n=0;n<diferent;n++){
l3=l3+l1;
l4=l4+l2;
if (l3>1000){
l3=l3-1000;
xxx1++;
}
if (l4>1000){
l4=l4-1000;
yyy1--;
}

pixelset(xxx1,yyy1,lineupcolor);

}
}

}


