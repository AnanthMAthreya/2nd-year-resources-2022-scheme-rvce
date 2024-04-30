#include<stdio.h>
#include<stdlib.h>

// Inserting node to the end of the list

struct node
{
   int data;
   struct node *llink,*rlink;
};

struct node *first, *last;

void listinsert(struct node *newnode)
{
       struct node *temp;

       if (first->data >= newnode->data)   // Insert as a first node
       {
           newnode->rlink = first;
           first->llink = newnode;
           first=newnode;
       }

       else
            if (last->data <= newnode->data)  // Insert as a last node
            {
              last->rlink=newnode;
              newnode->llink=last;
              last=newnode;
            }
            else
            {
             temp = first; //Traverse the list for the position for insertion
             while (temp->data < newnode->data)
                    temp = temp->rlink;

             // insert in between two nodes
             newnode->rlink=temp;
             newnode->llink=temp->llink;
             temp->llink->rlink=newnode;
             temp->llink=newnode;
            }

}


void listdisplay(struct node *first, struct node *last)
{
    struct node *temp;

    printf("The list contents from first to last are\n");
    temp=first;
    while(temp != NULL)
    {
      printf("%d\n", temp->data);
      temp=temp->rlink;
    }

     printf("The list contents from last to first are\n");
    temp=last;
    while(temp != NULL)
    {
      printf("%d\n", temp->data);
      temp=temp->llink;
    }
}


void main()
{

   struct node *newnode;
   int x,key;

   first=last=NULL;   // Empty list

   while(1)
   {
      printf("Enter the data \n"); scanf("%d",&x);
      if (x == -1) break;

      newnode=(struct node *)malloc(sizeof(struct node)); //create newnode and initialize
      newnode->data=x; newnode->llink=newnode->rlink=NULL;

      if (first == NULL)
      first = last = newnode;  // first node of the list
      else
      listinsert(newnode); // insert new node at proper place
    }


    listdisplay(first,last);


}
