#include <stdio.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <stdlib.h>

#define WIDTH 3000
#define HEIGHT 3000
using namespace std;


float RandomFloat(float a, float b) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}


int max(int screen[][HEIGHT]){
	int max=0;
	for(int j=0;j<WIDTH ;j++){
		for(int k=0;k<HEIGHT ;k++){
			if(screen[j][k]>max) max = screen[j][k];
		}
	}
	
	return max;

}

bool check(double r,double i){
	float tempf=0,sumrf=0,sumif=0;
	sumrf += r ;
	sumif += i ;
	for (int j = 0; j <= 5000; ++j)
	{ //per il singolo punto
		 	    	
		tempf=sumrf;
		sumrf = sumrf*sumrf - sumif*sumif;
		sumif = 2*tempf*sumif;   // calcola il quadrato del numero complesso (a^2-b^2+2iab)
		sumrf += r ;
		sumif += i ;
		if((sumrf>2 || sumrf<-2 || sumif >2 || sumif<-2) && j<2500) return false;    
		else if((sumrf>2 || sumrf<-2 || sumif >2 || sumif<-2) && j>=2500) return true;
		 		    
	}
	return false;



}

int screen[WIDTH][HEIGHT];

int main(){
	double temp,sumr=0,sumi=0;
	int x,y;
	double r,i;

	for(int j=0;j<WIDTH;j++){
		for(int k=0;k<HEIGHT ;k++){
			screen[j][k]=0;
		}
	}
	for(int k=0;k<200;){ 

		r=RandomFloat(-2,0.75);
		i=RandomFloat(-1.5,1.5);
		double p = sqrt(pow(r-1.0/4.0,2)+i*i); 

		if( pow((r+1),2) + pow(i,2) - 1.0/16.0 > 0  && r>(p-2*pow(p,2)+1.0/4)) {
			if(check(r,i)==true){
				sumr=r;
				sumi=i;
				k++;
				printf("%d,  ",k);
				for (int j = 0; j <= 30000; ++j)
				{ 	    	
					temp=sumr;
					sumr = sumr*sumr - sumi*sumi;
					sumi = 2*temp*sumi;   
					sumr += r ;
					sumi += i ;
					if(sumi > 2 || sumr > 2 || sumr<-2 || sumr<-2) break;
					x = sumr*750.0+ 1500;  //DA REGOLARE IN BASE ALLE DIMESNIONI DELLO SCHERMO
					y = sumi*-750.0+ 1500;
					if(x<WIDTH && y<HEIGHT && x>=0 && y>=0) screen[x][y]++;
				}
			}
			
		}
		
	}

	ofstream img ("Buddahbrot.ppm");

	img << "P3" << endl;
	img << WIDTH << " " << HEIGHT << endl;
	img << max(screen) << endl;

	printf("Salvando l'immagine: ",j);

	for(int j=0;j<WIDTH;j++){
		for(int k=0;k<HEIGHT;k++){
			if(screen[j][k]!=0){
				int color=screen[j][k];
				img << color << " " << color << " " << color << endl;

			}
			else img << 0 << " " << 0 << " " << 0 << endl;

		}
	}
	return 0;


}