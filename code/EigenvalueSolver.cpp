/*
 * =====================================================================================
 *
 *       Filename:  EigenvalueSolver.cpp
 *
 *    Description:  Program that finds the eigenvalues of a symmetric matrix using the
 *				    Armadillo function eig_sym().
 *
 *        Version:  1.0
 *        Created:  10/10/2013 14:12:26
 *       Revision:  none
 *       Compiler:	c++ 
 *
 *         Author:  Vedad Hodzic (VH), vedadh@student.matnat.uio.no
 *   Organization:  Student, University of Oslo
 *
 * =====================================================================================
 */

#include <iostream>
#include <armadillo>
#include "EigenvalueSolver.hpp"

using namespace std;
using namespace arma;

vec EigenvalueSolver(int n, double rho_max) {

	vec diagonal(n);
	vec offDiagonal(n-1);
	vec rho(n);
	vec V(n);
	
	double rho_min = 0.0;
//	double rho_max = 4.5;

	// Step size
	double h = (rho_max - rho_min)/(n+1);

	double e = -1./(h*h);

	for (int i=0; i<(n-1); i++) {

		offDiagonal(i) = e;
	}
	
	for (int i=0; i < n; i++) {

		rho(i) = rho_min + (i+1) * h;
		V(i) = rho(i) * rho(i);
		diagonal(i) = 2./(h * h) + V(i);

	}

	mat A = zeros<mat>(n,n);
	
	A.diag() = diagonal;
	A.diag(1) = offDiagonal;
	A.diag(-1) = offDiagonal;

	vec eigenVals;
	mat eigenVecs;

	eig_sym(eigenVals, eigenVecs, A, "dc");

	vec sortEigenvals = eigenVals;
	
	for (int i=0; i<3; i++) {

		cout << "Eigenvalue no. " << i+1 << ":	" << sortEigenvals(i) << endl; 
		
	}

	return sortEigenvals;

}
