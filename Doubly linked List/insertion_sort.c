#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node* push(struct Node *head,int x)
{
    struct Node *node=(struct Node*)malloc(sizeof(struct Node));
    node->data=x;
    if(head==NULL)
    {
        node->next=NULL;
        node->prev=NULL;
    }
    else
    {
        node->next=head;
        head->prev=node;
    }
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
    else
    {
        printf("Doubly Linked list is empty");
    }
}
struct Node *eleAt(struct Node *head,int idx)
{
    struct Node *temp=head;
    for(int i=0;i<idx;i++)temp=temp->next;
    return temp;
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
int valueAt(struct Node *head,int idx)
{
    struct Node *temp=head;
    for(int i=0;i<idx;i++)temp=temp->next;
    return temp->data;
}
void insertion(struct Node *head)
{
    for(int i=1;i<len(head)+1;i++)
    {
        int key=eleAt(head,i)->data;
        int j=i-1;
        while(j>=0 && (valueAt(head,j))>key)
        {
            eleAt(head,j+1)->data=valueAt(head,j);
            j--;
        }
        eleAt(head,j+1)->data=key;
    }
    print(head);
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
    printf("Linked list:");
    print(head);
    printf("\n");
    printf("Sorted Linked List:");
    insertion(head);

}
