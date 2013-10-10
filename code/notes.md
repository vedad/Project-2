*** Choosing the smaller of the roots ***
Can see that by choosing t to be the smaller of the roots, we ensure that the
difference between the matrices A and B is the smallest possible. Then c gets
larger, and c^2 in the denominator in the sum gets small, resulting in a smaller
sum. 

Why this means that the theta <= abs(pi/4) I do not know.

*** n_step and dependency on the choice of rho_max ***
--------------------
n = n_step - 1 = 100
--------------------

rho_max = 3:
--------------------------
Eigenvalue no. 1:	3.01023
Eigenvalue no. 2:	7.29531
Eigenvalue no. 3:	12.8108

rho_max = 4:
---------------------------
Eigenvalue no. 1:	2.99952
Eigenvalue no. 2:	7.00016
Eigenvalue no. 3:	11.0594

rho_max = 4.5:
---------------------------
Eigenvalue no. 1:	2.99937
Eigenvalue no. 2:	6.99692
Eigenvalue no. 3:	10.9966

rho_max = 5:
---------------------------
Eigenvalue no. 1:	2.99922
Eigenvalue no. 2:	6.99609
Eigenvalue no. 3:	10.9906

rho_max = 6:
---------------------------
Eigenvalue no. 1:	2.99887
Eigenvalue no. 2:	6.99437
Eigenvalue no. 3:	10.9863

rho_max = 7:
---------------------------
Eigenvalue no. 1:	2.99847
Eigenvalue no. 2:	6.99234
Eigenvalue no. 3:	10.9813

We see that the ideal choice of rho_max lies between 4 and 5 in order for the
numerical eigenvalues to be as close as possible to the analytical ones: 3, 7
and 11. The number of iterations for the different values of rho_max seem to be
about the same: in the 16,000 range. It seems that rho_max = 4.5 seems to be 
optimal.

rho_max = 4.5
n = 200:
---------------------------
Iterations: 66980
Eigenvalue no. 1:	2.99984
Eigenvalue no. 2:	6.99931
Eigenvalue no. 3:	11.0031
---------------------------

n = 250:
---------------------------
Iterations: 105060
Eigenvalue no. 1:	2.9999
Eigenvalue no. 2:	6.9996
Eigenvalue no. 3:	11.0039
---------------------------

n = 300:
---------------------------
Iterations: 151228
Eigenvalue no. 1:	2.99993
Eigenvalue no. 2:	6.99976
Eigenvalue no. 3:	11.0044
---------------------------

We see that some eigenvalues get higher accuracy, but others lower their
accuracy. Operating on larger and larger matrices will not necessarily increase
the accuracy.

It could be wise to plot the number of iterations as function of n, then let
MATLAB do a regression to approximate a polynomial to the curve.
^
Plotted the iterations as function of n. Need to insert this into MATLAB for it
to find us an approximated polynomial. The graph looks like a second order
polynomial that is positive.

Did a polyfit in MATLAB, and plotted the polynomial as function of n. Here
are the polynomial coefficients:

Linear model Poly2:
f(x) = p1*x^2 + p2*x + p3
where x is normalized by mean 143 and std 89.44
Coefficients (with 95% confidence bounds):
p1 =   1.356e+04  (1.35e+04, 1.362e+04)
p2 =   4.298e+04  (4.293e+04, 4.304e+04)
p3 =   3.409e+04  (3.402e+04, 3.417e+04)

Goodness of fit:
SSE: 9.485e+04
R-square: 1
Adjusted R-square: 1
RMSE: 88.91

Also used the Jacobi rotation algorithm for different rho_max. I plotted the
relative difference between numerical and analytical values for the eigenvalues.
From the plot we can see that the smallest errors are for rho_max = 4-10.
By doing another plot for rho_max with these values, we more clearly see
the difference in precision. There is a minimum for rho_max = 4.5.

Have now computed the time it takes for the Jacobi rotation algorithm to find
the eigenvalues of a tridiagonal matrix, compared to the Armadillo function that
uses a standard eigenvalue solver algorithm. The difference in time is major.
For n = 200, the Jacobi algorithm used just under 16 seconds, while the 
Armadillo function used about 0.2 seconds. By using a divide and conquer method
with the same Armadillo function, the time recudes to 0.1 seconds.

Let us compare the time spent for the three methods for some values of n:

n=50:
JRA: 0.07
Arma: 0.00
ArmaDC: 0.00

n=100:
JRA: 0.99
Arma: 0.00
ArmaDC: 0.00

n=150:
JRA: 4.94
Arma: 0.01
ArmaDC: 0.01

n=200:
JRA: 15.61
Arma: 0.02
ArmaDC: 0.01

n=250:
JRA: 37.77
Arma: 0.03
ArmaDC: 0.02

n=300:
JRA: 77.68
Arma: 0.05
ArmaDC: 0.02





