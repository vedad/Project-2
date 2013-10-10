#include <iostream>
#include <cmath>
#include <fstream>
#include <armadillo>
#include "JacobiRotation.h"
#include <ctime>
//#include "getUnixTime.h"

using namespace std;
using namespace arma;

void exA(int,double);
void iterationDependency();
void rhoMaxDependency(int);
double duration(clock_t, clock_t);

int main() {

	rhoMaxDependency(150);
//	iterationDependency();
//	exA(165,4.5);

	return 0;
}


void exA(int n, double rho_max) {
	
	int iterations;

	clock_t start, finish;
	start = clock();
	JacobiRotation(n, &iterations, rho_max);
	finish = clock();
	printf ("Time elapsed: %.2f s\n", duration(start,finish));

}

void iterationDependency() {

	int iterations;
	
	fstream outFile;
	outFile.open("data/iterationsData.dat", ios::out);

	for (int n=3; n <= 300; n+=20) {

		JacobiRotation(n,&iterations,4.5);
		outFile << n << " " << iterations << endl;

	}

	outFile.close();

}

void rhoMaxDependency(int n) {

	int iterations;
	vec sortEigenvals(n);
	double firstEig = 3.00;
	double secondEig = 7.00;
	double thirdEig = 11.00;

	fstream outFile;
	outFile.open("data/rhoMaxData.txt", ios::out);

	for (double rho_max=1; rho_max <= 10; rho_max+=0.5) {
		
		sortEigenvals = JacobiRotation(n,&iterations,rho_max);
	
		// Calculate relative difference from exact solution
		double relDiffFirstEig = abs(firstEig - sortEigenvals(0));
		double relDiffSecondEig = abs(secondEig - sortEigenvals(1));
		double relDiffThirdEig = abs(thirdEig - sortEigenvals(2));

		outFile << rho_max << " " << relDiffFirstEig << " " << relDiffSecondEig << " " << relDiffThirdEig << endl;

	}

	outFile.close();

}

double duration(clock_t start, clock_t finish) {

	return (finish-start)/((double)CLOCKS_PER_SEC);
}

