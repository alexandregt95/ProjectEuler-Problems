#include<stdio.h>
#include<math.h>

int a[120];
int den[100], num[100], b[100];


/*unsigned long long int fracao(int n){
  unsigned long long int b,num,den;
  int termo;
  termo=n-1;
  den=1;
  num=a[termo];

  
  while(termo>=0)
  {
    b=den;
    den=num;
    num=b;
    num=(a[termo-1]*den)+num;
    termo--;
    //den=den;
  }
  printf("%llu / %llu\n",den,num);
    
  return den;
}*/
//---------------------------------------------------------------
  /*
  int dnum=0, dden=1, c=0,i,j,k,x;
  den[0]=1;
  while(a[termo]) //armazena o numero a[termo] em um vetor
  {
    num[c]=a[termo]%10;
    a[termo]/=10;
    c++;
    dnum++;
  }
  while(termo>=0)
  {
    for(i=0;i<dden;i++)
      b[i]=den[i];
    for(j=0;j<dnum;j++)
      den[j]=num[j];
    for(k=0;k<dden;++)
      num[k]=b[k];
    x=dden;
    dden=dnum;
    dnum=x;
            //falta fazer num=(a[termo-1]*den)+num; em bigint e o print para bigint
    termo--;
  }
  */

int soma(unsigned long long int n){
  int soma=0;
  while(n)
  {
    soma+=n%10;
    n/=10;
  }
  return soma;
}

int main() {
  int i, t, n;
  a[0]=2;
  a[1]=1;
  a[2]=2;
  t = 3;
  for(i=2; t<100; i++) {
     a[t++] = 1;  
     a[t++] = 1;
     a[t++] = i*2;
  }
  scanf("%d",&n);
for(i=1; i<=n; i++) fracao(i);
  printf("%d\n",soma(fracao(n)));
}