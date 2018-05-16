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
int number1;       
int number2;       
int sound1;       
int sound2;       
int max();       
int min();       
void sleep();       
void print();       
void cls3();       
long get_ttimer();       
void sounds();       
void main(){       
          	int x1;       
          	int y1;       
          	int y2;       
          	int x2;       
          	int xx;       
          	int yy;       
          	int c;       
          	long t1;       
          	long t2;       
          	long t3;       
          	char ss[2];       
          	char sss[2];       
          	char *s1=" ";       
          	char *s="O";       
          	strcpy(ss,s);       
          	strcpy(sss,s1);       
          	cls1=0x17;       
          	cls3();       
          	color=cls1;       
          	sound1=523;       
          	sound2=16;       
          	sounds();       
          	x1=0;       
          y1=0;       
          x2=0;       
          y2=0;       
          xx=1;       
          yy=1;       
          t3=6;       
          do{       
                    t1=get_ttimer();       
                    t1=t1+t3;       
                    x=x2;       
                    y=y2;       
                    print1=&sss;       
                    print();       
                    x=x1;       
                    y=y1;       
                    print1=&ss;       
                    print();       
                           
                    y2=y1;       
                    x2=x1;       
                    x1=x1+xx;       
                    y1=y1+yy;       
                    if (x1>79){       
                              	x1=79;       
                              xx=-1;       
                              sounds();       
                    	}       
                    if (x1<0){       
                              	x1=0;       
                              xx=1;       
                              sounds();       
                    	}       
                    if (y1>24){       
                              	y1=24;       
                              yy=-1;       
                              sounds();       
                    	}       
                    if (y1<0){       
                              	y1=0;       
                              yy=1;       
                              sounds();       
                    	}       
                           
                           
                    do{       
                              t2=get_ttimer();       
                    }while(!(kbhit() || t1<t2));       
          }while(!kbhit());       
          	       
                 
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
