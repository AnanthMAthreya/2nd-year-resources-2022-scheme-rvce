#include<stdio.h>
#include<stdlib.h>

typedef struct treenode
{
  int data;
  struct treenode *left, *right;
} node;

int found=0;
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

node *deleteNode(node  *root, int key) // Tree node deletion logic
{
node  *temp;

if (root == NULL)
    return root;

if (key < root -> data)
        root->left = deleteNode(root->left, key);
else if (key > root->data) // Key in right subtree
        root->right = deleteNode(root->right, key);
        else  // Key found
        {   found=1;
            if (root->left == NULL)
            {
                temp = root->right;
                free(root);
                return temp;
            }else if (root->right == NULL)
            {
                temp = root->left;
                free(root);
                return temp;
            }

            // Get the inorder successor smallest in the right subtree

            temp = root->right;

            // loop down to find the leftmost leaf
            while (temp->left != NULL)
            temp = temp->left;

            // Copy the inorder successor's content to this node
            root->data = temp->data;

           // Delete the inorder successor
            root->right = deleteNode(root->right, temp->data);
        }

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

    printf("Enter the key for deletion\n");
    scanf("%d", &key);
    tree=deleteNode(tree, key);

    if (found==0)
        printf("Node with key element not found in the tree\n");
    else
    {

    printf ("Binary Tree after Deletion \n");
    printf("Preorder \n");
    preorder(tree);

    }


}
