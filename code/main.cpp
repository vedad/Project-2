#include <iostream>
#include <cmath>
#include <fstream>
#include <armadillo>
#include "JacobiRotation.h"
#include "EigenvalueSOlver.hpp"
#include <ctime>

using namespace std;
using namespace arma;

void exA(int, double);
void exB(int, double);
void iterationDependency();
void rhoMaxDependency(int);
void nDependency(double);
double duration(clock_t, clock_t);

int main() {

	nDependency(5.0);
//	rhoMaxDependency(175);
//	iterationDependency();
//	exA(150,4.5);
//	exB(300,4.5);

	return 0;
}


void exA(int n, double rho_max) {
	
	int iterations;

	clock_t start, finish;
	start = clock();
	JacobiRotation(n, &iterations, rho_max);
	finish = clock();
	printf ("Time elapsed for Jacobi algorithm: %.2f s\n", duration(start,finish));

}

void exB(int n, double rho_max) {
	
	clock_t start, finish;
	start = clock();
	EigenvalueSolver(n, rho_max);
	finish = clock();
	printf ("Time elapsed for Armadillo function: %.2f s\n", duration(start,finish));


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
	double firstEig = 3.0000;
	double secondEig = 7.0000;
	double thirdEig = 11.0000;

	fstream outFile;
	outFile.open("data/rhoMaxData2.txt", ios::out);

	for (double rho_max=4; rho_max <= 10; rho_max+=0.5) {
		
		sortEigenvals = JacobiRotation(n,&iterations,rho_max);
	
		// Calculate relative difference from exact solution
		double relDiffFirstEig = abs(firstEig - sortEigenvals(0));
		double relDiffSecondEig = abs(secondEig - sortEigenvals(1));
		double relDiffThirdEig = abs(thirdEig - sortEigenvals(2));

		outFile << rho_max << " " << relDiffFirstEig << " " << relDiffSecondEig << " " << relDiffThirdEig << endl;

	}

	outFile.close();

}

void nDependency(double rho_max) {

	int iterations;
	
	double firstEig = 3.0000;
	double secondEig = 7.0000;
	double thirdEig = 11.0000;

	fstream outFile;
	outFile.open("data/nData3.txt", ios::out);

	for (int n=150; n <= 300; n+=15) {

		vec sortEigenvals(n);
		sortEigenvals = JacobiRotation(n,&iterations,rho_max);

		double relDiffFirstEig = abs(firstEig - sortEigenvals(0));
		double relDiffSecondEig = abs(secondEig - sortEigenvals(1));
		double relDiffThirdEig = abs(thirdEig - sortEigenvals(2));

		outFile << n << " " << sortEigenvals(0) << " " << sortEigenvals(1) << " " << sortEigenvals(2) << endl;
	}

	outFile.close();

}

double duration(clock_t start, clock_t finish) {

	return (finish-start)/((double)CLOCKS_PER_SEC);
}

