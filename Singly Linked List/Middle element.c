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
        struct Node* head=(struct Node*)malloc(sizeof(struct Node));
        head->data=x;
        head->next=NULL;
        return head;
    }
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=x;
    ptr->next=head;
    return ptr;
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
    else
    {
        printf("Empty linked list");
    }
}
int len(struct Node *head)
{
    int size=0;
    if(head!=NULL)
    {
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
    return size;
}
int middle(struct Node *head)
{
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr=head;
    if(len(head)%2==1)
    {
        for(int i=0;i<((len(head)+1)/2)-1;i++)
        {
            ptr=ptr->next;
        }
        return ptr->data;//1,2,3,4,5
    }
    for(int i=0;i<(len(head)/2);i++)
    {
        ptr=ptr->next;
    }
    return ptr->data;//1,2,3,4,5,6
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
    printf("\n");
    printf("Middle element is:");
    printf("%d",middle(head));
    printf("\n");
}