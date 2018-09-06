#include <stdio.h>
#define MAX_LCS 100
#define max(a,b) a>b?a:b

int main() {
   int matrix[MAX_LCS][MAX_LCS];
   for (int i=0; i<MAX_LCS; ++i) {
      matrix[i][0] = 0;
      matrix[0][i] = 0;
   }
   char seq1[MAX_LCS], seq2[MAX_LCS];
   scanf("%s %s",seq1,seq2);
   int i=0,j=0,max=0;
   for(i=1; seq1[i-1]!='\0'; ++i) {
      for(j=1; seq2[j-1]!='\0'; ++j) {
         if(seq1[i-1]==seq2[j-1]) {
            matrix[i][j] = 1 + matrix[i-1][j-1];
         } else {
            matrix[i][j] = max(matrix[i-1][j],matrix[i][j-1]);
         }
         if(matrix[i][j]>max)
           max = matrix[i][j];
      }
   }
   printf("%d\n",max);
   return 0;
}
