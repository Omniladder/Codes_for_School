#/bin/bash

if [ $# -ne 1 ]; then
	echo "Needs 1 input to output the size of the diamond"
	exit 0
fi

if [ `expr $1 % 2 ` -eq 0 ]; then
	echo NUMBER MUST BE ODD
	exit 0

fi

star="*"
totalStars="*"

width=`expr $1 / 2`
size=$width

for i in $(seq $size); do

	let "width= $width + 1"
	printf '%*s\n' $width "$totalStars"
	totalStars="$totalStars$star$star"


done

echo "$totalStars"

for i in $(seq $size); do
	length=${#totalStars}
	totalStars="${totalStars:0:`expr length-2`}"
	printf '%*s\n' $width "$totalStars"
	let "width = $width - 1"
done



