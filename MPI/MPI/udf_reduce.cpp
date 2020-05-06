#include <iostream>
#include "mpi.h"
#include<cstdlib>
#include<stdio.h>
#include<ctime>
using namespace std;
int main(int argc, char** argv)
{
	FILE *fp;
	if (( fp = fopen("result2.txt","w"))==NULL)
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

	if(my_rank==0)
	{
		float result[10][10];
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				array[i][j]=0;
			}
		}
		for (size_t i = 1; i < size; i++)
		{
			MPI_Recv(result, 10 * 10, MPI_FLOAT, i, 99, MPI_COMM_WORLD, &status);
			fprintf(fp,"Array %d:\n",i);
			fprintf(stdout,"Array %d:\n",i);
			for (int k = 0; k < 10; k++)
			{
				for (int j = 0; j < 10; j++)
				{
					fprintf(fp,"%9.3g", result[k][j]);
				}
				fprintf(fp,"\n");
			}
			fprintf(fp,"\n");
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (result[i][j] > array[i][j])
				{
					array[i][j]=result[i][j];
				}
			}
		}
		}

	}
	else
	{
		srand(my_rank-1);
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				array[i][j]=(float)rand()/RAND_MAX;
			}
		}
		
		MPI_Send(array,10*10,MPI_FLOAT,0,99,MPI_COMM_WORLD);
	}
	
	if(my_rank==0)
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				fprintf(fp,"%9.3g",array[i][j]);
			}
			fprintf(fp,"\n");
		}
		fflush(fp);
		fclose(fp);
	}

	MPI_Finalize();

	

	return 0;
}
