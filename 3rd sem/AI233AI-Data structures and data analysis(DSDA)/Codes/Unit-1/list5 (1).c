#include<stdio.h>
#include<stdlib.h>

// Inserting node to the end of the list

struct node
{
   int data;
   struct node *link;
};

void listinsert(struct node *start, struct node *newnode)
{
       struct node *temp;

       // Traverse the list to last node
       temp = start;

       while (temp->link != NULL)
       temp=temp->link; //Change the temp to next node of the list

       temp->link = newnode;  // Insert the new node in the end

}

struct node *listdelete(struct node *start, int key)
{
       struct node *current, *previous;

       previous = NULL;
       current = start;

       while (current)
       {
           if (current->data == key)
               if (previous == NULL)  //first node with the key
               {
               start=start->link;
               current->link=NULL;
               free(current);
               current=start;
               }
               else
               {
               previous->link=current->link; //any other node in the list with the key
               current->link=NULL;
               free(current);
               current=previous->link;
               }
           else
           {
               previous=current;
               current=current->link;
           }

       }
     return(start);
}

void listdisplay(struct node *start)
{
    struct node *temp;

    printf("The list contents are\n");
    temp=start;
    while(temp)
    {
      printf("%d\n", temp->data);
      temp=temp->link;
    }
}


void main()
{

   struct node *temp, *start=NULL, *newnode;
   int x,key;

   while(1)
   {
      printf("Enter the data \n"); scanf("%d",&x);
      if (x == -1) break;

      newnode=(struct node *)malloc(sizeof(struct node)); //create newnode and initialize
      newnode->data=x; newnode->link=NULL;

      if (start == NULL)
      start = newnode;  // first node of the list
      else
      listinsert(start, newnode);
    }


    listdisplay(start);


    printf("Enter the key for deletion \n");
    scanf("%d", &key);
    start=listdelete(start,key);

    printf("List after deletion\n");
    listdisplay(start);

}
