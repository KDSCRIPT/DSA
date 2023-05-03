#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node* insert(struct Node *head, char x)
{
    if(head==NULL)
    {
        struct Node *head=(struct Node*)malloc(sizeof(struct Node));
        head->data=x;
        head->next=NULL;
        return head;
    }
    struct Node *node=(struct Node*)malloc(sizeof(struct Node));
    struct Node *ptr=head;
    node->data=x;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=node;
    return head;
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
void remove_duplicates(struct Node *head)
{
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr=head;
    int curdata=INT_MAX;
    while(ptr->next!=NULL)
    {
        if(ptr->data==ptr->next->data)
        {
            struct Node* deleted=ptr->next;
            struct Node* nextNode=ptr->next->next;
            ptr->next=NULL;
            deleted->next=NULL;
            ptr->next=nextNode;
            free(deleted);
        }
        else ptr=ptr->next;
    }
    print(head);
}
int main()
{
    int n;
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
    printf("Linked list with duplicate elements removed:");
    remove_duplicates(head);
}

