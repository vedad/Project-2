import numpy as np
import matplotlib.pyplot as plt
#from matplotlib import rc
"""
rc('font',**{'family':'sans-serif','sans-serif':['Helvetica']})
## for Palatino and other serif fonts use:
#rc('font',**{'family':'serif','serif':['Palatino']})
rc('text', usetex=True)
"""

def read():

	inFile = open("data/rhoMaxData.txt", 'r')

	global _rhoMax; _rhoMax = []
	global _relDiffFirstEig; _relDiffFirstEig = []
	global _relDiffSecondEig; _relDiffSecondEig = []
	global _relDiffThirdEig; _relDiffThirdEig = []

	for line in inFile:
		columns = line.split()
		_rhoMax.append(float(columns[0]))
		_relDiffFirstEig.append(float(columns[1]))
		_relDiffSecondEig.append(float(columns[2]))
		_relDiffThirdEig.append(float(columns[3]))

	inFile.close()


read()

#plt.rc('text', usetex=True)
#plt.rc('font', family='serif')

fig = plt.figure()
ax = fig.add_subplot(111)
ax.plot(_rhoMax, _relDiffFirstEig, '.', linestyle='-',
label='$\lambda = 3$')
plt.hold('on')
ax.plot(_rhoMax, _relDiffSecondEig, '.', linestyle='-',
label='$\lambda = 7$')
ax.plot(_rhoMax, _relDiffThirdEig, '.', linestyle='-',
label='$\lambda = 11$')
plt.hold('off')
fig.suptitle('Relative difference between numerical and exact eigenvalues', fontsize='14')
ax.set_xlabel('$\\rho_{max}$', fontsize='16')
ax.set_ylabel('Relative difference', fontsize='14')
ax.legend(loc='best')
plt.grid('on')
plt.show()


