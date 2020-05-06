#include <iostream>
#include "mpi.h"
#include<cstdlib>
#include<stdio.h>
#include<ctime>
using namespace std;
int main(int argc, char** argv)
{
	FILE *fp;
	if (( fp = fopen("result.txt","w"))==NULL)
	{
		fprintf(stderr,"Unable to open the file!");
		exit(0);
	}


	MPI_Init(&argc,&argv);
	int size=0;
	int my_rank=0;

	MPI_Status status;
	MPI_Comm_rank(MPI_COMM_WORLD,&my_rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);

	float array[10][10];

float result[10][10];

		srand(my_rank);
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				array[i][j]=(float)rand()/RAND_MAX;
			}
		}
		
		MPI_Reduce(array,result,10*10,MPI_FLOAT,MPI_MAX,0,MPI_COMM_WORLD);
	
    
    MPI_Barrier(MPI_COMM_WORLD);
	
	if(my_rank==0)
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				fprintf(fp,"%9.3g",result[i][j]);
			}
			fprintf(fp,"\n");
		}
		fflush(fp);
		fclose(fp);
	}

	MPI_Finalize();

	

	return 0;
}
