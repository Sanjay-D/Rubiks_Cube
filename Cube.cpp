#include "Cube.h"
#include "colors.h"
#include<iostream>
#include<graphics.h>
#include<math.h>
#include<fstream>
using namespace std;

float mod(float x){
	if(x>=0)
		return x;
	else 
	return -x;
}

void Cube::disp(){
	
	float d;
	d=sqrt(pow(ps[A].x-ps[B].x,2)+pow(ps[A].y-ps[B].y,2));
	cout<<d<<endl;
	
}

void Cube::colorSide(point a,point b,point c,point d,int colo,char *fName="White.dat"){
	

    int col[9];
    short int mp[16]={(2*a.x+b.x)/3,(2*a.y+b.y)/3,(a.x+2*b.x)/3,(a.y+2*b.y)/3,
    (2*b.x+c.x)/3,(2*b.y+c.y)/3,(b.x+2*c.x)/3,(b.y+2*c.y)/3,
    (2*c.x+d.x)/3,(2*c.y+d.y)/3,(c.x+2*d.x)/3,(c.y+2*d.y)/3,
    (2*d.x+a.x)/3,(2*d.y+a.y)/3,(d.x+2*a.x)/3,(d.y+2*a.y)/3,
    },
    mpm[8]={(2*mp[0]+mp[10])/3,(2*mp[1]+mp[11])/3,
    (mp[0]+2*mp[10])/3,(mp[1]+2*mp[11])/3,
    (2*mp[2]+mp[8])/3,(2*mp[3]+mp[9])/3,
    (mp[2]+2*mp[8])/3,(mp[3]+2*mp[9])/3
    };
    
    
    
    
    ifstream ifile(fName);
    ifile.read((char*)&col,sizeof(col));
    
    for(int i=0;i<9;i++){
    setfillstyle(1,col[i]);
            
            if(i==0){
                     int pt[8]={a.x,a.y,mp[0],mp[1],mpm[0],mpm[1],mp[14],mp[15]};
                     fillpoly(4,pt);
                     }
            if(i==1){
                     int pt[8]={mp[0],mp[1],mp[2],mp[3],mpm[4],mpm[5],mpm[0],mpm[1]};
                     fillpoly(4,pt);
                     }
            if(i==2){
                     int pt[8]={mp[2],mp[3],b.x,b.y,mp[4],mp[5],mpm[4],mpm[5]};
                     fillpoly(4,pt);
                     }
            if(i==3){
                     int pt[8]={mp[14],mp[15],mpm[0],mpm[1],mpm[2],mpm[3],mp[12],mp[13]};
                     fillpoly(4,pt);
                     }
            if(i==4){
                     int pt[8]={mpm[0],mpm[1],mpm[4],mpm[5],mpm[6],mpm[7],mpm[2],mpm[3]};
                     fillpoly(4,pt);
                     }
            if(i==5){
                     int pt[8]={mpm[4],mpm[5],mp[4],mp[5],mp[6],mp[7],mpm[6],mpm[7]};
                     fillpoly(4,pt);
                     }
            if(i==6){
                     int pt[8]={mp[12],mp[13],mpm[2],mpm[3],mp[10],mp[11],d.x,d.y};
                     fillpoly(4,pt);
                     }
            if(i==7){
                     int pt[8]={mpm[2],mpm[3],mpm[6],mpm[7],mp[8],mp[9],mp[10],mp[11]};
                     fillpoly(4,pt);
                     }
            if(i==8){
                     int pt[8]={mpm[6],mpm[7],mp[6],mp[7],c.x,c.y,mp[8],mp[9]};
                     fillpoly(4,pt);
                     }
            }
    
    
	
	ifile.close();
	
	
}

void Cube::initPoints(){

	ps[A].x=170;ps[A].y=90;ps[A].theta=5*M_PI/4;ps[A].phi=3*M_PI/4;
	ps[B].x=470;ps[B].y=90;ps[B].theta=7*M_PI/4;ps[B].phi=3*M_PI/4;
	ps[C].x=470;ps[C].y=390;ps[C].theta=7*M_PI/4;ps[C].phi=5*M_PI/4;
	ps[D].x=170;ps[D].y=390;ps[D].theta=5*M_PI/4;ps[D].phi=5*M_PI/4;
	
	
	ps[E].x=180;ps[E].y=100;ps[E].theta=3*M_PI/4;ps[E].phi=M_PI/4;
	ps[F].x=460;ps[F].y=100;ps[F].theta=M_PI/4;ps[F].phi=M_PI/4;
	ps[G].x=460;ps[G].y=380;ps[G].theta=M_PI/4;ps[G].phi=7*M_PI/4;
	ps[H].x=180;ps[H].y=380;ps[H].theta=3*M_PI/4;ps[H].phi=7*M_PI/4;
	

	
}

void Cube::drawCube(){
	
	int flag;
	if(spin){
		colorSide(ps[D],ps[C],ps[G],ps[H],GREEN,"Green.dat");
        drawLine(ps[D].x,ps[D].y,ps[H].x,ps[H].y,ps[G].x,ps[G].y,ps[C].x,ps[C].y);
		
		if((ps[A].theta>5*M_PI/4&&ps[A].theta<7*M_PI/4)||(ps[A].theta<-M_PI/4&&ps[A].theta>-3*M_PI/4)){
			colorSide(ps[H],ps[G],ps[F],ps[E],YELLOW,"Yellow.dat");drawLine(ps[E].x,ps[E].y,ps[F].x,ps[F].y,ps[G].x,ps[G].y,ps[H].x,ps[H].y);
			colorSide(ps[B],ps[F],ps[G],ps[C],RED,"Red.dat");drawLine(ps[B].x,ps[B].y,ps[F].x,ps[F].y,ps[G].x,ps[G].y,ps[C].x,ps[C].y);//always show in y-rotaion	
		}
		else if(ps[A].theta>M_PI/4&&ps[A].theta<3*M_PI/4||(ps[A].theta<-5*M_PI/4&&ps[A].theta>-7*M_PI/4)){
			colorSide(ps[A],ps[B],ps[C],ps[D],WHITE,"White.dat");drawLine(ps[A].x,ps[A].y,ps[B].x,ps[B].y,ps[C].x,ps[C].y,ps[D].x,ps[D].y);
			colorSide(ps[E],ps[A],ps[D],ps[H],CYAN,"Cyan.dat");drawLine(ps[A].x,ps[A].y,ps[E].x,ps[E].y,ps[H].x,ps[H].y,ps[D].x,ps[D].y);//never show in y-rotation
			
		}
		else if(ps[A].theta>3*M_PI/4&&ps[A].theta<5*M_PI/4||(ps[A].theta<-3*M_PI/4&&ps[A].theta>-5*M_PI/4)){
			colorSide(ps[E],ps[A],ps[D],ps[H],CYAN,"Cyan.dat");drawLine(ps[A].x,ps[A].y,ps[E].x,ps[E].y,ps[H].x,ps[H].y,ps[D].x,ps[D].y);
			colorSide(ps[H],ps[G],ps[F],ps[E],YELLOW,"Yellow.dat");drawLine(ps[E].x,ps[E].y,ps[F].x,ps[F].y,ps[G].x,ps[G].y,ps[H].x,ps[H].y);
			
		}
		
		else{
			colorSide(ps[A],ps[B],ps[C],ps[D],WHITE,"White.dat");drawLine(ps[A].x,ps[A].y,ps[B].x,ps[B].y,ps[C].x,ps[C].y,ps[D].x,ps[D].y);
			colorSide(ps[B],ps[F],ps[G],ps[C],RED,"Red.dat");drawLine(ps[B].x,ps[B].y,ps[F].x,ps[F].y,ps[G].x,ps[G].y,ps[C].x,ps[C].y);//always show in y-rotaion
		}
		
	}
	
	else{
		colorSide(ps[E],ps[A],ps[D],ps[H],CYAN,"Cyan.dat");drawLine(ps[A].x,ps[A].y,ps[E].x,ps[E].y,ps[H].x,ps[H].y,ps[D].x,ps[D].y);//always show in y-rotation
		if(ps[A].phi>3*M_PI/4&&ps[A].phi<5*M_PI/4||(ps[A].phi<-3*M_PI/4&&ps[A].phi>-5*M_PI/4)){
			colorSide(ps[H],ps[G],ps[F],ps[E],YELLOW,"Yellow.dat");drawLine(ps[E].x,ps[E].y,ps[F].x,ps[F].y,ps[G].x,ps[G].y,ps[H].x,ps[H].y);
			colorSide(ps[D],ps[C],ps[G],ps[H],GREEN,"Green.dat");drawLine(ps[D].x,ps[D].y,ps[H].x,ps[H].y,ps[G].x,ps[G].y,ps[C].x,ps[C].y);//top side , show while rotation about line(x=0;y=0)
			
		}
		else if(ps[A].phi>5*M_PI/4&&ps[A].phi<7*M_PI/4||(ps[A].phi<-M_PI/4&&ps[A].phi>-3*M_PI/4)){
			colorSide(ps[A],ps[B],ps[C],ps[D],WHITE,"White.dat");drawLine(ps[A].x,ps[A].y,ps[B].x,ps[B].y,ps[C].x,ps[C].y,ps[D].x,ps[D].y);
			colorSide(ps[D],ps[C],ps[G],ps[H],GREEN,"Green.dat");drawLine(ps[D].x,ps[D].y,ps[H].x,ps[H].y,ps[G].x,ps[G].y,ps[C].x,ps[C].y);//top side , show while rotation about line(x=0;y=0)
			
		}
		else if((ps[A].phi>7*M_PI/4&&ps[A].phi<=2*M_PI)||(ps[A].phi>=0&&ps[A].phi<M_PI/4)||(ps[A].phi<-M_PI/4&&ps[A].phi>-3*M_PI/4)){
			colorSide(ps[A],ps[B],ps[C],ps[D],WHITE,"White.dat");drawLine(ps[A].x,ps[A].y,ps[B].x,ps[B].y,ps[C].x,ps[C].y,ps[D].x,ps[D].y);
			colorSide(ps[E],ps[F],ps[B],ps[A],BLUE,"Blue.dat");drawLine(ps[A].x,ps[A].y,ps[E].x,ps[E].y,ps[F].x,ps[F].y,ps[B].x,ps[B].y);	
			
		}
		else if(ps[A].phi>M_PI/4&&ps[A].phi<3*M_PI/4||(ps[A].phi<-5*M_PI/4&&ps[A].phi>-7*M_PI/4)){
			colorSide(ps[E],ps[F],ps[B],ps[A],BLUE,"Blue.dat");drawLine(ps[A].x,ps[A].y,ps[E].x,ps[E].y,ps[F].x,ps[F].y,ps[B].x,ps[B].y);
			colorSide(ps[H],ps[G],ps[F],ps[E],YELLOW,"Yellow.dat");drawLine(ps[E].x,ps[E].y,ps[F].x,ps[F].y,ps[G].x,ps[G].y,ps[H].x,ps[H].y);
	
		}
		
		else {
			colorSide(ps[A],ps[B],ps[C],ps[D],WHITE,"White.dat");drawLine(ps[A].x,ps[A].y,ps[B].x,ps[B].y,ps[C].x,ps[C].y,ps[D].x,ps[D].y);
			colorSide(ps[E],ps[F],ps[B],ps[A],BLUE,"Blue.dat");drawLine(ps[A].x,ps[A].y,ps[E].x,ps[E].y,ps[F].x,ps[F].y,ps[B].x,ps[B].y);
			
			
		}	
	}	
}

void Cube::drawQ(point p1,point p2,point p3,point p4){
	
	line(p1.x,p1.y,p2.x,p2.y);
	line(p2.x,p2.y,p3.x,p3.y);
	line(p3.x,p3.y,p4.x,p4.y);
	line(p4.x,p4.y,p1.x,p1.y);
}

void Cube::rotate(int xspin,int yspin){
	
	if(xspin){
		spin=1;
		for(int i=A;i<=H;i++){
			ps[i].theta=ps[i].theta +xspin*M_PI/36;
			ps[i].phi+=xspin*M_PI/36;
			if(ps[i].theta>=2*M_PI){
			ps[i].theta=0;
			}
			if(ps[i].theta<=-2*M_PI){
				ps[i].theta=0;
			}
			if(ps[i].phi>=2*M_PI){
			ps[i].phi=0;
			}
			if(ps[i].phi<=-2*M_PI){
				ps[i].phi=0;
			}
			
			ps[i].x=145*cos(ps[i].theta)+320;
			if(i==D|i==C||i==G||i==H)
			ps[i].y=100*sin(ps[i].theta)+180;
			else
			ps[i].y=100*sin(ps[i].theta)+320;
			
		}
		
		

	}
	
	if(yspin){
		spin=0;
		for(int i=A;i<=H;i++){
			ps[i].theta=ps[i].theta +yspin*M_PI/36;
			ps[i].phi+=yspin*M_PI/36;
			if(ps[i].theta>=2*M_PI){
			ps[i].theta=0;
			}
			if(ps[i].theta<=-2*M_PI){
				ps[i].theta=0;
			}
			if(ps[i].phi>=2*M_PI){
			ps[i].phi=0;
			}
			if(ps[i].phi<=-2*M_PI){
				ps[i].phi=0;
			}
			
			ps[i].y=145*sin(ps[i].phi)+250;
			if(i==A|i==E||i==D||i==H)
			ps[i].x=100*cos(ps[i].phi)+250;
			else
			ps[i].x=100*cos(ps[i].phi)+400;
			
			
		}
	}
	cSide();
}


void Cube::cSide(){
	
	if(spin==1){
		
		if(ps[A].theta>=0&&ps[A].theta<=M_PI/2||(ps[A].theta>=-2*M_PI&&ps[A].theta<=-3*M_PI/2))
			curSide="White";
		else if(ps[A].theta>=M_PI/2&&ps[A].theta<=M_PI||(ps[A].theta>=-3*M_PI/2&&ps[A].theta<=-M_PI))
			curSide="Cyan";
		else if(ps[A].theta>=M_PI&&ps[A].theta<=3*M_PI/2||(ps[A].theta>=-M_PI&&ps[A].theta<=-M_PI/2))
			curSide="Yellow";
		else if(ps[A].theta>=3*M_PI/2&&ps[A].theta<=2*M_PI||(ps[A].theta>=-M_PI/2&&ps[A].theta<=0))
			curSide="Red";
	}
	else if(spin==0){
		if(ps[A].phi>=0&&ps[A].phi<=M_PI/2||(ps[A].phi>=-2*M_PI&&ps[A].phi<=-3*M_PI/2))
			curSide="Blue";
		else if(ps[A].phi>=M_PI/2&&ps[A].phi<=M_PI||(ps[A].phi>=-3*M_PI/2&&ps[A].phi<=-M_PI))
			curSide="Yellow";
		else if(ps[A].phi>=M_PI&&ps[A].phi<=3*M_PI/2||(ps[A].phi>=-M_PI&&ps[A].phi<=-M_PI/2))
			curSide="Green";
		else if(ps[A].phi>=3*M_PI/2&&ps[A].phi<=2*M_PI||(ps[A].phi>=-M_PI/2&&ps[A].phi<=0))
			curSide="White";
			
	}
	
}

