#!/bin/bash

for i in *;  do

	case $i in 
		*.cpp)
	exec g++ $i
	;;

		*.c)
	exec gcc $i
	;;

		*.txt)
	exec cat $i
	;;

		*)
	echo NOT A TXT C OR CPP
	;;
	esac
done

