#include <stdio.h>

int main(){
    int i, j,k, hprod=0,prod,vprod[10];
    for (i=100;i<1000;i++)
    {
        for (j=100;j<1000;j++)
        {
            prod=i*j;
            /*if(prod>hprod)
            {
                hprod=prod;*/
                for(k=0;k<6;k++)
                {
                    vprod[k]=prod%10;
                    prod/=10;
                }
                if(vprod[0]==vprod[5] && vprod[1]==vprod[4] && vprod[2]==vprod[3])
                {
                    for(k=5;k>=0;k--)
                    {
                        printf("%d",vprod[k]);
                    }
                    printf("\n");
                }
            //}
        }
    }
}