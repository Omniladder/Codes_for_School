#!/bin/bash

sum=0

for i in $@; do

	let "sum = $sum + $i"

done

echo $sum
