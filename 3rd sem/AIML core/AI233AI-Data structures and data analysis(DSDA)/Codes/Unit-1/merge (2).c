#include<stdio.h>
#include<stdlib.h>

// Inserting node to the end of the list

struct node
{
   int data;
   struct node *link;
};


struct node *listinsert(struct node *l, int x)
{
       struct node *temp, *newnode;

       // Traverse the list to last node

       newnode = (struct node*)malloc(sizeof(struct node));
       newnode->data=x; newnode->link = NULL;

       if (l==NULL)
        l=newnode;
       else
       {
       temp = l;

       while (temp->link != NULL)
       temp=temp->link; //Change the temp to next node of the list

       temp->link = newnode;  // Insert the new node in the end
       }
       return l;
}


void listdisplay(struct node *l)
{
    struct node *temp;

    printf("The list contents are\n");
    temp=l;
    while(temp)
    {
      printf("%d\n", temp->data);
      temp=temp->link;
    }
}


void main()
{

   struct node *l1, *l2, *l3, *newnode,*temp1, *temp2;
   int x;

   l1=l2=l3=NULL;

   printf("Creating first list \n");
   while(1)
   {
      printf("Enter the data \n"); scanf("%d",&x);
      if (x == -1) break;
      l1=listinsert(l1, x);
    }

    printf("First list \n");
    listdisplay(l1);

    printf("Creating second list \n");
    while(1)
    {
      printf("Enter the data \n"); scanf("%d",&x);
      if (x == -1) break;
      l2=listinsert(l2, x);
    }

    printf("Second list \n");
    listdisplay(l2);

    // Merging logic

    temp1=l1;
    temp2=l2;

    while (temp1 && temp2)
    {
      if (temp1->data <= temp2->data) // First list node has lower value
      {
         l3=listinsert(l3,temp1->data);
         temp1=temp1->link;
      }
      else
      {
        l3=listinsert(l3, temp2->data);
        temp2=temp2->link;
      }

    } // of while

    // Merge remaining elements if the lists are not of equal sizes
    if (temp1)
       while (temp1)
       {
         l3=listinsert(l3,temp1->data);
         temp1=temp1->link;
       }
    else
       while (temp2)
       {
         l3=listinsert(l3,temp2->data);
         temp2=temp2->link;
       }

    printf("List after merging \n");
    listdisplay(l3);
}
