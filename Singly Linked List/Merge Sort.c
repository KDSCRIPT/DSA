#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node* insert(struct Node *head,int x)
{
    if (head==NULL)
    {
        head=(struct Node*)malloc(sizeof(struct Node));
        head->data=x;
        head->next=NULL;
        return head;
    }
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    struct Node* t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;
    ptr=head;
    while(ptr->next!=NULL)ptr=ptr->next;
    ptr->next=t;
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
int eleAt(struct Node *head,int idx)
{
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr=head;
    for(int i=0;i<idx;i++)ptr=ptr->next;
    return ptr->data;
}
struct Node* ptrAt(struct Node* head, int idx)
{
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr=head;
    for(int i=0;i<idx;i++)ptr=ptr->next;
    return ptr;
}
void merge(struct Node *head,int low,int mid,int high)
{
    struct Node* head1=NULL;
    struct Node *ptr,*ptr1;
    int l=low;
    int h=mid+1;
    while(l<=mid && h<=high)
    {
        if(eleAt(head,l)<eleAt(head,h))head1=insert(head1,eleAt(head,l++));
        else head1=insert(head1,eleAt(head,h++));
    }
    while(l<=mid)head1=insert(head1,eleAt(head,l++));
    while(h<=high)head1=insert(head1,eleAt(head,h++));
    ptr=ptrAt(head,low);
    ptr1=head1;
    while(ptr!=NULL && ptr1!=NULL)
    {
        ptr->data=ptr1->data;
        ptr=ptr->next;
        ptr1=ptr1->next;
    }
 }
void mergesort(struct Node *head,int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergesort(head,low,mid);
        mergesort(head,mid+1,high);
        merge(head,low,mid,high);
    }
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
    mergesort(head,0,n-1);
    printf("Merge sorted Linked list:");
    print(head);
}