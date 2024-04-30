#include<stdio.h>
#include<stdlib.h>

// Inserting node to the end of the list

struct node
{
   int data;
   struct node *link;
};

void main()
{

   struct node *temp, *start=NULL, *newnode;
   int x;

   while(1)
   {
      printf("Enter the data \n"); scanf("%d",&x);
      if (x == -1) break;

      newnode=(struct node *)malloc(sizeof(struct node)); //create newnode and initialize
      newnode->data=x; newnode->link=NULL;

      if (start == NULL)
      start = newnode;  // first node of the list
      else
      {
       // Traverse the list to last node
       temp = start;

       while (temp->link != NULL)
       temp=temp->link; //Change the temp to next node of the list

       temp->link = newnode;  // Insert the new node in the end
      }
    }

    printf("The list contents are\n");
    temp=start;
    while(temp)
    {
      printf("%d\n", temp->data);
      temp=temp->link;
    }
}
