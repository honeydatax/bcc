#include <conio.h>
#include <bios.h>
#include <stdio.h>
#include <dos.h>
#include <varargs.h>
#include <stdlib.h>
#include <string.h>

int x;
int y;
char color;
int draw1;
char cls1;
int sleep1;
int number1;
int number2;
int sound1;
int sound2;

int pixelsetx;
int pixelsety;
int pixelsetcolor;
int screenptr;
int hlinex;
int hliney;
int hlinex1;
int hliney1;
char hlinecolor;
int rectx;
int recty;
int rectx1;
int recty1;
int rectsx;
int rectsy;
int rectsx1;
int rectsy1;
char rectscolor;
int circlex;
int circley;
int circler;
int circlecolor;
int fillcirclex;
int fillcircley;
int fillcircler;
int fillcirclecolor;
char rectcolor;
char cls1;
int sleep1;
int vlinex;
int vliney;
int vlinex1;
int vliney1;
char vlinecolor;
int drawtextx;
int drawtexty;
char drawtextcolor;
char *drawtextvalue;
char drawcharvalue;
char drawcharcolor;
char drawcharback;
int linedownx;
int linedowny;
int linedownx1;
int linedowny1;
int linedowncolor;



long get_ttimer();
void sounds();
void draws();
int screen13();
int hlines();
int rect();
void cls13();
void getptr();
void sleep();
void refresh();
void pixelset();
void circle();
void fillcircle();
int vlines();
int drawtext();
int rects();
void linedown();


void main(){
	int c;
	int d;
	long l;
	long ll;
	char *b="IM LOVE MARINA.";

int a;
int e;	
	int t=screen13();


getptr();
	cls1=4;
	cls13();
e=4;
fillcirclecolor=1;
fillcircley=100;
for (a=10;a<300;a=a+50){
fillcirclex=a;
fillcircler=2;
fillcircle();

}

fillcircley=180;
for (a=40;a<300;a=a+50){
fillcirclex=a;
fillcircler=2;
fillcircle();

}

linedowncolor=1;
linedownx=0;
linedowny=0;
linedowny1=100;
for (a=10;a<300;a=a+50){
linedownx1=a;
linedown();
}

linedowny1=180;
for (a=40;a<300;a=a+50){
linedownx1=a;
linedown();
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


	long get_ttimer(){
		long i;
		movedata(0x40,0x6c,__get_ds(),&i,4);
		return  i;
		}
		
		int max(){
		int r ;
		if ( number1>number2){
			r=number1;
			}else{
				r=number2;
				}
		return r;
		}
	
	
	int min(){
		int r ;
		if ( number1<number2){
			r=number1;
			}else{
				r=number2;
				}
		return r;
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
		
		sleep1=sound2;
		sleep();
		
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

void draws(){
rectx=x-10;
recty=y-20;
rectx1=x+10;
recty1=y+20;
rectcolor=draw1;
rect();
rectx=x-20;
recty=y-10;
rectx1=x+20;
recty1=y+10;
rectcolor=draw1;
rect();


}




	void getptr(){
		
		int r;
		
		asm "push ds";
		asm "push cs";
		asm "pop ds";
		asm "mov ax,ss";
		asm "mov [0x80],ax";
		asm "pop ds";
		
	    movedata(__get_cs(),0x80,__get_ds(),&r,2);
		screenptr=r+0x2000;
		
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


void pixelset(){


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

void circle(){
int xxx;	
int yyy;
int p;
int a;

xxx=0;
yyy=circler;
pixelsetcolor=circlecolor;

p=1-(yyy);
do{
pixelsetx=circlex+xxx;
pixelsety=circley+yyy;
pixelset();	
pixelsetx=circlex+yyy;
pixelsety=circley+xxx;
pixelset();	
pixelsetx=circlex+xxx;
pixelsety=circley-yyy;
pixelset();	
pixelsetx=circlex+yyy;
pixelsety=circley-xxx;
pixelset();	
pixelsetx=circlex-xxx;
pixelsety=circley-yyy;
pixelset();	
pixelsetx=circlex-xxx;
pixelsety=circley+yyy;
pixelset();	
pixelsetx=circlex-yyy;
pixelsety=circley+xxx;
pixelset();	
pixelsetx=circlex-yyy;
pixelsety=circley-xxx;
pixelset();	

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

void fillcircle(){
int xxx;	
int yyy;
int p;
int a;





xxx=0;
yyy=fillcircler;
hlinecolor=fillcirclecolor;

p=1-(yyy);
do{
hlinex=fillcirclex-xxx;
hliney=fillcircley+yyy;
hlinex1=fillcirclex+xxx;
hliney1=fillcircley+yyy;
hlines();	

hlinex=fillcirclex-yyy;
hliney=fillcircley+xxx;
hlinex1=fillcirclex+yyy;
hliney1=fillcircley+xxx;
hlines();	

hlinex=fillcirclex-xxx;
hliney=fillcircley-yyy;
hlinex1=fillcirclex+xxx;
hliney1=fillcircley-yyy;
hlines();	

hlinex=fillcirclex-yyy;
hliney=fillcircley-xxx;
hlinex1=fillcirclex+yyy;
hliney1=fillcircley-xxx;
hlines();	




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


int vlines()
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
	xx=vlinex;
	yy=vliney;
	xx1=vlinex1;
	yy1=vliney1;

        if (xx>319) xx=319;
	if (xx1>319) xx1=319;
	if (yy>199) yy=199;
	if (yy1>199) yy1=199;
	if (xx<0) xx=0;
	if (xx1<0) xx1=0;
	if (yy<0) yy=0;
	if (yy1<0) yy1=0;
	if (xx==xx1 && yy<=yy1) {
		xxa=xx1-xx;
yyy=yy1-yy;		
if (yyy<1) yyy=1;
		
		
	
			
	xxx=yy*320+xx;
	ir=screenptr;
	movedata(__get_ds(),&ir,__get_cs(),0x80,2);
	ir=xxx;
	movedata(__get_ds(),&ir,__get_cs(),0x82,2);
	ir=yyy;

	movedata(__get_ds(),&ir,__get_cs(),0x84,2);
	ir=320;
	movedata(__get_ds(),&ir,__get_cs(),0x86,2);
	movedata(__get_ds(),&vlinecolor,__get_cs(),0x88,1);
	asm "push ds";
	asm "push cs";
	asm "pop ds";
	asm "mov di,[0x82]";
	asm "mov dx,[0x88]";
	asm "mov bx,[0x86]";	
	asm "mov cx,[0x84]";
	asm "mov ax,[0x80]";
	asm "push ax";
	asm "pop ds";
	asm "mov al,dl";
	asm "mov dx,bx";
	asm "xor bx,bx";

asm "label22:";

asm "mov [di],al";
asm "clc";
asm "add di,dx";
asm "dec cx";
asm "cmp cx,bx";
asm "jnz label22";
	asm "pop ds";
			
			
		r=-1;
		
		
		}else{
			r=0;
			}
		
		return r;
	}




int drawtext()
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
	xx=drawtextx;
	yy=drawtexty;
        if (xx>319) xx=319;

	if (yy>199) yy=199;

	if (xx<0) xx=0;

	if (yy<0) yy=0;

	if (xx<320/8 && yy<200/8) {
	

ir=xx;
	movedata(__get_ds(),&ir,__get_cs(),0x80,2);
	ir=yy;
	movedata(__get_ds(),&ir,__get_cs(),0x82,2);
	ir=0x13;
	movedata(__get_ds(),&ir,__get_cs(),0x84,2);
	ir=1;
	movedata(__get_ds(),&ir,__get_cs(),0x86,2);
	ir=0;
	movedata(__get_ds(),&ir,__get_cs(),0x88,2);
	ir=drawtextcolor;
	movedata(__get_ds(),&ir,__get_cs(),0x8a,2);
	ir=strlen(drawtextvalue);
	movedata(__get_ds(),&ir,__get_cs(),0x8c,2);

	movedata(__get_ds(),&drawtextvalue,__get_cs(),0x8e,2);



	asm "push es";
	asm "push ds";
	asm "push ds";
	asm "pop es";
	asm "push bp";
	asm "push di";
	asm "push si";

	asm "push cs";
	asm "pop ds";
	asm "mov dh,[0x80]";
	asm "mov dl,[0x82]";	
        asm "mov bh,[0x88]";	
        asm "mov bl,[0x8a]";
	asm "mov cx,[0x8c]";
	asm "mov ax,[0x8e]";
	asm "push ax";
	asm "pop bp";
	asm "mov ah,[0x84]";
	asm "mov al,[0x86]";



asm "int 0x10";
	asm "pop si";
	asm "pop di";
	asm "pop bp";

	asm "pop ds";
	asm "pop es";			
			
		r=-1;
		
		
		}else{
			r=0;
			}
		
		return r;
	}


int rects()
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
	xx=rectsx;
	yy=rectsy;
	xx1=rectsx1;
	yy1=rectsy1;
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
	movedata(__get_ds(),&rectscolor,__get_cs(),0x8a,1);
	asm "push es";
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
	asm "push ax";
	asm "pop es";
	asm "pop ds";
	asm "mov al,dl";
	asm "xor dx,dx";
	asm "push cx";
	asm "label40:";
	asm "pop cx";
	asm "push cx";
asm "label50:";
asm "push ax";
asm "xor ax,ax";
asm "mov ah,[di]";
asm "cmp ah,al";
asm "jnz label51";
asm "pop ax";
asm "mov [di],al";
asm "jmp label52";
asm "label51:";
asm "pop ax";
asm "label52:";
asm "inc di";
asm "dec cx";
asm "cmp cx,dx";
asm "jnz label50";
	asm "clc";
	asm "add di,si";
asm "dec bx";
asm "cmp bx,dx";
	asm "jnz label40";
	asm "pop ax";
	asm "pop ds";
	asm "pop es";
			
			
		r=-1;
		
		
		}else{
			r=0;
			}
		
		return r;
	}


void linedown(){
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
	xx=linedownx;
	yy=linedowny;
	xx1=linedownx1;
	yy1=linedowny1;
	if (xx>319) xx=319;
	if (xx1>319) xx1=319;
	if (yy>199) yy=199;
	if (yy1>199) yy1=199;
	if (xx<0) xx=0;
	if (xx1<0) xx1=0;
	if (yy<0) yy=0;
	if (yy1<0) yy1=0;

xx1=xx1-xx+1;
yy1=yy1-yy+1;

if (xx1<1 || yy1<1 || xx1>319 || yy1>199) goto linedownexit;

n1=100;
n2=100;

if (xx1<yy1){
n1=xx1*100;
n1=n1/yy1;
yyy=yy1;
}

if (xx1>yy1){
n2=yy1*100;
n2=n2/xx1;
yyy=xx1;
}


	xxx=yy*320+xx;
	ir=screenptr;
	movedata(__get_ds(),&ir,__get_cs(),0x80,2);
	ir=xxx;
	movedata(__get_ds(),&ir,__get_cs(),0x82,2);
	ir=100;
	movedata(__get_ds(),&ir,__get_cs(),0x84,2);
	ir=99;
	movedata(__get_ds(),&ir,__get_cs(),0x86,2);
	ir=yyy;
	movedata(__get_ds(),&ir,__get_cs(),0x88,2);
	ir=0;
	movedata(__get_ds(),&ir,__get_cs(),0x8a,2);
	ir=0;
	movedata(__get_ds(),&ir,__get_cs(),0x8c,2);
	ir=0;
	movedata(__get_ds(),&ir,__get_cs(),0x8e,2);
	ir=320;
	movedata(__get_ds(),&ir,__get_cs(),0x90,2);
	ir=n1;
	movedata(__get_ds(),&ir,__get_cs(),0x92,2);
	ir=0;
	movedata(__get_ds(),&linedowncolor,__get_cs(),0x94,2);
	ir=n2;
	movedata(__get_ds(),&ir,__get_cs(),0x96,2);



	asm "push bp";
	asm "push es";
	asm "push ds";
	asm "push cs";
	asm "pop ds";
	asm "mov si,sp";
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
/* get stask point */
	asm "mov bp,sp";
/* get bit map address segment */
	asm "mov ax,[bp+0x16]";
	asm "mov ds,ax";
	asm "mov es,ax";
/* get bit map address */
	asm "mov di,[bp+0x14]";

	asm "label41:";
/* draw point */
	asm "mov ax,[bp+0x2]"; /*get color attribut */
	asm "mov [di],al";


/* add const float to add part into float 0xc from stack */
	asm "mov ax,[bp+0xc]";   /* load float 0xc  from stack */
	asm "mov bx,[bp+0x4]";    /* load decimal part of float */
	asm "clc";  /* clear carry */
	asm "add ax,bx"; /*add float 0xc into decimal part of equetion */
	asm "mov [bp+0xc],ax"; /* save float 0xc  */

/* add const float to add part into float 0xa from stack */
	asm "mov ax,[bp+0xa]";   /* load float 0xa  from stack */
	asm "mov bx,[bp+0x0]";    /* load decimal part of float */
	asm "clc";  /* clear carry */
	asm "add ax,bx"; /*add float 0xa into decimal part of equetion */
	asm "mov [bp+0xa],ax"; /* save float 0xa  */

/* define x add 1 to di pointer to screen*/
	asm "mov ax,[bp+0xc]";  /* load float 0xc from stack */
	asm "mov bx,[bp+0x12]";  /* load  const 100 */
	asm "cmp ax,bx";  /* cmp float 0xa > 100 */
	asm "jb label43";  /*jump if ignore */
	asm "inc di"; /* add 1 point to di pointer */
	asm "label43:";  /*escape label */


/*define y add 320 1 line*/
	asm "mov ax,[bp+0xa]"; /* load float 0xa from stack */
	asm "mov bx,[bp+0x12]"; /* load  const 100 */
	asm "cmp ax,bx";  /* cmp float 0xa > 100 */
	asm "jb label44";  /*jump if ignore */
	asm "mov ax,[bp+0x6]"; /*load constant 320 */
	asm "clc"; /*clear +1 */
	asm "add di,ax"; /* add 1 line to di pointer */
	asm "label44:";  /*escape label */

/* check if the float 0xc is > 100 */
	asm "mov ax,[bp+0xc]"; /* float 0xc from stack */
	asm "mov bx,[bp+0x12]"; /* const 100*/
	asm "cmp ax,bx"; /*compare 0xc > 100*/
	asm "jb label45"; /*jump if ignore */
	asm "mov ax,[bp+0xc]"; /* load 0xc */
	asm "mov bx,[bp+0x12]"; /*load const 100 */
	asm "clc"; /*clear carry +1*/
	asm "sub ax,bx"; /*sub 0xc - 100 */
	asm "mov [bp+0xc],ax"; /*save 0xc */
	asm "label45:"; /*escape label */

/* check if the float 0xa is > 100 */
	asm "mov ax,[bp+0xa]"; /* float 0xa from stack */
	asm "mov bx,[bp+0x12]"; /* const 100*/
	asm "cmp ax,bx"; /*compare 0xc > 100*/
	asm "jb label46"; /*jump if ignore */
	asm "mov ax,[bp+0xa]";  /* load 0xa */
	asm "mov bx,[bp+0x12]"; /*load const 100 */
	asm "clc"; /*clear carry +1*/
	asm "sub ax,bx"; /*sub 0xa - 100 */
	asm "mov [bp+0xa],ax"; /*save 0xa */
	asm "label46:"; /*escape label */


/*check counter */
	asm "mov ax,[bp+0xe]"; /*load 0xe counter */
	asm "dec ax"; /* 0xe -1 */
	asm "mov [bp+0xe],ax"; /*save 0xe from stack counter */
	asm "mov bx,[bp+0x8]"; /* load const 0 */

	asm "cmp ax,bx"; /*comp counter ==0 */ 
	asm "jnz label41"; /* for counter */
	asm "mov sp,si"; /*restore sp */

	asm "pop ds"; /* restore var from return */
	asm "pop es";
	asm "pop bp";			

linedownexit:
;


	}

