
#!/bin/bash

Tail=$1
Size=$2

if [ `expr $Size % 2` -ne 1 ]; then

echo "enter odd number only greater than 3"
exit 1
fi

for i in $(seq 1 $Size)
do
	if [ $i -le `expr  $Size / 2` ]; then
		for j in $(seq 1 $Tail);
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
		for j in $(seq 1 `expr $Size + $Tail`);
		do
		echo -n "*"
		done
		echo ""
		else
		for j in $(seq 1 $Tail); do
		echo -n " "
		done

	fi

	if [ `expr $Size / 2 + 1` -eq $i ]; then
		for j in $(seq 1 $Tail); do
                  echo -n " "
                  done


	fi

	if [ $i -gt `expr $Size / 2` ]; then
		
		for j in $(seq 1 `expr $i - $Size / 2`);
		do
		echo -n ""
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

