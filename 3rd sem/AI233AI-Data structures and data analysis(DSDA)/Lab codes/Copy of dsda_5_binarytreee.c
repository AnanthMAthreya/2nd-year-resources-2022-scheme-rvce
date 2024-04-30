#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct node
{
    char info;
    struct node *left, *right;
};

struct stack
{
    struct node *top;
    struct stack *link;
};

struct node *newnode(char ch)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->info = ch;
    temp->left = temp->right = NULL;
    return temp;
}

void push(struct stack **s, struct node *x)
{
    struct stack *temp = (struct stack *)malloc(sizeof(struct stack));
    temp->top = x;
    temp->link = *s;
    *s = temp;
}

struct node *pop(struct stack **s)
{
    if (*s == NULL)
    {
        printf("Stack underflow\n");
        return NULL;
    }
    struct node *temp = (*s)->top;
    *s = (*s)->link;
    return temp;
}

struct node *ExpTree(char postfix[])
{
    struct stack *s = NULL;
    struct node *t, *t1, *t2;
    for (int i = 0; i < strlen(postfix); i++)
    {
        t = newnode(postfix[i]);
        if (isalnum(postfix[i]))
            push(&s, t);
        else
        {
            t1 = pop(&s);
            t2 = pop(&s);
            t->right = t1;
            t->left = t2;
            push(&s, t);
        }
    }
    return pop(&s);
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%c", root->info);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%c", root->info);
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    char postfix[20];
    printf("Enter postfix expression: ");
    scanf("%s", postfix);
    struct node *root = ExpTree(postfix);
    printf("Infix Expression is: ");
    inorder(root);
    printf("\nPrefix expression is: ");
    preorder(root);
    return 0;
}
