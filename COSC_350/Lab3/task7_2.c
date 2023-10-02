#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>


int stringToInt(char str){
    int ans = 0;//answer
    int negative = 0;//tracks negative
    int i=0;

    //check for negative
    if(str[i] == '-')
    {
        negative = 1;
     i++;
    }
    //loops through all character of input string
    for( i ; str[i] != '\0'; i++){
        if(str[i] >= '0' && str[i] <= '9'){
            ans = (ans10) + str[i] - '0';
        }
        else{
        return -1;// number error
        }
    }

    if(negative==1){
        return -1ans;
    }
  //return ans
  return ans;
}

int main(int argc, charargv[])
{

    if(argc == 1)
    {
        write(2, "Need an integer\n", 16);
        return 1; // argument error
    }
    int sum = 0;
    int temp = 0;

    for(int i =1; i<argc; i++){
        printf(" num %d: \n", stringToInt(argv[i]));
        sum += stringToInt(argv[i]);
    }
    printf("The sum is %d: \n", sum);
    exit (0);
}
