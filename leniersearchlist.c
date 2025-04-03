#include <stdio.h>
# include<stdlib.h>



// structure
struct node{
   int data;
   struct node *next;
   };

   //alaysing
   typedef struct node snode;

   // pointer to head
   snode *head = NULL;

   //create list
   void CreateList(int x)
   {
       snode *tempnode = NULL;
       tempnode = (snode*)malloc(sizeof(snode));
       tempnode->data = x;
       tempnode->next = NULL;
       head = tempnode;
       return;
   }


   //printlist
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


   //appendnode

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


   //search


   void searchtheelement(int x)
       {
         snode *tempnode = head;
         while(tempnode != NULL){
            if(tempnode->data == x)
            {
                printf("%d element found\n",x);
                return;
            }
            tempnode = tempnode->next;
         }
         printf("%d element not found\n",x);
       }

   int main(){
   CreateList(10);
   appendnode(20);
   appendnode(60);
   appendnode(70);
   appendnode(80);
   searchtheelement(60);
   printList();
   return;
   }
