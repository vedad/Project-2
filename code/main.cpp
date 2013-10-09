#include <iostream>
#include <cmath>
#include <fstream>
#include <armadillo>
#include "JacobiRotation.h"
#include <ctime>
//#include "getUnixTime.h"

using namespace std;

void exA(int,double);
void iterationDependency();
void rhoMaxDependency();
double duration(clock_t, clock_t);

int main() {

	rhoMaxDependency();
//	iterationDependency();
//	exA(165,4.5);

	return 0;
}


void exA(int n, double rho_max) {
	
	int iterations;
//	double rho_max;

	clock_t start, finish;
	start = clock();
	JacobiRotation(n, &iterations, rho_max);
	finish = clock();
	printf ("Time elapsed: %.2f s\n", duration(start,finish));

}

void iterationDependency() {

	int iterations;
//	double rho_max;
	
	fstream outFile;
	outFile.open("data/iterationsData.dat", ios::out);

	for (int n=3; n <= 300; n+=20) {

		JacobiRotation(n,&iterations,4.5);
		outFile << n << " " << iterations << endl;

	}

	outFile.close();

}

void rhoMaxDependency() {

	int iterations;

	fstream outFile;
	outFile.open("data/rhoMaxData.dat", ios::out);

	for (double rho_max=1; rho_max <= 10; rho_max+=0.5) {
		
		JacobiRotation(100,&iterations,rho_max);
		outFile << rho_max << endl;
	}

	outFile.close();

}

double duration(clock_t start, clock_t finish) {

	return (finish-start)/((double)CLOCKS_PER_SEC);
}

