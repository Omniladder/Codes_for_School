#!/bin/bash

for i in *; do

	case $i in 

		*.c)
		gcc $i
			;;
		*.cpp)
		g++ $i
			;;
		*.txt)
		cat $i
			;;
		*)
		echo FILE IS NOT C CPP OR TXT


	esac

done
