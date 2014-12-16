/*

This program computes the sum S = Sum(k=0:N,k^(-4))
with increasing N in order to reach machine epsilon precision
*/

#include <stdio.h>
#include <math.h>

// evaluates machine epsilon
float macheps_eval(void)
{
    float macheps =1.;
    while((float)(1. + macheps)!=1.)
    {
        macheps /= 2;   
    }
    return macheps;
}

// chore
int main(void)
{
    float sum = 0., exact  = pow(M_PI,4)/90.0;
    float err = 1., errmax = 3*macheps_eval();
    long N,k;
    
    for(N=10L;err > errmax;N *=2)	// repeat the process with twice more terms as long as the error is too high
    {
        for(k=N;k>0L;k--)           // adding smaller terms first to keep maximal precision
            sum += pow(k,-4);
        err = fabs(sum-exact);		// comparing result with exact solution for error
        printf("%ld %f %f\n",N,sum,err);	// printing results
        sum = 0.;					// reset sum for next iteration
    }
    return 0;
}
