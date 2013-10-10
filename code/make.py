"How does one use this crap?"

import os,sys
os.system('c++ -c *.cpp')
os.system('c++ -o %s.x -larmadillo -lblas -llapack *.o' % sys.argv[1])
