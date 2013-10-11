import numpy as np

def read():

	inFile = open("data/iterationsData.txt",'r')

	global _n; _n = []
	global _iterations; _iterations = []

	for line in inFile:
		columns = line.split()
		_n.append(float(columns[0]))
		_iterations.append(float(columns[1]))

	inFile.close()

read()
print np.polyfit(_n,_iterations,2)

