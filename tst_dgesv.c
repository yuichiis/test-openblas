#include <stdio.h>
#define SIZE 2

int main(void) {
  int     n             = SIZE;
  int     nrhs          = 1   ;
  double  A[SIZE*SIZE]        ;
  A[0]=1; A[2]=2;
  A[1]=3; A[3]=4;
  int     lda           = SIZE;
  int     ipiv[SIZE]          ;
  double  b[SIZE]             ;
  b[0]=5;
  b[1]=6;
  int     ldb           = SIZE;
  int     info                ;

  dgesv_(&n,&nrhs,A,&lda,ipiv,b,&ldb,&info);

  printf("x = %5.3lf\n",b[0]);
  printf("y = %5.3lf\n",b[1]);
  return 0;
}
