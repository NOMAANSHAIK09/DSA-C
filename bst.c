#include <stdio.h>
#include <stdlib.h>
struct tree{
int data;
struct tree *right;
struct tree *left;
};
typedef struct tree bst;
bst *root = NULL;
void createtree(int data){
bst *child = NULL;
child = (bst*)malloc(sizeof(bst));
child->data=data;
child->left=child->right=NULL;
root=child;
}
void printright(){
bst *child=root;
printf("\n right tree:");
while(child != NULL){
    printf("%d->", child->data);
    child = child->right;
}
printf("\n");
}
void printleft(){
bst *child=root;
printf("left tree:");
while(child!=NULL){
    printf("%d->",child->data);
    child=child->left;
}
printf("\n");
}
void inserttree(int data){
bst *child = root;
bst *leave = NULL;
bst *parent = NULL;
leave = (bst*)malloc(sizeof(bst));
leave->data=data;
leave->right=leave->left=NULL;
while (child != NULL) {
        parent = child;
        if (data < child->data){
            child = child->left;}
        else{
            child = child->right;}
    }

    if (data < parent->data){
        parent->left = leave;}
    else{
        parent->right = leave;}
}
void printmax(){
bst *child = root;
printf("max element:");

    while(child->right!=NULL){
        child=child->right;
    }
    printf("%d",child->data);
return;
}
void printmin(){
bst *child = root;
printf("\n min element:");

    while(child->left!=NULL){
        child=child->left;
    }
    printf("%d",child->data);
return;
}

 void searchelement(int data){
    bst *child = root;
    while (child != NULL) {
        if (data == child->data) {
            printf("\n%d element found", data);
            return;
        }
        else if (data < child->data) {
            child = child->left;
        }
        else {
            child = child->right;
        }
    }
    printf("\n%d not found in the tree", data);
}

//void inorder(bst *node){
  //  if (node == NULL) return;
    //inorder(node->left);
 //   printf("%d -> ", node->data);
   // inorder(node->right);

//}
//void preorder(bst *node){
  //  if (node == NULL) return;
    //printf("%d -> ", node->data);
    //preorder(node->left);
    //preorder(node->right);
//}
//void postorder(bst *node){
  //  if (node == NULL) return;
   // postorder(node->left);
   // postorder(node->right);
   // printf("%d -> ", node->data);
//}


int main(){
createtree(10);
inserttree(4);
inserttree(40);
inserttree(15);
inserttree(12);
inserttree(20);
inserttree(2);
inserttree(90);
inserttree(3);


//printf("\nInorder traversal:\n");
//inorder(root);

//printf("\nPreorder traversal:\n");
//preorder(root);

//printf("\nPostorder traversal:\n");
//postorder(root);
printright();
printleft();
printmax();
printmin();
searchelement(60);
}
