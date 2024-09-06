#include<stdio.h>
#include<stdlib.h>

// Inserting node to the end of the list using Recursive functions

struct node
{
   int data;
   struct node *link;
};

struct node *listinsert(struct node *current_node, int x) // Recursive function for listcreate
{
       struct node *newnode;

        printf("Address of current node on the stack - INSERT Logic = %u \n", current_node);
        if (current_node == NULL)
        {
           newnode = (struct node *)malloc(sizeof (struct node));
           newnode->data = x;
           newnode->link = NULL;
           return newnode;
        }

       current_node->link=listinsert(current_node->link, x);
}


void listdisplay(struct node *current_node) // Recursive function for listdisplay
{
      printf("Address of current node on the stack - DISPLAY Logic = %u \n", current_node);

      if (current_node != NULL)
      printf("%d\n", current_node->data);

      listdisplay(current_node->link);

}


void main()
{

   struct node  *start=NULL;
   int x;

   while(1)
   {
      printf("Enter the data \n"); scanf("%d",&x);
      if (x == -1) break;

      start=listinsert(start, x);
    }

    printf ("----------The contents of list---------------\n");
    listdisplay(start);

}
