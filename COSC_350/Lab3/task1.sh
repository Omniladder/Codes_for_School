
if [ $# -lt 2 ]; then
echo enter Input and Output into parameters
exit 1
fi

umask 0000

gcc task1.c -o task1

./task1 < $1 > $2

exit 0
