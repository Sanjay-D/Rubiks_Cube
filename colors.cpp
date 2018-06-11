#include<graphics.h>
#include "colors.h"
#include<iostream>
#include<fstream>
using namespace std;

int isSolved(){
     fstream f;
     char *file[6]={"White.dat","Yellow.dat","Cyan.dat","Green.dat","Blue.dat","Red.dat"};
     for(int i=0;i<6;i++){
     f.open(file[i]);
     int col[9],k;
     short int flag=0;
     f.read((char*)&col,sizeof(col));
     k=col[0];
     for(int j=1;j<9;j++){
             if(col[j]!=k){
             flag=0;
             return 0;
             }
             }     
     f.close();
     }
     return 1;
     }

void drawLine(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4){
     setcolor(BLACK);
     setlinestyle(0,1,3);
     int mx1=(2*x1+x2)/3,my1=(2*y1+y2)/3,mx2=(x3+2*x4)/3,my2=(y3+2*y4)/3;
     line(mx1,my1,mx2,my2);
     
     mx1=(x1+2*x2)/3,my1=(y1+2*y2)/3,mx2=(2*x3+x4)/3,my2=(2*y3+y4)/3;
     line(mx1,my1,mx2,my2);
     
     mx1=(2*x2+x3)/3,my1=(2*y2+y3)/3,mx2=(2*x1+x4)/3,my2=(2*y1+y4)/3;
     line(mx1,my1,mx2,my2);
     
     mx1=(x2+2*x3)/3,my1=(y2+2*y3)/3,mx2=(x1+2*x4)/3,my2=(y1+2*y4)/3;
     line(mx1,my1,mx2,my2);
     
     
     setlinestyle(0,1,1);
     }
     

void initfile()
{
     
int col[9];    
ofstream ofile("White.dat");
for(int i=0;i<9;i++)
{col[i]=WHITE;}
ofile.write((char*)&col,sizeof(col));
ofile.close(); 

ofile.open("Red.dat");
for(int i=0;i<9;i++)
{col[i]=RED;}
ofile.write((char*)&col,sizeof(col));
ofile.close();

ofile.open("Green.dat");
for(int i=0;i<9;i++)
{col[i]=GREEN;}
ofile.write((char*)&col,sizeof(col));
ofile.close();

ofile.open("Yellow.dat");for(int i=0;i<9;i++)
{col[i]=YELLOW;}
ofile.write((char*)&col,sizeof(col));
ofile.close();

ofile.open("Blue.dat");
for(int i=0;i<9;i++)
{col[i]=BLUE;}
ofile.write((char*)&col,sizeof(col));
ofile.close();

ofile.open("Cyan.dat");
for(int i=0;i<9;i++)
{col[i]=MAGENTA;}
ofile.write((char*)&col,sizeof(col));
ofile.close();

}



