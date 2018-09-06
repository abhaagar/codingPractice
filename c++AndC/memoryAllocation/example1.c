#include<stdlib.h>
#include<stdio.h>

void printMetadata(void *p) {
    char *c = (char*) p;
    c = c-16;
    int *startMetadata = (int*)c;
    printf("Allocated Chunk Metadata:");
    //for(int i=0;i<=4;++i)
    for(int i=0;i<=15;++i)
       //printf("%d ",startMetadata[i]);
       printf("%02x ",c[i]);
    printf("\n");

}

int main() {
   void *p1 = malloc(1024);
   printf("Allocated Chunk Address p1: %p\n",p1);
   printMetadata(p1);

   void *p2 = malloc(1024);
   printf("Allocated Chunk Address p2: %p\n",p2);
   printMetadata(p2);

   void *p3 = malloc(1024);
   printf("Allocated Chunk Address p3: %p\n",p3);
   printMetadata(p3);

   void *p4 = malloc(1024);
   printf("Allocated Chunk Address p4: %p\n",p4);
   printMetadata(p4);

   free(p3);
   printf("Deallocated P3\n\n");
   printf("Allocated Chunk Address p1: %p\n",p1);
   printMetadata(p1);

   printf("Allocated Chunk Address p2: %p\n",p2);
   printMetadata(p2);

   printf("Allocated Chunk Address p3: %p\n",p3);
   printMetadata(p3);

   printf("Allocated Chunk Address p4: %p\n",p4);
   printMetadata(p4);

   void *p5 = malloc(1024);
   printf("Allocated Chunk Address p5: %p\n",p5);
   printMetadata(p5);

   return 0;
}	
