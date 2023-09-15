#!/bin/bash

Size=$1

if [ `expr $Size % 2` -ne 1 -o $Size -le 3 ]; then

echo "enter odd number only greater than 3"
exit 1
fi

for i in $(seq 1 $Size)
do
	if [ $i -le `expr 1 + $Size / 2` ]; then
		for j in $(seq 1 `expr  $Size / 2 - $i + 1`);
		do
		echo -n " "
		done	
		p=`expr  $i - 1`
		for j in $(seq 1 `expr 1 + 2 \* $p`);
		do
		echo -n "*"
		done
	fi

	if [ `expr $Size / 2 + 1 ` -eq $i ]; then
	echo ""
	fi


	if [ $i -gt `expr $Size / 2` ]; then
		
		for j in $(seq 1 `expr $i - $Size / 2`);
		do
		echo -n " "
		done	

		p=`expr  $i - $Size / 2`
		
		for j in $(seq 1 `expr $Size - 2 \* $p `);
		do
		echo -n "*"
		done

	fi
echo ""
done

exit 0

Size=$1

if [ `expr $Size % 2` -ne 1 -o $Size -le 3 ]; then

echo "enter odd number only greater than 3"
exit 1
fi

for i in $(seq 1 $Size)
do
	if [ $i -le `expr 1 + $Size / 2` ]; then
		for j in $(seq 1 `expr  $Size / 2 - $i + 1`);
		do
		echo -n " "
		done	
		p=`expr  $i - 1`
		for j in $(seq 1 `expr 1 + 2 \* $p`);
		do
		echo -n "*"
		done
	fi

	if [ `expr $Size / 2 + 1 ` -eq $i ]; then
	echo ""
	fi


	if [ $i -gt `expr $Size / 2` ]; then
		
		for j in $(seq 1 `expr $i - $Size / 2`);
		do
		echo -n " "
		done	

		p=`expr  $i - $Size / 2`
		
		for j in $(seq 1 `expr $Size - 2 \* $p `);
		do
		echo -n "*"
		done

	fi
echo ""
done

exit 0
