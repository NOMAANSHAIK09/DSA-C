//DOUBLE LINKLIST

# include <stdio.h>
# include <stdlib.h>

// structure
struct node{
      int data;
      struct node *next, *prev;
};

// alaysing
typedef struct node dnode;
// head and tail pointer
dnode *head = NULL;
dnode *tail = NULL;
// create list

void createlist(int x){
dnode *tempnode = NULL;
tempnode = (dnode*)malloc(sizeof(dnode));
tempnode->data = x;
tempnode->next = tempnode->prev = NULL;
head = tempnode;

}
//print list
void printlistforward(){
dnode *temp = head;
printf("Forward: ");
while(temp != NULL){
    printf("%d->", temp->data);
    temp=temp->next;
}
}
//print list
void printlistbackward(){
dnode *temp = head;

printf("Backward: ");
while( temp->next != NULL){
    temp=temp->next;
}
while( temp != NULL){
    printf("%d->", temp->data);
    temp=temp->prev;
}
}
// append node
void appendnode(int x ){
dnode *tempnode = head;
dnode *tail = tempnode;
dnode *newnode  = NULL;
newnode = (dnode*)malloc(sizeof(dnode));
newnode->data = x;
newnode->next = newnode->prev = NULL;
while(tempnode->next != NULL){
   tempnode = tempnode->next;
}
tempnode->next = newnode;
newnode->prev = tempnode;
}

int main(){
createlist(10);
appendnode(20);
appendnode(50);
appendnode(30);
appendnode(40);
printlistforward();
printlistbackward();

return 0;
}
