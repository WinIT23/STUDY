#include<stdio.h>
#include<malloc.h>
struct node{
    int data;
    struct node *left,*right;
};

struct node* insert(struct node*,int);
struct node* del(struct node*,int);
void traverse(struct node*);
void preorder(struct node*);
void inorder(struct node*);
void postorder(struct node*);
struct node * leastValue(struct node*);
struct node* deleteNode(struct node*, int);
struct node* createNode();

int main(){
    struct node *root=NULL;
    int choice,element;
    do{
        printf("Enter your choice:\n");
        printf("1. Insert\n2. Delete\n3. Traverse\n");
        scanf("%d",&choice);
        if(choice==1){
            printf("Enter element to be inserted: ");
            scanf("%d",&element);
            root=insert(root,element);
        }
        else if(choice==2){
            printf("Enter element to be deleted: ");
            scanf("%d",&element);
            root=deleteNode(root,element);}
        else if(choice==3)
            traverse(root);
        else
            break;
    }while(1);
    return 0;
}

struct node* insert(struct node* root,int ele)
{
    if(root==NULL)
        return createNode(ele);
    if (ele<root->data)
        root->left=insert(root->left,ele);
    else if (ele>root->data)
        root->right=insert(root->right,ele);
    return root;
}

/*struct node* del(struct node* root,int element){
    struct node *temp;
    if(root==NULL)
        return root;

    if(element<root->data)
        root->left=del(root->left,element);
    else if(element>root->data)
        root->right=del(root->right,element);
    else{
        if(root->left==NULL){
            temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            temp=root->left;
            free(root);
            return temp;
        }
    }
}*/
struct node* deleteNode(struct node* root, int element)
{

    if (root == NULL) return root;
    if (element < root->data)
        root->left = deleteNode(root->left, element);
    else if (element > root->data)
        root->right = deleteNode(root->right, element);
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = leastValue(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
struct node * leastValue(struct node* node)
{
    struct node* current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

void traverse(struct node *root){
    int choice;
    printf("1. Preorder\n2. Inorder\n3. Postorder\n");
    scanf("%d",&choice);
    switch(choice){
            case 1: printf("Preorder: ");preorder(root); break;
            case 2: printf("Inorder: ");inorder(root);break;
            case 3: printf("Postorder: ");postorder(root);
    }
    printf("\n");
}

void preorder(struct node *root){
    if(root==NULL)
        return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node *root){
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void postorder(struct node *root){
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}


struct node* createNode(int ele){
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=ele;
	newnode->left=NULL;
	newnode->right=NULL;
    return newnode;
}
