#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 1000
#define MAX_LCS_MATRIX_SIZE MAX_SIZE+1
#define MAX(a,b) a>b?a:b

int main() {
   char seq1[MAX_SIZE+1];
   char seq2[MAX_SIZE+1];
   int lenSeq1 = 0;
   int lenSeq2 = 0;
   int i,j;
   scanf("%s %s",seq1,seq2);

   //int lcsMatrix[MAX_SIZE*MAX_SIZE];
   int lcsMatrix[MAX_LCS_MATRIX_SIZE][MAX_LCS_MATRIX_SIZE];
   for (i=0; i<=MAX_SIZE && seq1[i]!='\0'; ++i,++lenSeq1) {
      lcsMatrix[0][i] = 0;
   }
   lcsMatrix[0][i] = 0;

   for (i=0; i<=MAX_SIZE && seq2[i]!='\0'; ++i,++lenSeq2) {
      lcsMatrix[i][0] = 0;
   }
   lcsMatrix[i][0] = 0;

   for (i=1; i<=lenSeq1; ++i) {
      for (j=1; j<=lenSeq2; ++j) {
         if(seq1[i]==seq2[j]){
            lcsMatrix[i][j] = 1 + lcsMatrix[i-1][j-1];
         } else {
            lcsMatrix[i][j] = MAX(lcsMatrix[i-1][j],lcsMatrix[i][j-1]); 
         }
    
      }

   }
   printf("%d\n",lcsMatrix[lenSeq1][lenSeq2]);
   return 0;
}
