#include <stdio.h>

int main(){
    unsigned long long int i, n, c1=0,c2=0;
    for (i=1;i<1000000;i++)
    {
        n=i;
        while(n!=1)
        {
            if(n%2==0)
            {
                n/=2;
                c1++;
            }
            else
            {
                n=3*n+1;
                c1++;
            }
        }
        if(c1>c2)
        {
            printf("%llu %llu\n",i,c1);
            c2=c1;
        }
        c1=0;
    }
}