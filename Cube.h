#ifndef CUBE_H
#define CUBE_H

float mod(float);

struct point{
	int x,y;
	float theta,phi;
};

enum{
	A=0,B,C,D,E,F,G,H
};

class Cube
{
	point ps[8];
	int spin;
	
	void drawQ(point,point,point,point);
	void cSide();
	
	public:
		char *curSide;
		void initPoints();
		void drawCube();
		void rotate(int,int);
		void disp();
		void colorSide(point,point,point,point,int,char []);
		int retSpin(){
			return spin;
		}
		float retTheta(){
			return ps[A].theta;
		}
		
		float retPhi(){
			return ps[A].phi;
		}
	protected:
};

#endif
