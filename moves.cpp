#include "moves.h"
#include<string.h>
#include<iostream>
#include<fstream>
#include<time.h>
#include<stdlib.h>
using namespace std;

int mod(int x){
	if(x>=0)
	return x;
	else
	return -x;
}

void assignFiles(int move){
	int k=3;
	if(move<0)
	k=1;
	
	if(mod(move)==Right||mod(move)==Left){
	strcpy(fileName[0],"White.dat");
	strcpy(fileName[(k+2)%4],"Blue.dat");
	strcpy(fileName[2],"Yellow.dat");
	strcpy(fileName[k%4],"Green.dat");
	if(move==Right||move==iRight){
		twistSide("Red.dat",move);
	}
	else{
		twistSide("Cyan.dat",-move);
	}
}
else if(mod(move)==Up||mod(move)==Down){
	strcpy(fileName[0],"White.dat");
	strcpy(fileName[k%4],"Red.dat");
	strcpy(fileName[2],"Yellow.dat");
	strcpy(fileName[(k+2)%4],"Cyan.dat");
	if(mod(move)==Up){
		twistSide("Blue.dat",-move);
	}
	if(move==Down|move==iDown)
	twistSide("Green.dat",move);
}
else if(move==Front||move==iFront||move==Back||move==iBack){
	strcpy(fileName[0],"Blue.dat");
	strcpy(fileName[1],"Red.dat");
	strcpy(fileName[2],"Green.dat");
	strcpy(fileName[3],"Cyan.dat");
	if(mod(move)==Front)
		twistSide("White.dat",-move);
	else
		twistSide("Yellow.dat",move);
}
}

void moveSide(int move){
	assignFiles(move);
	if(move==Front){
		short int arr1[3]={6,7,8},arr2[3]={8,5,2};
		swapData(fileName[0],fileName[3],arr1,arr2);
		arr1[0]=2;arr1[1]=1;arr1[2]=0;
		swapData(fileName[3],fileName[2],arr2,arr1);
		arr2[0]=0;arr2[1]=3;arr2[2]=6;
		swapData(fileName[2],fileName[1],arr1,arr2);
	}
	else if(move==iFront){
		short int arr1[3]={6,7,8},arr2[3]={0,3,6};
		swapData(fileName[0],fileName[1],arr1,arr2);
		arr1[0]=2;arr1[1]=1;arr1[2]=0;
		swapData(fileName[1],fileName[2],arr2,arr1);
		arr2[0]=8;arr2[1]=5;arr2[2]=2;
		swapData(fileName[2],fileName[3],arr1,arr2);
	}
	else if(move==Back){
		short int arr1[3]={0,1,2},arr2[3]={6,3,0};
		swapData(fileName[0],fileName[3],arr1,arr2);
		arr1[0]=8;arr1[1]=7;arr1[2]=6;
		swapData(fileName[3],fileName[2],arr2,arr1);
		arr2[0]=2;arr2[1]=5;arr2[2]=8;
		swapData(fileName[2],fileName[1],arr1,arr2);
	}
	else if(move==iBack){
		short int arr1[3]={0,1,2},arr2[3]={2,5,8};
		swapData(fileName[0],fileName[1],arr1,arr2);
		arr1[0]=8;arr1[1]=7;arr1[2]=6;
		swapData(fileName[1],fileName[2],arr2,arr1);
		arr2[0]=6;arr2[1]=3;arr2[2]=0;
		swapData(fileName[2],fileName[3],arr1,arr2);
	}
	else if(mod(move)==Up){
		swapData(fileName[1],fileName[2],move,8,7,6);
		swapData(fileName[1],fileName[0],move);
		swapData(fileName[0],fileName[3],move);
	
	}
	
	else if(mod(move)==Down){
		
		swapData(fileName[1],fileName[2],move,2,1,0);
		swapData(fileName[0],fileName[1],move);
		swapData(fileName[0],fileName[3],move);
	
	}
	else{
	swapData(fileName[0],fileName[1],move);
	swapData(fileName[1],fileName[2],move);
	swapData(fileName[2],fileName[3],move);
}
}

void swapData(char w1[],char w2[],int move,int i1,int i2,int i3){
	
	fstream f1(w1),f2(w2);
	
	f1.seekg(0);
	f2.seekg(0);
	int col[9],nextCol[9],arr[3]={i1,i2,i3};
	short int x=0;
	f1.read((char*)&col,sizeof(col));
	f2.read((char*)&nextCol,sizeof(nextCol));
	int flag=0;
	for(int i=0;i<9;i++){
		flag=0;
		if(mod(move)==3&&i<3){
		flag=1;
		if(i1){
				int t=nextCol[arr[x]];
				nextCol[arr[x]]=col[i];
				col[i]=t;
				x++;
				flag=0;
			
		}
		}
		else if(mod(move)==4&&i>5&&i<=8){
			flag=1;
			if(i2!=0){
				int t=nextCol[arr[x]];
				nextCol[arr[x]]=col[i];
				col[i]=t;
				x++;
				flag=0;
			}
		}
		else if((mod(move)==Front||mod(move)==Back)&&(i%3)+10==mod(move)){
		
		int t=nextCol[arr[x]];
		nextCol[arr[x]]=col[i];
		col[i]=t;
		x++;
		}
		
		else if((i%3)+5==mod(move)){
		flag=1;
	}
	if(flag){
			int t=col[i];
		col[i]=nextCol[i];
		nextCol[i]=t;
	}
	}
	f1.seekg(0);
	f1.write((char*)&col,sizeof(col));
	f2.seekg(0);
	f2.write((char*)&nextCol,sizeof(nextCol));
}

void twistSide(char f[],int spin){
	
	fstream file(f);
	int col[9],newCol[9];
	file.read((char*)&col,sizeof(col));
	for(int x=0;x<9;x++){
		if(spin>0){
			newCol[x]=col[(6-x+10*(x%3))/3];
		}
		else if(spin<0){
			newCol[x]=col[((x-x%3)/3)+6-(x%3)*3];
		}
	}
	file.seekg(0);
	file.write((char*)&newCol,sizeof(newCol));
	file.close();
}

void swapData(char w1[],char w2[],short int arr1[],short int arr2[]){
	
	fstream f1(w1),f2(w2);
	f1.seekg(0);
	f2.seekg(0);
	
	int col[9],nextCol[9];
	f1.read((char*)&col,sizeof(col));
	f2.read((char*)&nextCol,sizeof(nextCol));
	
	for(int i=0;i<3;i++){
		int t=col[arr1[i]];
		col[arr1[i]]=nextCol[arr2[i]];
		nextCol[arr2[i]]=t;
	}
	f1.seekg(0);f2.seekg(0);
	f1.write((char*)&col,sizeof(col));
	f2.write((char*)&nextCol,sizeof(nextCol));
	f1.close();
	f2.close();
}


void shuffle(){
	short int arr[12]={Right,iRight,Left,iLeft,Up,iUp,Down,iDown,Front,iFront,Back,iBack};
	srand(time(NULL));
	for(int i=0;i<40;i++){
		moveSide(arr[rand()%12]);
	}
	
	
}

void translate(char side[], int move ,int spin)
{
if(spin==1)
	{
		if(!strcmp(side,"White"))
		{
			if(mod(move)==Right)
				{moveSide(move*Left/mod(move));
				}
			else if(mod(move)==Left)
				{moveSide(mod(move)*Right/move);
				}
			else if(mod(move)==Up)
				{moveSide(mod(move)*iDown/move);
				}	
			else if(mod(move)==Down)
				{moveSide(mod(move)*Up/move);
				}	
			else if(mod(move)==Front)
				moveSide(move);
		}
		else if(!strcmp(side,"Red"))
		{
			 if(mod(move)==Left)
				{moveSide(mod(move)*iBack/move);
				}
			else if(mod(move)==Right)
				{moveSide(mod(move)*Front/move);
				}
			else if(mod(move)==Up)
				{moveSide(mod(move)*iDown/move);
				}
			else if(mod(move)==Down)
				{moveSide(mod(move)*Up/move);
				}			
			else if(mod(move)==Front)
				moveSide(mod(move)*iRight/move);
		}
		else if(!strcmp(side,"Yellow"))
		{
			if(mod(move)==Left)
				{moveSide(mod(move)*Left/move);
				}
			else if(mod(move)==Right)
				{moveSide(mod(move)*iRight/move);
				}
			else if(mod(move)==Up)
				{moveSide(mod(move)*iDown/move);
				}
			else if(mod(move)==Down)
				{moveSide(mod(move)*Up/move);
				}			
			else if(mod(move)==Right)
				moveSide(mod(move)*iBack/move);
			else if(mod(move)==Front)
				moveSide(mod(move)*iBack/move);
		}
		else if(!strcmp(side,"Cyan"))
		{
			if(mod(move)==Left)
				{moveSide(mod(move)*Front/move);
				}
			else if(mod(move)==Right)
				{moveSide(mod(move)*iBack/move);
				}
			else if(mod(move)==Up)
				{moveSide(mod(move)*iDown/move);
				}
			else if(mod(move)==Down)
				{moveSide(mod(move)*Up/move);
				}		
			else if(mod(move)==Front)
				moveSide(mod(move)*Left/move);
		}
	}
	else if(!spin)
	
		{
		if(!strcmp(side,"White"))
		{cout<<side;
			if(mod(move)==Right)
				{moveSide(mod(move)*iRight/move);
				}
			else if(mod(move)==Left)
				{moveSide(mod(move)*Left/move);
				}
			else if(mod(move)==Up)
				{moveSide(mod(move)*Up/move);
				}	
			else if(mod(move)==Down)
				{moveSide(mod(move)*iDown/move);
				}	
			else if(mod(move)==Front)
				moveSide(move);
				
		}
		else if(!strcmp(side,"Blue"))
		{cout<<side;
			 if(mod(move)==Left)
				{moveSide(mod(move)*Left/move);
				}
			else if(mod(move)==Right)
				{moveSide(mod(move)*iRight/move);
				}
			else if(mod(move)==Up)
				{moveSide(mod(move)*iBack/move);
				}
			else if(mod(move)==Down)
				{moveSide(mod(move)*Front/move);
				}			
				
			else if(mod(move)==Front)
				moveSide(mod(move)*Up/move);
		}
		else if(!strcmp(side,"Yellow"))
		{cout<<side;
			if(mod(move)==Left)
				{moveSide(mod(move)*Left/move);
				}
			else if(mod(move)==Right)
				{moveSide(mod(move)*iRight/move);
				}
			else if(mod(move)==Up)
				{moveSide(mod(move)*iDown/move);
				}
			else if(mod(move)==Down)
				{moveSide(mod(move)*Up/move);
				}			
			else if(mod(move)==Front)
				moveSide(mod(move)*iBack/move);
		}
		else if(!strcmp(side,"Green"))
		{cout<<side;
			if(mod(move)==Left)
				{moveSide(mod(move)*Left/move);
				}
			else if(mod(move)==Right)
				{moveSide(mod(move)*iRight/move);
				}
			else if(mod(move)==Up)
				{moveSide(mod(move)*Front/move);
				}
			else if(mod(move)==Down)
				{moveSide(mod(move)*iBack/move);
				}		
			else if(mod(move)==Front)
				moveSide(mod(move)*iDown/move);
		}
	}
	
	
}

