numofArguments=$#
input=$1
answer=0

if [[ $numofArguments -ne 1 ]]; then
	echo "must enter 1 argument"
	exit 1
fi

if [[ ! $input =~ ^[0-9]+$ ]]; then
	echo "must be integer in parameters"
        exit 1
fi


while [ $input -gt 0 ]
do
	answer=$((answer + ((input % 10))))
        input=$((input / 10))

done

echo -n "The sum of digits is "
echo $answer

