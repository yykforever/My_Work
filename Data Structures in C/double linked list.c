/*
implementing queue using doublelinkedlist

Operations supported
1)Add
2)Delete
3)rotate
4)print
5)print in reverse order

edge cases: emptylist, deleting with 1 node, deleting with empty list, inserting into empty list
*/


#include <stdio.h>
#include <stdlib.h>

struct ll_node
{
  int data;
  struct ll_node *left;
  struct ll_node *right;
};

typedef struct ll_node node;

void insertAtEnd(node **,node **,int);
node* get_new_node(int);
void rotate(node **,node **);
node* deleteFromStart(node **start,node **end);
void printList(node **);
void printListReverse(node **);

main()
{
   node *temp = NULL;
   node *head = NULL;
   node *tail = NULL;

/* 
   insertAtEnd(&head,&tail,1);
 

   insertAtEnd(&head,&tail,3);
   insertAtEnd(&head,&tail,5);
   insertAtEnd(&head,&tail,7);
*/
 
/*
   temp = head;
   printf("printing from start to end\n");
   while(temp != NULL)
   {
     printf("%d ",temp->data);
     temp = temp->right;
   } 
*/

/*
   rotate(&head,&tail);
   rotate(&head,&tail);
   rotate(&head,&tail);
*/  
  

/*
   node *temp1 = tail;
   printf("printing from end to start\n");
   
   while(temp1 != NULL)
   {
     printf("%d ",temp1->data);
     temp1 = temp1->left;
   } 
*/

/*
   insertAtEnd(&head,&tail,1);
   insertAtEnd(&head,&tail,3);
   insertAtEnd(&head,&tail,5);
   insertAtEnd(&head,&tail,7); 
*/
   
   insertAtEnd(&head,&tail,19);
   while(head != NULL)
   {
   node *temp_head = deleteFromStart(&head,&tail);
   printf("deleted node's data is %d ",temp_head->data);
   }  

   insertAtEnd(&head,&tail,9);
   insertAtEnd(&head,&tail,11); 

   printList(&head);
   printListReverse(&tail);
}

//adding at the end since its the queue
void insertAtEnd(node **start,node **end,int n)
{
    node* head = *start;      
  
    if((*start) == NULL)
    {
       node* new_node = get_new_node(n);
       *start = new_node;
       *end = new_node;
       return;
     }

    node* new_node = get_new_node(n);
    (*end)->right = new_node;
    new_node -> left = (*end);    
    (*end) = (*end)->right;
}

//removing an element from the start i.e start of queue
node* deleteFromStart(node **start,node **end)
{

     node* head = *start;  

     if(head == NULL)
     return;

     if(head -> right == NULL)
     {
        *start = NULL;
        *end = NULL;
        return head;
     }
   
     head -> right -> left = NULL; 
     (*start) = (*start) -> right;
     head -> right = NULL; 
   
     return head;

}

//removing the first node and adding it to the end
void rotate(node **start,node **end)
{

     if(*start == NULL || (*start)->right == NULL)
     {
     return;
     }

     node *initial = *start;
     
     //removing the first node
     (*start)->right->left = NULL; 
     (*start) = (*start) -> right;
     initial->right = NULL; 

     //adding the node to the right
     (*end)->right = initial;
     initial->left = *end;
     *end = (*end) -> right;                
}

void printList(node **head)
{
     node *start = *head;
     printf("printing from start to end: \n");

     while(start != NULL)
     {
        
        printf("%d-->",start->data);
        start = start -> right;
     }
}

void printListReverse(node **tail)
{
     node *start = *tail;
     printf("printing from end to start: \n");

     while(start != NULL)
     {
        printf("%d-->",start->data);
        start = start -> left;
     }
}


node* get_new_node(int n)
{

     node* new_node = (node *)malloc(sizeof(node));
     new_node -> data = n;
     new_node -> left = NULL;
     new_node -> right = NULL;
        
     return new_node;
}
  




