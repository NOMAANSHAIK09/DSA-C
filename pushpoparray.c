// this is a code for push pop operation ussing aaray of pointer
#  include <stdio.h>
int st[5] = {0};
int stkpointer = -1;
void push( int element)
{
    if(stkpointer < 4)
    {

        stkpointer++;
        st[stkpointer] = element;
        printf(" %d element inserted\n", element);
        }
       else
       {
           printf("over flow\n");
       }
}
       int pop()
       {
           int x;
           if(stkpointer>-1)
           {
              x = st[stkpointer];
              stkpointer--;
               printf(" %d element is poped\n", x);
               return x;
           }
           else
           {
               printf("down flow\n");
               return -1;
       }
       }
       int main()
       {
           printf(" element added :\n");
           push(10);
           push(15);
           push(16);
           push(18);
           push(90);

           printf("element popped:\n");
           printf("%d \n", pop());
           printf("%d \n", pop());
           printf("%d \n", pop());
           printf("%d \n", pop());
           printf("%d \n", pop());
           return 0;
       }
