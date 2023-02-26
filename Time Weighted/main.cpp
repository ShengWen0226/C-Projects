#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;

int main() {
	double x[381];
	double y[381];
	ofstream outfun("funtion.txt");
	for(int i=0;i<=380;i++){
		x[i] = i*0.1;
		if(x[i]<=15*M_PI/16 || x[i]>=2*M_PI){
			y[i] = sin(16*x[i])/2;
		}else if(x[i]<=M_PI || x[i]>=62*M_PI/32){
			y[i] = sin(16*x[i])*5/4;
		}else{
			y[i] = sin(16*x[i])*2;
		}
	}
	for(int i=0;i<=100;i++){
		outfun <<x[i]<<","<<y[i]<<endl;
	}
	outfun.close();
	double sx[191];
	double sy[191];
	double total = 0;
	for(int i=0;i<=380;i++){
		total += pow(y[i],2);
		if(i%2==0){
			sx[i/2] = i*0.1;
			sy[i/2] = sqrt(total/(i/2+1));
		}
	}
	sy[0] = sy[2];
	sy[1] = sy[2];
	ofstream outslow("slow.txt");
	for(int i=0;i<=50;i++){
		outslow <<sx[i]<<","<<sy[i]<<endl;
	}
	outslow.close();
	double fx[191];
	double fy[191];
	int n = 1;
	int m = 1;
	fx[0] = sx[0];
	fy[0] = sy[0];
	for(int i=1;i<=50;i++){
		fx[i] = sx[i];
		fy[i] = sy[i];
		if(i>10 && sy[i]-sy[i-1]>0.005){
			fx[i] = fx[i]-0.2*n+0.2*n*0.125;
			n ++;
		}else if(sy[i-1]-sy[i]>0.005){
			fx[i] = fx[i]-0.2*m+0.2*m*0.125;
        	m ++;
		}
	}
	for(int i=51;i<=190;i++){
		fx[i] = sx[i];
		fy[i] = sy[i];
		fx[i] = fx[i]-0.2*m+0.2*m*0.125;
        m ++;
	}
	ofstream outfast("fast.txt");
	for(int i=0;i<=190;i++){
		outfast <<fx[i]<<","<<fy[i]<<endl;
	}
	outfast.close();
	double ix[51];
	double iy[51];
	n = 1;
	m = 1;
	ix[0] = sx[0];
	iy[0] = sy[0];
	for(int i=1;i<=50;i++){
		ix[i] = sx[i];
		iy[i] = sy[i];
		if(i>10 && sy[i]-sy[i-1]>0.005){
			ix[i] = ix[i]-0.2*n+0.2*n*0.035;
			n ++;
		}else if(sy[i-1]-sy[i]>0.005){
			ix[i] = ix[i]-0.2*m+0.2*m*1.5;
        	m ++;
		}
	}
	ofstream outimpulse("impulse.txt");
	for(int i=0;i<=50;i++){
		outimpulse <<ix[i]<<","<<iy[i]<<endl;
	}
	outimpulse.close();
	system("pause");
	return 0;
}

