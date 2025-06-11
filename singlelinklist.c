// SINGLE LINKLIST FULLL CODE

#include <stdio.h>
# include<stdlib.h>
struct node{
   int data;
   struct node *next;
   };
   typedef struct node snode;
   snode *head = NULL;
   void CreateList(int x)
   {
       snode *tempnode = NULL;
       tempnode = (snode*)malloc(sizeof(snode));
       tempnode->data = x;
       tempnode->next = NULL;
       head = tempnode;
       return;
   }
   void printList()
   {
       snode *temp = head;
       while(temp != NULL)
       {
           printf("%d->", temp->data);
           temp = temp->next;
       }
       return;
   }

   void appendnode(int x)
   {
       snode *tempnode = head; // temporarypointer
       snode *newnode = NULL;
       newnode = (snode*)malloc(sizeof(snode));
       newnode->data = x;
       newnode->next = NULL;
           while(tempnode->next != NULL)
           {
               tempnode = tempnode->next;
           }
           tempnode->next = newnode;

   }
   void insertatfirst(int x)
   {
       snode *newnode = NULL;
       newnode = (snode*)malloc(sizeof(snode));
       newnode->data = x;
       newnode->next = head;
       head = newnode;
       return;
   }
   void insertatposition(int x){
       snode *tempnode = head;
   snode *newnode = NULL;
   newnode = (snode*)malloc(sizeof(snode));
   newnode->data = x;
   newnode->next = NULL;
   while(  tempnode->next->data != 52)
   {
       tempnode = tempnode->next;

   }
   if (tempnode->next != NULL) {
        newnode->next = tempnode->next;  // Point to the node with data 52
        tempnode->next = newnode;
   }
   }
void deleteelement(int x)
   {
     snode *tempnode = head;
    snode *collectnode = NULL;
       while(tempnode->next->data != x)
       {
          tempnode = tempnode->next;
       }
       collectnode = tempnode->next;
       tempnode->next = tempnode->next->next;
       collectnode->next = NULL;

       free(collectnode);
       return;
       }
       void searchtheelement(int x)
       {
         snode *tempnode = NULL;
         while(tempnode != NULL){
            if(tempnode->data = x)
            {
                printf("%d element found\n",x);
                return;
            }
            tempnode = tempnode->next;
         }
         printf("%d element not found\n",x);
       }
       void updateelement(int x, int y)
       {
           snode *tempnode = head;
           while(tempnode != NULL){
            if(tempnode->data = x){
                tempnode->data = y;
                printf("%d element update\n",x,y);
                return;
            }
            tempnode=tempnode->next;
           }
           printf("element %d not update",x);
       }


   int main()
   {
       CreateList(10);
       appendnode(52);
       appendnode(72);
       appendnode(62);
       insertatfirst(15);
       insertatposition(22);
       deleteelement(72);
       searchtheelement(62);
       updateelement(52,65);
       printList();
       return;
        }


