#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node *left, *right;
}node;

void insert(node *root, int key)
{
    
    if(root->data==key)
    return;
    else{
        if(root->data>key)
        {
            if(root->left==NULL)
            {
                node *temp=(node *)malloc(sizeof(node));
                temp->data=key;
                temp->left=NULL;
                temp->right=NULL;
                root->left=temp;
            }
            else
                insert(root->left, key);
        }
            else
            {
                if(root->right==NULL)
                {
                    node *temp=(node *)malloc(sizeof(node));
                temp->data=key;
                temp->left=NULL;
                temp->right=NULL;
                root->right=temp;
                }
                else
                    insert(root->right,key);
            }
        }
    }

node *getsucc(node *curr)
{
    curr=curr->right;
    while(curr!=NULL && curr->left!=NULL)
    curr=curr->left;
    return curr;
}
node *delete(node *root, int del)
{
    if(root==NULL)
    return NULL;
    else if(root->data>del)
    root->left=delete(root->left, del);
    else if(root->data<del)
    root->right=delete(root->right, del);
    else
    {
        if(root->left==NULL)
        {
            node *temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            node *temp=root->left;
            free(root);
            return temp;
        }
        else{
            node *succ=getsucc(root);
            root->data=succ->data;
            root->right=delete(root->right, succ->data);
        }
    }
    return root;
}
void inorder(node *root){
    if(root==NULL)
    return;
    inorder(root->left);
    printf("%d\t", root->data);
    inorder(root->right);
}
void preorder(node *root){
    if(root==NULL)
    return;
    printf("%d\t", root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(node *root){
    if(root==NULL)
    return;
    postorder(root->left);
    postorder(root->right);
    printf("%d\t", root->data);
}
void level_order(node *root){
    node* queue[100];
    int front=-1;
    int rear=-1;
    queue[++rear]=root;
    while(front<rear){
        node *temp=queue[++front];
        printf("%d\t", temp->data);
        if(temp->left!=NULL)
        queue[++rear]=temp->left;
        if(temp->right!=NULL)
        queue[++rear]=temp->right;
    }
}
int max(int a1, int b1){
    if(a1>=b1)
    return a1;
    else 
    return b1;
}
int height(node *root)
{
    if(root==NULL)
    return 0;
    else
    return max(height(root->left), height(root->right))+1;
}
void printKdist(node *root, int k)
{
    if(root==NULL)
    return;
    if(k==0)
    printf("%d\t", root->data);
    else
    {
        printKdist(root->left, k-1);
        printKdist(root->right, k-1);
    }
}
int main()
{
    int val;
    printf("Enter root node: \t");
    scanf("%d", &val);
    node *root=(node *)malloc(sizeof(node));
    root->data=val;
    root->left=NULL;
    root->right=NULL;
    while(val!=-1)
    {
        printf("\nEnter value\n");
        scanf("%d", &val);
        if(val!=-1)
        insert(root, val);
    }
    printf("\n\nThe preorder is:\t");
    preorder(root);
    printf("\n\nThe inorder is:\t");
    inorder(root);
    printf("\n\nThe postorder is:\t");
    postorder(root);
    printf("\n\nThe level-order is:\t");
    level_order(root);
    printf("\n Height of tree:\t%d", height(root));

    printf("\n Enter how many nodes you want to delete\n");
    int n,i;
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        scanf("%d", &val);
    node *curr=root;
    root=delete(root, val);
    root=curr;
    printf("\n\nThe preorder is:\t");
    preorder(root);
    printf("\n\nThe inorder is:\t");
    inorder(root);
    printf("\n\nThe postorder is:\t");
    postorder(root);
    printf("\n\nThe level-order is:\t");
    level_order(root);

    printf("\n Height of tree:\t%d", height(root));
    }

    printf("\nEnter the value to print the nodes at k-th level\n");
    int k;
    scanf("%d", &k);
 printKdist(root,k);
}