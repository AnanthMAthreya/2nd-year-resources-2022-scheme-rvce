#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    char word[500];
    struct node *left, *right;
};

struct node *add(struct node *head, char s[])
{

    struct node *new = (struct node *)malloc(sizeof(struct node));
    strcpy(new->word, s);
    new->left = NULL;
    new->right = NULL;
    if (head == NULL)
    {
        head = new;
    }

    if (strcmp(s, head->word) > 0)
    {
        head->right = add(head->right, s);
    }
    else if (strcmp(s, head->word) < 0)
    {
        head->left = add(head->left, s);
    }
    return head;
}

void inorder(struct node *head)
{
    if (head != NULL)
    {
        inorder(head->left);
        printf("%s\n", head->word);
        inorder(head->right);
    }
}

struct node *delete(struct node *head, char s[])
{
    if (head == NULL)
    {
        return NULL;
    }
    if (strcmp(s, head->word) > 0)
    {
        head->right = delete (head->right, s);
    }
    else if (strcmp(s, head->word) < 0)
    {
        head->left = delete (head->left, s);
    }
    else
    {
        if (head->right == NULL)
        {
            struct node *tmp = head->left;
            free(head);
            return tmp;
        }
        else if (head->left == NULL)
        {
            struct node *tmp = head->right;
            free(head);
            return tmp;
        }
        else
        {
            struct node *tmp = head->right;
            while (tmp->left != NULL)
            {
                tmp = tmp->left;
            }
            strcpy(head->word, tmp->word);
            head->right = delete (head->right, head->word);
        }
    }
    return head;
}

int main()
{
    int choice;
    char a[100];
    struct node *head = NULL;
    while (1)
    {
        printf("Select an option:\n");
        printf("1. Enter words\n");
        printf("2. Delete words\n");
        printf("3. Display words\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            while (1)
            {
                printf("Enter a word (-1 to exit): ");
                scanf("%s", a);
                if (strcmp(a, "-1") == 0)
                {
                    break;
                }
                head = add(head, a);
            }
            break;

        case 2:
            printf("Enter a word to delete: ");
            scanf("%s", a);
            head = delete (head, a);
            break;
        case 3:
            printf("Words in alphabetical order:\n");
            inorder(head);
            break;
        case 4:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}