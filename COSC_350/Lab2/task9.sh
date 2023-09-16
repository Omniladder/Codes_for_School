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
while [ $numTimes -lt 3 -a ! -e $file ]; do
if [ ! -e $file ]; then
	echo INVALID FILE
	read file
	let "numTimes++"
fi
done

if [ $numTimes -eq 3 ]; then
	echo "no such file (after 3 attempts)"
	exit 2
fi

if [ ! -r $file ]; then
	echo "FILE ISN'T READABLE"
	exit 3
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
