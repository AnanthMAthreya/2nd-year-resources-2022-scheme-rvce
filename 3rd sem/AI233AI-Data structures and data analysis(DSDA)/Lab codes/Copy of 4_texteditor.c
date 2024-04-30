#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char line[80];
    struct node *rlink;
    struct node *llink;
};

char buffer[80];
char newline[80];
int n, d;

struct node *first, *temp, *rlink, *llink;

void insert(char l[])
{

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->rlink = NULL;
    newnode->llink = NULL;
    strcpy(newnode->line, l);

    if (first == NULL)
    {
        first = newnode;
        temp = first;
    }

    else
    {

        newnode->llink = temp;

        //   if (temp->rlink != NULL)

        temp->rlink = newnode;
        temp = newnode;
    }
}

void insertnew(char nl[], int p)
{

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->rlink = NULL;
    newnode->llink = NULL;
    temp = first;
    strcpy(newnode->line, nl);

    if (p == 1)
    {
        first->llink = newnode;
        newnode->rlink = first;
        first = newnode;
        temp = first;
    }

    else
    {
        for (int i = 0; i < p - 2; i++)
        {
            temp = temp->rlink;
        }
        {
            newnode->llink = temp;
            newnode->rlink = temp->rlink;
            newnode->rlink->llink = newnode;
            temp->rlink = newnode;
            //   p = p + 1;
        }
    }
}

void display()
{

    struct node *temp1 = first;
    printf("\nDisplaying:\n");
    while (temp1->rlink != NULL)
    {

        printf("%s\n", temp1->line);
        temp1 = temp1->rlink;
    }
}

void Delete(int p)
{
    int i;
    // struct node *temp;
    temp = first;

    if (p == 1)
    {
        first = temp->rlink;
        temp->rlink = NULL;
    }
    else
    {
        for (int i = 0; i <= p - 2; i++)
        {
            temp = temp->rlink;
        }
        {
            temp->llink->rlink = temp->rlink;
            temp->rlink->llink = temp->llink;
        }
    }
}

void main()
{

    first = NULL;
    temp = NULL;
    rlink = NULL;
    llink = NULL;

    printf("Enter few lines:");
    scanf(" %s", newline);
    insert(newline);
    char end[4] = "end";
    int flag = 1;

    while (flag != 0)
    {
        scanf(" %s", newline);
        flag = strcmp(newline, end);
        insert(newline);
    }
    display();

    printf("\nEnter the Line no. to insert:");
    scanf("%d", &n);
    printf("\nEnter the Line to be inserted:");
    scanf(" %[^\n]", buffer);
    insertnew(buffer, n);
    display();

    printf("\nEnter the line to be deleted:");
    scanf("%d", &d);
    Delete(d);
    display();
}
