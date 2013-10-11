import numpy as np
import matplotlib.pyplot as plt

def read():

	inFile = open("data/armaData.txt", 'r')

	global _n; _n = []
	global _relDiffFirstEig; _relDiffFirstEig = []
	global _relDiffSecondEig; _relDiffSecondEig = []
	global _relDiffThirdEig; _relDiffThirdEig = []

	for line in inFile:
		columns = line.split()
		_n.append(float(columns[0]))
		_relDiffFirstEig.append(float(columns[1]))
		_relDiffSecondEig.append(float(columns[2]))
		_relDiffThirdEig.append(float(columns[3]))

	inFile.close()


read()

fig = plt.figure()
ax = fig.add_subplot(111)
ax.plot(_n, _relDiffFirstEig, '.', linestyle='-',
label='$\lambda = 3$')
plt.hold('on')
ax.plot(_n, _relDiffSecondEig, '.', linestyle='-',
label='$\lambda = 7$')
ax.plot(_n, _relDiffThirdEig, '.', linestyle='-',
label='$\lambda = 11$')
plt.hold('off')
fig.suptitle('Relative difference between numerical and exact\n eigenvalues' \
		'using the Armadillo function', fontsize='14')
ax.set_xlabel('$n$', fontsize='16')
ax.set_ylabel('Relative difference', fontsize='14')
ax.legend(loc='best')
plt.grid('on')
plt.show()


