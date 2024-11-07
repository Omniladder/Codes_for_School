#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "mpi.h"


double* sort(double* arr, int arrLength, int* indexes);
double* merge(double* arr1, int arrLength1 ,double* arr2, int arrLength2, int* indexes, int** newIndexes);
double** splitArr(double* arr, int arrLength, int splitIndex, int* indexes, int** newIndexes);

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
    else if (rank < m) //children node code
    {
		MPI_Status status;
		MPI_Recv(productArray, n, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);
    }

double average = 0;

	/*
		Dr. Jing The reason why my code doesn't overflow as fast is because I used a double which has a mantissa of 53 comapared to ints 32 bits most people kept sum in an
		int which overflowed faster I also modified the code the a bit by distributing the / n over the sum you keep the terms smaller which means the full sum is smaller and
		therefore overflows later
	*/

	for(int i = 0; i < n; i++)
	{
		average += productArray[i] / (n * 1.0); //Sums together * 1.0 to keep it all in decimals
	}
	
	free(productArray);
	
	if(rank == 0)
	{
//		double averages[m];
		double* averages = (double*)malloc(sizeof(double) * m);
		averages[0] = average;
		double* newAvgBuf = (double*)malloc(sizeof(double));
		int* indexes = (int*)malloc(sizeof(int) * m);
		indexes[0] = 0;
		for(int i = 1; i < m; i++)
		{
			MPI_Status status;
			MPI_Recv(newAvgBuf, 1, MPI_DOUBLE, i, 2, MPI_COMM_WORLD, &status);
			averages[i] = newAvgBuf[0];
			indexes[i] = i;
		}
		averages = sort(averages, m, indexes);
		for(int i = 0; i < m; i++)
		{
			printf("%d Average is: %.1f\n", indexes[i], averages[i]);
		}
		double t2 = MPI_Wtime();

		printf("MPI run time: %4.1f\n", t2-t1);
		
		free(averages);
		free(newAvgBuf);
		free(indexes);
	}
	else if (rank <= m)
	{
		double* averageBuf = (double*)malloc(sizeof(double));
		averageBuf[0] = average;
		MPI_Send(averageBuf, 1, MPI_DOUBLE, 0, 2, MPI_COMM_WORLD);
		free(averageBuf);
	}


  MPI_Finalize();

   return 0;
}


double** splitArr(double* arr, int arrLength, int splitIndex, int* indexes, int** newIndexes)
{
	double** arrays = (double **)malloc(sizeof(double*) * 2);
	arrays[0] = (double*)malloc(sizeof(double) * (arrLength / 2 ));
	arrays[1] = (double*)malloc(sizeof(double) * (arrLength - arrLength / 2 ));

	for(int i = 0; i < arrLength / 2; i++)
	{
		arrays[0][i] = arr[i];
		newIndexes[0][i] = indexes[i];
	}

	for(int i = arrLength / 2; i < arrLength; i++)
	{
		arrays[1][i - arrLength / 2] = arr[i];
		newIndexes[1][i - arrLength / 2] = indexes[i];
	}
	return arrays;
}

double* merge(double* arr1, int arrLength1 ,double* arr2, int arrLength2, int* indexes, int** newIndexes)
{
	double* doublearr3 = (double*)malloc(sizeof(double*) * (arrLength1 + arrLength2));
	
	int index1 = 0;
	int index2 = 0;

	for(int index3 = 0; index3 < arrLength1 + arrLength2; index3++)
	{
		if(arr1[index1] < arr2[index2])
		{
			doublearr3[index3] = arr2[index2];
			indexes[index3] = newIndexes[1][index2];
			index2++;
		}
		else
		{
			doublearr3[index3] = arr1[index1];
			indexes[index3] = newIndexes[0][index1];
			index1++;
		}
	}
	free(arr1);
	free(arr2);
	return doublearr3;
}

//Merge Sort Algorithm
double* sort(double* arr, int arrLength, int* indexes)
{
	if(arrLength == 1)
	{
		return arr;
	}

	int** newIndexes = (int**)malloc(sizeof(int*) * 2);
	newIndexes[0] = (int*)malloc(sizeof(int) * arrLength / 2);
	newIndexes[1] = (int*)malloc(sizeof(int) * arrLength / 2);

	double** splitArrays = splitArr(arr, arrLength, arrLength/2, indexes, newIndexes);


	splitArrays[0] = sort(splitArrays[0], arrLength / 2, indexes);
	splitArrays[1] = sort(splitArrays[1], arrLength - (arrLength / 2 ), indexes);

	arr = merge(splitArrays[0], arrLength / 2, splitArrays[1], arrLength - (arrLength / 2), indexes, newIndexes);

	free(newIndexes[0]);
	free(newIndexes[1]);

	return arr;
}
