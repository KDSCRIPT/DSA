#include<stdio.h>
#include<stdlib.h>
struct Node* addresses[100];
int idx=0;
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
int checkInArray(struct Node *element,int idx)
{
    for(int i=0;i<idx;i++)
    {
        if(addresses[i]==element)return -1;
    }
    return 0;
}
int looper(struct Node *head)
{
    if(head!=NULL)
    {
        struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
        ptr=head;
        while(ptr->next!=NULL)
        {
            if(checkInArray(ptr->next,idx)==-1)return -1;
            addresses[idx]=ptr->next;
            idx++;
            ptr=ptr->next;
        }
        return 0;   
    }
    return 0;
}
int main()
{
    int n;
    struct Node *head=NULL;
    printf("Enter number of elements:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter element:");
        int t;
        scanf("%d",&t);
        head=insert(head,t);
    }
    //head->next->next->next->next=head;
    if(looper(head)==-1)printf("Loop detected");
    else printf("No Loop detected");
    printf("\n");

}