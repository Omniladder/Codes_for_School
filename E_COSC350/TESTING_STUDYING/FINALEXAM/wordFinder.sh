#!/bin/bash

if [ $# -ne 2 ]; then
	echo ONLY INPUT 1 TERM TO SEARCH FOR and then 1 filename
	exit -1
fi

if [ ! -e $2 ]; then
	echo FILE DOESNT EXIST
	exit -1
fi

grep -n "$1" $2
