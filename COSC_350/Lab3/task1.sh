
if [ $# -lt 2 ]; then  #input validates
echo enter Input and Output into parameters #prompts user
exit 1 #exits
fi

umask 0000 #sets default permissions

gcc task1.c -o task1 #compiles code

./task1 < $1 > $2 #takes file input and outputs it

rm task1 #cleans out the compiled code

exit 0 #ends
