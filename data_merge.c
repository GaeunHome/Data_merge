#include<stdio.h>
#define MAXLEN 10
void merge(double A[], int Alen, double B[], int Blen, double C[]);
void merge(double A[MAXLEN], int Alen, double B[MAXLEN], int Blen, double C[2*MAXLEN]) {
  for(int i=0; i<Alen; i++) {
    C[i] = A[i];
  }
  int j = 0;
  for(int i=Alen; i<Alen+Blen; i++) {
    C[i] = B[j];
    j++;
  }
  for(int i=0; i<Alen+Blen; i++) {
    for(int k=0; k<i; k++) {
      double tmp = 0;
      if(C[i]>C[k]) {
        tmp = C[k];
        C[k] = C[i];
        C[i] = tmp;
      }
    }
  }
}
int main()
{
   double A[MAXLEN];
   double B[MAXLEN];
   double C[2*MAXLEN];
   int lenA, lenB;
   scanf("%d%d",&lenA,&lenB);
   for(int i=0;i<lenA;i++) {
      scanf("%lf",&A[i]);
   }
   for(int i=0;i<lenB;i++) {
      scanf("%lf",&B[i]);
   }
   merge(A,lenA,B,lenB,C);
   for(int i=0;i<lenA+lenB;i++) {
     printf("%f\n",C[i]);
   }
   return 0;
}
