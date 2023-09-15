#!/bin/bash

number=$1

timeRan=1
answer=1

while [ $timeRan -le $number ]; do

answer=$((answer*timeRan))
timeRan=$((timeRan+1))


done

echo $answer
exit 0
