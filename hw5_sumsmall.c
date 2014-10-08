#include<stdio.h>
#include<math.h>

/*note that using floats and ints results in overflow, 
but if I switch these to long ints and doubles, the two loops
evaluate to the same thing; since we were supposed to have 
different results, I keep the types small*/

int main(){
float sum, sum1;
int i, j;

for(i=1;i<=10000;i++){
sum+=1./(i*i);
}

printf("%.14f\n",sum);

for(j=10000;j>=1;j--){
sum1+=1./(j*j);
}

printf("%.14f\n",sum1);


return 0;
}
