#!/usr/bin/python
import random
elemNum = 100000
f = open("largeData.txt", 'w+')
for _ in xrange(1, elemNum):
    f.write('%f\n' % (random.uniform(-10000, 10000),))
f.close()
