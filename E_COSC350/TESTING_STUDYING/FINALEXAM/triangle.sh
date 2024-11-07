#!/bin/bash

if [ $# -ne  1 ]; then

	echo Please only Input 1 number
	exit -1
fi


for i in $(seq $1); do

	for j in $(seq `expr $1 - $i`); do

		echo -n " "

	done

	for j in $(seq `expr $i \* 2 - 1`); do
	
		echo -n "*"

	done

	echo ""

done
