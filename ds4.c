#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left,*right;
}*root=NULL,*stack[100];
int top=-1;
void push(struct node *temp)
{
    if(top<99)
    {
        top++;
        stack[top]=temp;
    }
}
struct node *pop()
{
    if(top>=0)
    {
        return stack[top--];
    }
    else
    {
        return NULL;
    }
}
struct node *createNode(int x)
{
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->data=x;
    new->left=NULL;new->right=NULL;
    return new;
}
void insertNode(int x)
{
   struct node *new=createNode(x);
   if(root==NULL)
   {
        root=new;
        printf("Root node created with data %d\n",new->data);
        return;  
   }
   struct node *curr=root;
   struct node *ptr=NULL;
   while(curr!=NULL)
   {
        ptr=curr;
        if(x<curr->data)
        {
            curr=curr->left;   //move to left subtree
        }
        else if (x>curr->data)
        {
            curr=curr->right;  //move to right subtree
        }
        else
        {
            //if value already exists, dont insert it, as no duplicate allowed
            printf("Duplicate value %d not inserted.\n",x);
            return;
        }
   }
    //now ptr points to where the new node should be attached
    if(x<ptr->data)
    {
        ptr->left=new;
    }
    else
    {
        ptr->right=new;
    }
}
void shoot(struct node *root,int m)
{
    struct node *curr=root;
    while(curr!=NULL||top!=-1)
    {
        while(curr!=NULL)
        {
            push(curr);
            curr=curr->left;
        }
        curr=pop();
        if(curr->data>m){
            printf("%d ->",curr->data);
        }
        curr=curr->right;
    }
    printf("\n");
}
void inorder(struct node *root)
{
    struct node *curr=root;
    while(curr!=NULL||top!=-1)
    {
        while(curr!=NULL)
        {
            push(curr);
            curr=curr->left;
        }
        curr=pop();
        printf("%d ->",curr->data);
        curr=curr->right;
    }
    printf("\n");
}

void main()
{
    int ch,x,m;
    while(1)
    {
        printf("1.insertNode 2.inorder 3.shoot 0.exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter data to enter:");
                scanf("%d",&x);
                insertNode(x);
                break;
            case 2:
                printf("Inorder traversal\n");
                inorder(root);
                break;
            case 3:
                printf("enter key to shoot\n");
                scanf("%d",&m);
                printf("displaying elements greater than m: \n");
                shoot(root,m);
                break;
            case 0:
                exit(0);
            default:
                printf("invalid choice!!");
        }
    }
}