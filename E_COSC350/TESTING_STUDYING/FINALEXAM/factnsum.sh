#!/bin/bash

if [ $# -ne 1 ]; then
	echo "INPUT PROPER NUMBER OF Inputs \n"
	exit 0
fi

sum=0
fact=1

for i in $(seq $1); do

	let "sum= $sum + $i"
	let "fact= $fact * $i"
done

echo "Sum is $sum factorial is $fact"
