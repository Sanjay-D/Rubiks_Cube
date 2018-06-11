#include "cover.h"
#include<graphics.h>
#include<iostream>
#include<fstream>
using namespace std;

void coverPage()
{ char ch;
start:
	initwindow(1000,600);
    //readimagefile("rcube.jpg",0,0,1000,1000);
    settextstyle(0,0,4);
    outtextxy(600,100,"PLAY");
    outtextxy(450,300,"HOW TO PLAY");
    if(kbhit())
    {ch=getch();
    cout<<int(ch);
	}
    	char f='a';
	while(f!=27)
{
if(kbhit())
	f=getch();
	
	if(mousex()>600&&mousey()<125&&mousey()>75&&ismouseclick(513)){
	clearmouseclick(513);
	closegraph();
	return;
	}
	
else if(mousex()>450&&mousey()>275&&mousey()<325&&ismouseclick(513))
	{
		clearmouseclick(513);
		closegraph();
		secondPage();
		goto start;
	}


}
    if (f==27)
    {cleardevice();
    closegraph();
	exitPage();
	}
    
    
    }

void secondPage(){
	system("HowToPlay.txt");
	return;
 }
  
void toWords(float f){
	
	char text[20]={'t','i','m','e',':','\0'};
	int t=(int)f,len=0;
	while(t>0){
		t/=10;
		len++;
	}
	t=(int)f;
	for(int i=0;i<len;i++){
		text[4+len-i]=(t%10)+48;
		t/=10;
	}
	text[5+len]='.';
	text[6+len]=(10*f-10*(int)f)+48;
	text[7+len]='\0';
	outtextxy(50,50,text);
}

void exitPage()
{initwindow(1100,480,"exit");
char ch;
settextstyle(0,0,5);
outtextxy(100,50,"THANK YOU FOR PLAYING!");
settextstyle(0,0,3);
outtextxy(500,400,"CREDITS:");
settextstyle(0,0,2);
outtextxy(500,430,"Abhiram and Sanjay");
while(ch!=27)
	{if(kbhit())
		{ch=getch();
		}
	}	
}

