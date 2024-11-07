#!/bin/bash


for i in *; do

	case $i in 
		*.cpp ) g++ -o "prog1" $i ;;
		*.c ) gcc -o "prog2" $i;;
		*.txt ) cat $i;;
		* ) echo NOT A TXT CPP OR C FILE ;;
	esac

done
