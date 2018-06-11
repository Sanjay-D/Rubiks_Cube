#include<iostream>
#include<graphics.h>
#include "Cube.h"
#include "colors.h"
#include "moves.h"
#include<time.h>
#include"cover.h"
using namespace std;

enum{
	white,blue,red,green,orange,yellow
};

int main(){
	coverPage();
	startGame:
		
	initwindow(640,480,"BOX");
	initfile();
		
	Cube c;
	c.initPoints();
	c.drawCube();
	delay(500);
	char ch;
	float t=0;
	
	while(ch!=27){
		
		int flag=0;
		setcolor(WHITE);
		if(isSolved()){
			outtextxy(0,0,"SOLVED!!");
		}	
		toWords(t);
		
		if(kbhit()){
			ch=getch();
			flag=1;
			if(ch=='l'){
				t=0;
				shuffle();
			} 
		 if(ch=='d')
				translate(c.curSide,Right,c.retSpin());
			else if(ch=='a')
				translate(c.curSide,Left,c.retSpin());
			else if(ch=='x')
				translate(c.curSide,Down,c.retSpin());
			else if(ch=='w')
				translate(c.curSide,Up,c.retSpin());
			else if(ch=='s')
				translate(c.curSide,Front,c.retSpin());
				
			else if(ch=='D')
				translate(c.curSide,iRight,c.retSpin());
			else if(ch=='A')
				translate(c.curSide,iLeft,c.retSpin());
			else if(ch=='X')
				translate(c.curSide,iDown,c.retSpin());
			else if(ch=='W')
				translate(c.curSide,iUp,c.retSpin());
			else if(ch=='S')
				translate(c.curSide,iFront,c.retSpin());
			else if(ch=='~')
				initfile();

		}
		
		if(mousex()>600){
			flag=1;
			c.rotate(1,0);
		}
		else if(mousex()<50){
			flag=1;
			c.rotate(-1,0);
		}
		if(mousey()>420){
			flag=1;
			c.rotate(0,-1);
		}
		else if(mousey()<60){
			flag=1;
			c.rotate(0,1);
		}
		
		if(flag){
		cleardevice();
		c.drawCube();
	}
		delay(100);
		t+=0.1;
	}
				if(ch==27)
			{cleardevice();
			closegraph();
			exitPage();
			}
}	

	

