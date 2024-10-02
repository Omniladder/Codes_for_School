#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "mpi.h"


double* sort(double* arr, int arrLength);
double* merge(double* arr1, int arrLength1 ,double* arr2, int arrLength2);
double** splitArr(double* arr, int arrLength, int splitIndex);

int main(int argc, char** argv)
{
	double t1 = MPI_Wtime();
  srand(time(NULL));

  MPI_Init(&argc, &argv); //Initatiates MPI
  MPI_Comm_set_errhandler(MPI_COMM_WORLD, MPI_ERRORS_RETURN);


  //INPUT VALIDATION
  if(argc <= 2)
  {
  	fprintf(stderr, "Inproper Number of Parameters must have at least 2\n");
	fflush(stderr);
	return -1;
  }

  //Pulls in Arguments
  int m = atoi(argv[1]);
  int n = atoi(argv[2]);


    int numComm = 0;
    MPI_Comm_size(MPI_COMM_WORLD, &numComm);

    int rank = 0;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if(!atoi(argv[1]) && !atoi(argv[2]) && atoi(argv[1]) >= 0 && atoi(argv[2]) >= 0)
    {
        printf("Invalid Parameter\n");
        return -1;
    }

	int* productArray = (int*)malloc(n * sizeof(int));
	if(rank == 0) //Code for parent node
    {
    	int **arr = (int **)malloc(m * sizeof(int*)); //Dynamically allocates an array of pointers too allow a 2D array to be created
		
		

    	for(int i = 0; i < m; i++)
    	{
	    arr[i] = (int *)malloc(n * sizeof(int)); //creates each sub array of 2D array
    	}
		for(int x = 0; x < m; x++)//Iterates through each element of the 2D array
    	{
			for(int y = 0; y < n; y++)
			{
				arr[x][y] = rand() % 5 + 1; //Sets each value to a random one
			}
    	}
		
    	productArray = arr[0];
	for(int i = 1; i < m; i++)
    	{
	  	 MPI_Send(arr[i], n, MPI_INT, i, 1, MPI_COMM_WORLD); //Sends data
    	}
    }
    else //children node code
    {
		MPI_Status status;
		MPI_Recv(productArray, n, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);
    }

double average = 0;

	for(int i = 0; i < n; i++)
	{
		average += productArray[i] * 1.0; //Sums together * 1.0 to keep it all in decimals
	}
	
	average /= n;
	
	if(rank == 0)
	{
//		double averages[m];
		double* averages = (double*)malloc(sizeof(double) * m);
		averages[0] = average;
		double* newAvgBuf = (double*)malloc(sizeof(double));
		for(int i = 1; i < m; i++)
		{
			MPI_Status status;
			MPI_Recv(newAvgBuf, 1, MPI_DOUBLE, i, 2, MPI_COMM_WORLD, &status);
			averages[i] = newAvgBuf[0];
		}
		averages = sort(averages, m);
		for(int i = 0; i < m; i++)
		{
			printf("%dth highest Avg: %.1f\n", i + 1, averages[i]);
		}
		double t2 = MPI_Wtime();

		printf("MPI run time: %4.1f\n", t2-t1);
	}
	else
	{
		double* averageBuf = (double*)malloc(sizeof(double));
		averageBuf[0] = average;
		MPI_Send(averageBuf, 1, MPI_DOUBLE, 0, 2, MPI_COMM_WORLD);
	}

  MPI_Finalize();

   return 0;
}


double** splitArr(double* arr, int arrLength, int splitIndex)
{
	double** arrays = (double **)malloc(sizeof(double*) * 2);
	arrays[0] = (double*)malloc(sizeof(double) * (arrLength / 2 ));
	arrays[1] = (double*)malloc(sizeof(double) * (arrLength - arrLength / 2 ));

	for(int i = 0; i < arrLength / 2; i++)
	{
		arrays[0][i] = arr[i];
	}

	for(int i = arrLength / 2; i < arrLength; i++)
	{
		arrays[1][i - arrLength / 2] = arr[i];
	}
	return arrays;
}

double* merge(double* arr1, int arrLength1 ,double* arr2, int arrLength2)
{
	double* doublearr3 = (double*)malloc(sizeof(double*) * (arrLength1 + arrLength2));
	
	int index1 = 0;
	int index2 = 0;

	for(int index3 = 0; index3 < arrLength1 + arrLength2; index3++)
	{
		if(arr1[index1] < arr2[index2])
		{
			doublearr3[index3] = arr2[index2];
			index2++;
		}
		else
		{
			doublearr3[index3] = arr1[index1];
			index1++;
		}
	}
	return doublearr3;
}

//Merge Sort Algorithm
double* sort(double* arr, int arrLength)
{
	if(arrLength == 1)
	{
		return arr;
	}

	double** splitArrays = splitArr(arr, arrLength, arrLength/2);


	splitArrays[0] = sort(splitArrays[0], arrLength / 2);
	splitArrays[1] = sort(splitArrays[1], arrLength - (arrLength / 2 ));

	arr = merge(splitArrays[0], arrLength / 2, splitArrays[1], arrLength - (arrLength / 2));

	

	return arr;
}
