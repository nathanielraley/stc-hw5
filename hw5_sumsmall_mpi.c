#include <stdio.h>
#include <mpi.h>
#include <math.h>

int main(int argc, char *argv[])
{
	int NNN=10000;
        int myrank, size;
	long int localstart=1, localend;
	double localsum=0.0;
	double sum=0.0;
        double h,x;
	int i,j;

	// Initilize Mpi and local rank and size
        MPI_Init(&argc, &argv);
        MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
        MPI_Comm_size(MPI_COMM_WORLD, &size);

        if(myrank==0)
	
  printf("\n");	
 	if(myrank==12){NNN=10008;}
	//Different MPI Tasks are doing different jobs!!!
        localstart=NNN/size * myrank +1; 
	localend=NNN/size * (myrank +1 );

h=1.0/(double)NNN;

//printf("h=%f",h);

for(i=localstart;i<=localend;i++){
localsum+=1./(i*i);
}

printf("%.15lf\n",localsum);

//printf("localsum=%lf",localsum);
 
	MPI_Reduce(&localsum, &sum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
	if(myrank==0)

		printf("\n The value of the sum 1/[x^2] from x=1 to 10000 is %.15lf, approximately (pi^2)/6\n", sum);

        MPI_Finalize();
        return 0;
}



