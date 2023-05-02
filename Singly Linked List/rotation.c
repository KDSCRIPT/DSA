#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next; 
};
struct Node* insert(struct Node *head,int x)
{
    if(head==NULL)
    {
        struct Node *head=(struct Node*)malloc(sizeof(struct Node));
        head->data=x;
        head->next=NULL;
        return head;
    }
    struct Node *node=(struct Node*)malloc(sizeof(struct Node));
    node->data=x;
    node->next=head;
    return node;
}
void print(struct Node *head)
{
    if(head!=NULL)
    {
        struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
        ptr=head;
        while(ptr!=NULL)
        {
            printf("%d,",ptr->data);
            ptr=ptr->next;
        }
        free(ptr);
    }
    else printf("Empty linked list");
    printf("\n");
}
int len(struct Node *head)
{
    int size=0;
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr=head;
    while(ptr!=NULL)
    {
        size++;
        ptr=ptr->next;
    }
    free(ptr);
    return size;
}
struct Node* concate(struct Node *head,struct Node *head1)
{
    struct Node *ptr=head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next =head1;
    head1=NULL;
    return head;
}
struct Node* rotate(struct Node *head,int n)
{
    if(n>=len(head))n-=len(head)%n;
    struct Node *ptr=head;
    for(int i=0;i<n-1;i++)
    {
        ptr=ptr->next;
    }
    struct Node *head1=ptr->next;
    ptr->next=NULL;
    // print(head1);
    // print(head);
    head=concate(head1,head);
    return head;
}

int main()
{
    int n,r;
    struct Node* head=NULL;
    printf("Enter number of elements in linked list:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int t;
        printf("Enter element:");
        scanf("%d",&t);
        head=insert(head,t);
    }
    printf("Linked list:");
    print(head);
    printf("Enter number of rotations:");
    scanf("%d",&r);
    head=rotate(head,r);
    print(head);
}