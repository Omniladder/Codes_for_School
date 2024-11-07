#!/bin/bash

echo "ENTER a Directory"

read direct

if [ ! -d $direct ]; then #Check for valid Directory
	echo no such directory
	exit 1
fi

echo Enter a Readable file in said Directory

read file
numTimes=1
while  [ ! -e $file -o ! -r $file ] && [ ! $numTimes -gt 2 ]; do
if [ ! -e $file -o ! -r $file ]; then
	echo INVALID FILE
	read file
	let "numTimes++"
else
	break
fi
done

if [ $numTimes -gt 2 ]; then
	if [ ! -e $file ]; then
	
	echo "no such file (after 3 attempts)"
	exit 2
	else
		echo FILE NOT READABLE
		exit 3
	fi

fi

echo Enter Word to search for

read word

if  grep -q $word $file ; then
	echo "FOUND!"	
else
	echo "NOT FOUND"
	exit 4
fi

exit 0
