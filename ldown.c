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
void linedown(linedownx,linedowny,linedownx1,linedowny1,linedowncolor);


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
	
	cls13(4);

for (a=10;a<300;a=a+50){
linedown(0,0,a,100,1);
}

for (a=40;a<300;a=a+50){
linedown(0,0,a,180,1);
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




void linedown(linedownx,linedowny,linedownx1,linedowny1,linedowncolor){
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

