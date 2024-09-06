#include<stdio.h>
#include<stdlib.h>

typedef struct treenode
{
  int data;
  struct treenode *left, *right;
} node;

void preorder(node *tree)   // Preorder Traversal using Recursive function
{
     if (tree)
    {
     printf("%d\n",tree->data);
     preorder(tree->left);
     preorder(tree->right);
    }
}

void inorder(node * tree)  // Inorder Traversal using Recursive function
{
    if (tree)
    {
    inorder(tree->left);
    printf("%d\n",tree->data);
    inorder(tree->right);
    }
}

void postorder(node * tree)  // Postorder Traversal using Recursive function
{
    if (tree)
    {
    postorder(tree->left);
    postorder(tree->right);
    printf("%d\n",tree->data);
    }
}

node *insert(node *tree, int value)  // Tree Insertion Logic using Recursion
{
    node *tmp = NULL;
    if(tree == NULL)
    {
        tmp = (node *)malloc(sizeof(node));
        tmp->left = tmp->right = NULL;
        tmp->data = value;
        return tmp;
    }

    if(value <= tree->data) // Insert lower and equal values to left and higher values to right
    tree->left=insert(tree->left, value);
    else
    tree->right=insert(tree->right, value);
}

node *leafDelete(node  *root) // Tree leaf nodes deletion logic
{
node  *temp;

if (root == NULL)
    return root;

if (root->left == NULL && root->right == NULL)
{
    free(root);
    return NULL;
}

 root->left = leafDelete(root->left);
 root->right = leafDelete(root->right);

 return root;


}



void main()
{
    node *tree=NULL;
    int x,key;
    while (1)
    {
     printf("Enter data or -1 to exit \n");
     scanf("%d", &x);
     if (x == -1) break;

     tree=insert(tree,x);
    }

    printf ("Binary Tree Traversals output \n");

    printf("Preorder \n");
    preorder(tree);

    printf("Inorder \n");
    inorder(tree);

    printf("Postorder \n");
    postorder(tree);


    tree=leafDelete(tree);

    printf ("Binary Tree after leaves Deletion \n");

    printf("Preorder \n");
    preorder(tree);

}
