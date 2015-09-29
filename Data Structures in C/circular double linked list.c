/*
Implementation of circular doubly linked list QUEUE
Operations supported
1)Add
2)Delete
3)rotate
4)print
5)print in reverse order
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

node* get_new_node(int);
void AddQ(node **,int);
void printCDLL(node **);
void printCDLLReverse(node **);
node* DelQ(node **);
void RotateQ(node **);

main()
{
   node *temp = NULL;
   node *head = NULL;

/*   
   AddQ(&head,11);
   AddQ(&head,13);
   
   AddQ(&head,17); 
   AddQ(&head,19);
   
   AddQ(&head,71); 
   AddQ(&head,91);
     
   printCDLL(&head);
   printf("\n");
   printCDLLReverse(&head); 
 
   printf("\n");

   RotateQ(&head);
   RotateQ(&head);
   printCDLL(&head);
   printf("\n");
   printCDLLReverse(&head); 
*/
   AddQ(&head,91);
   printCDLL(&head);   

   while(head -> right != head)
   {
   printf("%d ",DelQ(&head)->data);
   } 
   
   if( (temp = DelQ(&head)) != NULL)
   printf("%d ",temp->data);

   if( (temp = DelQ(&head)) != NULL)
   printf("%d ",temp->data);

}

void AddQ(node **head,int n)
{
    node* start = *head;      
  
    if(start == NULL)
    {
       node* new_node = get_new_node(n);
       *head = new_node;
       (*head) -> left  = *head;
       (*head) -> right = *head;
       return;
    }   
    
    node *end = start -> left;
    node* new_node = get_new_node(n);
    end -> right = new_node;
    new_node -> left = end;
    new_node -> right = start;
    start -> left = new_node;
}

void RotateQ(node **head)
{
    /*
    if( *head == NULL || (*head) -> right == *head)
    {
       return;
    } 
    */
  
    if(*head == NULL)
    {
       return;
    }
    
    (*head) = (*head) -> right;
}

node* get_new_node(int n)
{

     node* new_node = (node *)malloc(sizeof(node));
     new_node -> data = n;
     new_node -> left = NULL;
     new_node -> right = NULL;
        
     return new_node;
}
     
node* DelQ(node **head)
{
     node *temp = NULL;
    
     if(*head == NULL)
     {
      printf("cannot delete as the list is empty"); 
      return temp;
     }

     if((*head) -> right == *head)
     {
      temp = *head;  
      (*head) -> left = NULL;             
      (*head) -> right = NULL;
      (*head) = NULL;
      return temp;
     }
    
     temp = *head;
     node *end = (*head) -> left;
     (*head) -> right -> left = end;
     end -> right = (*head) -> right;    
     *head = (*head) -> right;
     temp -> left = NULL;
     temp -> right = NULL;

     return temp;  
}

void printCDLL(node **head)
{
     if(*head == NULL)
     return; 
     
     node *start = *head;
     node *end = start -> left;     

     while(start != end)
     {
     printf("%d ",start->data);
     start = start -> right;
     }

     printf("%d ",start->data);
}

void printCDLLReverse(node **head)
{
     if(*head == NULL)
     return; 
     
     node *start = *head;
     node *end = start -> left;     

     while(end != start)
     {
     printf("%d ",end->data);
     end = end -> left;
     }

     printf("%d",end->data);
}
