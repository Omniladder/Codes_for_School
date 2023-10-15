#!/bin/bash

if [ $# -lt 1 ]; then
	echo INPUT IN 1 OR MORE INTEGERS
	exit -1
fi

sum=0

for i in $@; do
	
	if [ ` expr $i % 2 ` -eq 0 ]; then
	let "sum= $i + $sum"
	fi

done


echo SUM OF EVEN INTEGERS IS $sum

exit 0

