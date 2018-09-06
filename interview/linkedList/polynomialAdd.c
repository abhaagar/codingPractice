#include"list.h"

int main() {
   int p1,p2;
   scanf("%d",&p1);
   int i=0;
   struct PolyNode * poly1 = NULL, * poly2 = NULL;
   struct PolyNode * poly1Temp = NULL, * poly2Temp = NULL;

   poly1Temp = poly1 = (struct PolyNode*)malloc(sizeof(struct PolyNode));
   poly2Temp = poly2 = (struct PolyNode*)malloc(sizeof(struct PolyNode));

   for(; i<p1; ++i) {
      poly1Temp->next = (struct PolyNode*)malloc(sizeof(struct PolyNode)); 
      poly1Temp = poly1Temp->next;
      poly1Temp->next = NULL;
      scanf("%d %d",&(*poly1Temp).coef,&(*poly1Temp).pow);
   }
   scanf("%d",&p2);
   for(i=0; i<p2; ++i) {
      poly2Temp->next = (struct PolyNode*)malloc(sizeof(struct PolyNode)); 
      poly2Temp = poly2Temp->next;
      poly2Temp->next = NULL;
      scanf("%d %d",&(*poly2Temp).coef,&(*poly2Temp).pow);
   }
   poly1 = poly1->next;
   poly2 = poly2->next;
   struct PolyNode* poly = (struct PolyNode*)malloc(sizeof(struct PolyNode));
   struct PolyNode* polyTemp = poly;
   struct PolyNode *temp = NULL;
   poly->next = NULL;
   while(poly1&&poly2) {
      polyTemp->next = (struct PolyNode*)malloc(sizeof(struct PolyNode));
      polyTemp = polyTemp->next;
      polyTemp->next = NULL;
      if(poly1->pow>poly2->pow) {
         polyTemp->coef = poly1->coef;
         polyTemp->pow = poly1->pow;
         temp = poly1;
         poly1 = poly1->next;
         free(temp);
      } else if(poly2->pow>poly1->pow) {
         polyTemp->coef = poly2->coef;
         polyTemp->pow = poly2->pow;
         temp = poly2;
         poly2 = poly2->next;
         free(temp);
      } else {
         polyTemp->coef = poly1->coef + poly2->coef;
         polyTemp->pow = poly1->pow;
         temp = poly1;
         poly1 = poly1->next;
         free(temp);
         temp = poly2;
         poly2 = poly2->next;
         free(temp);
      }
   }
   if(poly1) {
      while(poly1) {
         polyTemp->next = (struct PolyNode*)malloc(sizeof(struct PolyNode));
         polyTemp = polyTemp->next;
         polyTemp->next = NULL;
         polyTemp->coef = poly1->coef;
         polyTemp->pow = poly1->pow;
         temp = poly1;
         poly1 = poly1->next;
         free(temp);
      }
   } else {
      while(poly2) {
         polyTemp->next = (struct PolyNode*)malloc(sizeof(struct PolyNode));
         polyTemp = polyTemp->next;
         polyTemp->next = NULL;
         polyTemp->coef = poly2->coef;
         polyTemp->pow = poly2->pow;
         temp = poly2;
         poly2 = poly2->next;
         free(temp);
      }

   }
   poly = poly->next;
   while(poly) {
      printf("%dX^%d + ",poly->coef,poly->pow);
      poly = poly->next;
   }
   return 0;
}
