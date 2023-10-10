#!/bin/bash
if [ $# -lt 1 ]; then

	echo YOU NEED AT LEAST 1 INTEGER TO RUN THIS
	exit -1

fi

sum=0

for i in $@; do

	if [ ` expr $i % 2 ` -eq 0 ]; then
	
	let "sum= $sum + $i "
	
	fi

done

echo THE FINAL SUM OF ALL EVEN NUMBERS INPUTTED IS $sum

