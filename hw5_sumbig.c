#include<stdio.h>
#include<float.h>
#include<limits.h>
#include<string.h>
#include<math.h>

int main(){

FILE *fptr;
char filename[40]="datafile";
int data[50000];
int i,j;
float sum=0;


fptr = fopen(filename,"r");
if(fptr==NULL)printf("bad read");

for(i=0; i<50000; i++){
fscanf(fptr,"%d",&data[i]);
}

//for(i=0; i<10;i++){
//printf("%d\n",data[i]);
//}
fclose(fptr);


for(i=0;i<50000;i++){
sum+=data[i];
}

//printf("total sum of datafile: %f\n",sum);

long int biga, bigb, BIG_INT;


float x;

BIG_INT=INT_MAX;
//printf("Big_int is %d\n",BIG_INT);


biga=((long long)sum/BIG_INT);
bigb=(sum)-(biga*BIG_INT);

printf("\n\t 'biga'= %d and 'bigb'= %ld because\n\n",biga,bigb);
printf("\t SUM = biga * BIG_INT + bigb\n");
printf("\t SUM = %d * %ld + %ld\n",biga, BIG_INT, bigb);
printf("\t SUM = %f\n", sum);

return 0;
}

