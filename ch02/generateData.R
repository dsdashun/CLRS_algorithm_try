#!/usr/local/bin/R --slave -f
write(runif(100000, -10000, 10000), sep="\n")
