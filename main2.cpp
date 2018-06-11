#include<iostream>
#include<math.h>
#include<graphics.h>
using namespace std;
int h,k;
void para(float a,float u)
{int y=0;
for(int i=0;i<1000,y>=0;i++)
{y=(i*tan((a*M_PI)/180)-((5*i*i)/(u*u*pow(cos((a*M_PI)/180),2))));
circle(i,600-y,1);
delay(1);
if((i>=h-10)&&(i<=h+10)&&(y>=600-k)&&(y<=620-k))
{cleardevice();
outtext("SUCCESS!! ");
break;}
else if(((y<0)&&((i>h+10)||(i<h-10))||(i>1000)))
{cleardevice();
outtext("FAIL !!");
break;}}}
int main()
{float a,u;
cout<<"Enter target coordinates"<<endl<<" (x coordinate between 10 and 990 ) (y coordinate between 20 and 600)"<<endl;
cin>>h>>k;
cout<<"Target at ("<<h<<", "<<k<<")"<<endl;
cout<<"Artillery at (0,600) [Ground level]"<<endl;
cout<<"Enter angle of launch (degrees) and velocity of projectile"<<endl;
cin>>a>>u;
initwindow(1000,700);
line(0,600,1000,600);
rectangle(h-10,k-20,h+10,k);
para(a,u);	
system("pause");
}
