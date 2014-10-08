# README: HW5: MACHINE NUMBERS #


AUTHOR: NATHANIEL RALEY
DATE: 10/7/2014
The 4 files included in this source code are c programs for the machine numbers assignment, the fifth homework in STC, Fall 2014. 

### Answers & About ###

The first assignment (hw5_sumbig.c) was to sum 50,000 ~6-digit integers, and then represent this result in the form sum= biga * INT_MAX + bigb, where biga/bigb are integers and INT_MAX is the largest integer you can store in a 32bit integer type (2147483647 in base10). I found that  'biga'= 11 and 'bigb'= 1314373632 because the sum of those 50,000 integers was 24936693760, and INT_MAX divides this number 11 times with 1314373632 as a remainder (SUM = 11 * 2147483647 + 1314373632).

The second part (hw5_fib.c) was to calculate the 50th term in the Fibonacci sequence without using recursion, and to represent this large number using the same biga * INT_MAX + bigb formula used above. I used an iterative method with a temporary variable and found that F50=12586269025, which is representable using biga, bigb, and INT_MAX ('biga'= 5 and 'bigb'= 1848850790) as 
F50 = biga * BIG_INT + bigb, therefore
F50 = 5 * 2147483647 + 1848850790.

The third part (hw5_sumsmall.c) needs some explanation, because it gives out-of-bounds results sometimes. This calculation to be performed was to calculate the series of inverse squares (1/1+1/4+1/9+1/16+...+1/(n^2), where n=10000). First, the series was summed in the order demonstrated above, starting with the largest value and adding increasingly smaller values; then, the same series was summed the opposite way, started with the smallest value (1/(10000^2)) up to 1. At first, I declared my types as long ints and doubles, and my answers were correct, consistent, and exactly the same. Knowing that I was supposed to expect different results, I figured my types were too precise. As soon as I changed them to the plain "int" and "float" types, the results got wacky!
Summing from largest to smallest gives me 1.64472532272339 (but also generates garbage!), while summing from smallest to largest gives me 1.64483404159546 consistently:
```
#!c
login1$ ./a.out
1.64472532272339
1.64483404159546
login1$ ./a.out
1.64472532272339
1.64483404159546
login1$ ./a.out
4575361.00000000000000
1.64483404159546
login1$ ./a.out
1.64472532272339
1.64483404159546
login1$ ./a.out
1.64472532272339
1.64483404159546
login1$ ./a.out
-58356348664156461375422464.00000000000000
1.64483404159546

```

This is because pecision is lost most quickly when the magnitude of the two numbers to be added is greatest. When summing, one of the variables is always the running sum, and if you add from largest to smallest, you end up adding a huge thing (the running sum) to very tiny things (e.g., 1/10000000). This can be minimized by adding the numbers in order from the smallest to the largest in magnitude. When the numbers being summed are too far apart, bits will be discarded!

The fourth part (hw5_sumsmall_mpi.c) is just a parallel implementation of the above program; the task can be split among 2,4,8,10, or 12 processes. Compile using mpicc or the equivalent, and run using ibrun or the equivalent. 

### Who do I talk to? ###

* Nathaniel can be reached by email at nathaniel(dot)raley(at)utexas.edu
