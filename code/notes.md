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





