#include <stdio.h>
#define N 1010

int nums[2][N];
int num_soma[N];
int d[2];
int d_soma;

void transforma(int n, int k) {
  d[k] = 0;
  nums[k][0]=0;
  while(n) {
    nums[k][d[k]++] = n%10;
    n /= 10;
  }
}

void soma() {
  int i;
  int carrega = 0;
  int dmin = d[0];
  int v;
  int j;
  if(dmin > d[1]) dmin = d[1];

  for(i=0; i<dmin ;i++) {
    v = nums[0][i]+nums[1][i]+carrega;
    num_soma[i] = v%10;
    carrega = v/10;
  }

  d_soma = dmin;
  while(d[0]>d_soma) { //primeiro número tem mais digitos
    v = nums[0][d_soma]+carrega;
    num_soma[d_soma++] = v%10;
    carrega = v/10;
  } 
  while(d[1]>d_soma) { //segundo número tem mais digitos
    v = nums[1][d_soma]+carrega;
    num_soma[d_soma++] = v%10;
    carrega = v/10;
  } 
  if(carrega) {
    num_soma[d_soma++] = carrega;
  }

}

void imprime() {
  int i;
  if (d_soma==0) {
    printf("0\n");
  }
  else {
    for(i = d_soma-1; i>=0; i--) {
      printf("%d", num_soma[i]);
    }
    printf("\n");
  }
}

void copia(int k) {
  int i;
  for(i=0; i<d_soma; i++) {
    nums[k][i]=num_soma[i];
  }
  d[k] = d_soma;
}

int main() {
  int n0, n1, i;
  transforma(1, 0);
  transforma(1, 1);
  for(i=3; i<10000; i++) {
    soma();
    //imprime();
    if(d_soma >= 1000) {
      printf("F%d = ",i);
     imprime();
      printf("sucesso\n");
      break;
    }
    if(i%2) {
      copia(0);
    } else {
      copia(1);
    }
  }
  return 1;
}
