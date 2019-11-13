#include<stdio.h>
#include<math.h>
#define N 10000

int den[10000];
int num[10000];
int q;
int n;
int cont;
int max;

int repete() {
  if (num[q]==num[0] && den[q]==den[0]) return 1;
  return 0;
}

void calc() {
  int a = den[q];
  int d = (n-den[q]*den[q])/num[q];
  int a0 = (sqrt(n)+a)/d;  
 
  q++;
  den[q]= -a+a0*d;
  num[q]= d;
  //printf("%d\n", a0); 
  if(repete()) {
     //printf("Periodo %d\n", q);
     if(q%2==1) cont++;
     if (q>max) max = q;
  }
  else {
    calc();
  }
}

int main() {
cont = 0; max = 0;
for(n=2; n<=N; n++) {
  q = 0;
  int r = sqrt(n);
  num[q] = 1;
  den[q] = r; 
  if(n-r*r != 0) calc();
}
printf("Cont %d Max %d\n", cont, max);
}
