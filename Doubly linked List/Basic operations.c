#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
};
struct Node* push(struct Node *head,int x)
{
    if(head==NULL)
    {
        struct Node *head=(struct Node*)malloc(sizeof(struct Node));
        head->data=x;
        head->prev=NULL;
        head->next=NULL;
        return head;
    }
    struct Node *node=(struct Node*)malloc(sizeof(struct Node));
    node->data=x;
    node->next=head;
    head->prev=node;
    return node;
}
void print(struct Node *head)
{
    if(head!=NULL)
    {
        struct Node *temp=head;
        while(temp!=NULL)
        {
            printf("%d,",temp->data);
            temp=temp->next;
        }
    }
    else printf("Empty linked list");
}
void printback(struct Node *head)
{
    if(head!=NULL)
    {
        struct Node *temp=head;
        while(temp->next!=NULL)temp=temp->next;
        while(temp!=NULL)
        {
            printf("%d,",temp->data);
            temp=temp->prev;
        }
    }
    else printf("Empty linked list");
}
int len(struct Node *head)
{
    int size=0;
    if(head!=NULL)
    {
        struct Node *temp=head;
        while(temp->next!=NULL)
        {
            size++;
            temp=temp->next;
        }
        return size;
    }
    else return -1;
}
struct Node* eleAt(struct Node *head,int x)
{
    if(head!=NULL)
    {
        for(int i=0;i<x;i++)
        {
            head=head->next;
        }
        return head;
    }
}
struct Node* insert(struct Node *head,int x,int idx)
{
    struct Node *node=(struct Node*)malloc(sizeof(struct Node));
    node->data=x;
    if(head!=NULL && idx==0)
    {
        node->next=head;
        head->prev=node;
        return node;
    }
    if(head!=NULL && idx>0 && idx<len(head)+1)
    {
        node->next=eleAt(head,idx);
        eleAt(head,idx)->prev=node;
        eleAt(head,idx-1)->next=node;
        node->prev=eleAt(head,idx-1);
    }
    if(head!=NULL && idx==len(head)+1)
    {
        eleAt(head,idx-1)->next=node;
        node->prev=eleAt(head,idx-1);
        return head;
    }
    if(head==NULL || idx>len(head)+1 || idx<0)
    {
        printf("Index out of bounds");
        printf("\n");
    }
    return head;   
}
struct Node* delete(struct Node *head,int idx)
{
    struct Node *node;
    if(head!=NULL && idx==0)
    {
        node=head->next;
        head->next=NULL;
        node->prev=NULL;
        free(head);
        return node;
    }
    if(head!=NULL && idx>0 && idx<len(head))
    {
        node=eleAt(head,idx-1)->next;
        eleAt(head,idx-1)->next=node->next;
        node->next->prev=eleAt(head,idx-1);
        node->prev=NULL;
        free(node);
    }
    if(head!=NULL && idx==len(head))
    {
        node=eleAt(head,idx-1)->next;
        eleAt(head,idx-1)->next=NULL;
        node->prev=eleAt(head,idx-1);
        return head;
    }
    if(head==NULL || idx>len(head) || idx<0)
    {
        printf("Index out of bounds");
        printf("\n");
    }
    return head;   
}
int main()
{
    int n;
    struct Node *head=NULL;
    printf("Enter number of elements:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int t;
        printf("Enter element:");
        scanf("%d",&t);
        head=push(head,t);
    }
    printf("Linked list in order:");
    print(head);
    printf("\n");
    printf("Linked list in reverse order:");
    printback(head);
    printf("\n");
    printf("Length of linked list:%d",len(head));
    printf("\n");
    int a,b;
    printf("Enter element to be inserted:");
    scanf("%d",&a);
    printf("Enter position to be inserted(0,%d):",len(head)+1);
    scanf("%d",&b);
    head=insert(head,a,b);
    print(head);
    int c;
    printf("\n");
    printf("Enter index to be deleted:");
    scanf("%d",&c);
    head=delete(head,c);
    print(head);
}