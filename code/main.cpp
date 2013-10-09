#include <iostream>
#include <cmath>
#include <fstream>
#include <armadillo>
#include "JacobiRotation.h"
#include <ctime>
//#include "getUnixTime.h"

using namespace std;

void exA(int);
void iterationDependency();
double duration(clock_t, clock_t);

int main() {

//	iterationDependency();
	exA(165);

	return 0;
}


void exA(int n) {
	
	int iterations;
	clock_t start, finish;
	start = clock();
	JacobiRotation(n, &iterations);
	finish = clock();
	printf ("Time elapsed: %.2f s\n", duration(start,finish));
//	cout << "Time elapsed: " << "duration << endl;

}

void iterationDependency() {

	int iterations;
	
	fstream outFile;
	outFile.open("data/iterationsData.dat", ios::out);

	for (int n=3; n <= 300; n+=20) {

		JacobiRotation(n,&iterations);
		outFile << n << " " << iterations << endl;

	}

	outFile.close();

}

double duration(clock_t start, clock_t finish) {

	return (finish-start)/((double)CLOCKS_PER_SEC);
}

