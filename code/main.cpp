#include <iostream>
#include <cmath>
#include <fstream>
#include <armadillo>
#include "JacobiRotation.h"
#include "EigenvalueSOlver.hpp"
#include <ctime>

using namespace std;
using namespace arma;

void exA(int, double, double);
void exB(double);
void exC(int, double, double);
void iterationDependency(double);
void rhoMaxDependency(int,double);
void nDependency(double, double);
double duration(clock_t, clock_t);

int main() {

//	nDependency(5.0);
//	rhoMaxDependency(210);
//	iterationDependency();
//	exA(150,4.5);
//	exB(5.0);
	exC(210,4.5,5.0);

	return 0;
}


void exA(int n, double rho_max, double omegaR) {
	
	int iterations;

	clock_t start, finish;
	start = clock();
	JacobiRotation(n, &iterations, rho_max, omegaR);
	finish = clock();
	printf ("Time elapsed for Jacobi algorithm: %.2f s\n", duration(start,finish));

}

void exB(double rho_max) {

	double firstEig = 3.0000;
	double secondEig = 7.0000;
	double thirdEig = 11.0000;
	
	clock_t start, finish;
	start = clock();

	fstream outFile;
	outFile.open("data/armaData.txt", ios::out);

	for (int n=150; n <= 300; n+=10) {

		vec sortEigenvals(n);
		sortEigenvals =	EigenvalueSolver(n, rho_max);

		double relDiffFirstEig = abs(firstEig - sortEigenvals(0));
		double relDiffSecondEig = abs(secondEig - sortEigenvals(1));
		double relDiffThirdEig = abs(thirdEig - sortEigenvals(2));

		outFile << n << " " << relDiffFirstEig << " " << relDiffSecondEig << " " << relDiffThirdEig << endl;

	}

	outFile.close();
	finish = clock();
	printf ("Time elapsed for Armadillo function: %.2f s\n", duration(start,finish));


}

void exC(int n, double rho_max, double omegaR) {

	int iterations;

	JacobiRotation(n,&iterations,rho_max,omegaR);

}	


void iterationDependency(double omegaR) {

	int iterations;
	
	fstream outFile;
	outFile.open("data/iterationsData.dat", ios::out);

	for (int n=3; n <= 300; n+=20) {

		JacobiRotation(n,&iterations,4.5,omegaR);
		outFile << n << " " << iterations << endl;

	}

	outFile.close();

}

void rhoMaxDependency(int n, double omegaR) {

	int iterations;
	vec sortEigenvals(n);
	double firstEig = 3.0000;
	double secondEig = 7.0000;
	double thirdEig = 11.0000;

	fstream outFile;
	outFile.open("data/rhoMaxData2.txt", ios::out);

	for (double rho_max=4; rho_max <= 10; rho_max+=0.5) {
		
		sortEigenvals = JacobiRotation(n,&iterations,rho_max,omegaR);
	
		// Calculate relative difference from exact solution
		double relDiffFirstEig = abs(firstEig - sortEigenvals(0));
		double relDiffSecondEig = abs(secondEig - sortEigenvals(1));
		double relDiffThirdEig = abs(thirdEig - sortEigenvals(2));

		outFile << rho_max << " " << relDiffFirstEig << " " << relDiffSecondEig << " " << relDiffThirdEig << endl;

	}

	outFile.close();

}

void nDependency(double rho_max,double omegaR) {

	int iterations;
	
	double firstEig = 3.0000;
	double secondEig = 7.0000;
	double thirdEig = 11.0000;

	fstream outFile;
	outFile.open("data/nData2.txt", ios::out);

	for (int n=150; n <= 300; n+=15) {

		vec sortEigenvals(n);
		sortEigenvals = JacobiRotation(n,&iterations,rho_max,omegaR);

		double relDiffFirstEig = abs(firstEig - sortEigenvals(0));
		double relDiffSecondEig = abs(secondEig - sortEigenvals(1));
		double relDiffThirdEig = abs(thirdEig - sortEigenvals(2));

		outFile << n << " " << relDiffFirstEig << " " << relDiffSecondEig << " " << relDiffThirdEig << endl;
	}

	outFile.close();

}

double duration(clock_t start, clock_t finish) {

	return (finish-start)/((double)CLOCKS_PER_SEC);
}

