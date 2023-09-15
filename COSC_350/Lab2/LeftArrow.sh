
#!/bin/bash

Size=$2

if [ `expr $Size % 2` -ne 1 ]; then

echo "enter odd number only for head"
exit 1
fi


for i in $(seq 1 $Size)
do



	if [ $i -le `expr 1 + $Size / 2` ]; then
		for j in $(seq 1 `expr  -2 \* $i + $Size`);
		do
		echo -n " "
		done	
		p=`expr  $i - 1`
		for j in $(seq 1 `expr 1 + 2 \* $p`);
		do
		echo -n "*"
		done

	fi





	if [ $i -gt `expr $Size / 2` ]; then
		
		for j in $(seq 1 `expr  2 \* $i - $Size `);
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
