//#include<fstream>
enum {
	Right=7,Left=5,Up=3,Down=4,iRight=-7,iLeft=-5,iUp=-3,iDown=-4,Front=10,iFront=-10,Back=12,iBack=-12,X,Y
};

	static char fileName[4][20];
	void moveSide(int );
	void assignFiles(int);
	void swapData(char f1[],char f2[] ,int move,int i1=0,int i2=0,int i3=0);
	void twistSide(char f[],int spin);
	int mod(int x);
	void shuffle();
	void swapData(char w1[],char w2[],short int arr1[],short int arr2[]);
	void translate(char* ,int ,int );
