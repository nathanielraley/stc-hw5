#include<stdio.h>
#include<float.h>
#include<limits.h>
#include<string.h>
#include<math.h>

int main(){

int i,j;
long long int first,second,temp;
float sum=0;



first=1;
second=1;
for(i=2;i<50;i++){
temp=first;
first+=second;
second=temp;
}

printf("\nThe 50th fibonacci number is: %ld\n\n",first);

long int biga, bigb, BIG_INT;




float x;

BIG_INT=INT_MAX;
//printf("Big_int is %d\n",BIG_INT);


biga=((long long)first/BIG_INT);
bigb=(first)-(biga*BIG_INT);

printf("\t 'biga'= %d and 'bigb'= %ld because\n",biga,bigb);
printf("\t F50 = biga * BIG_INT + bigb, therefore\n");
printf("\t F50 = %d * %ld + %ld\n",biga, BIG_INT, bigb);
printf("\t F50 = %ld\n", first);

return 0;
}

