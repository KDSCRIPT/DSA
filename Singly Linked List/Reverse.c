#include<stdio.h>
#include<stdlib.h>
struct Node 
{
	int data;
	struct Node* next;
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
struct Node* reverse(struct Node *head)
{
    struct Node *ptr=head;
    struct Node *Next,*prev=NULL;
	while (ptr!=NULL) 
    {    
		Next=ptr->next;
		ptr->next=prev;
		prev=ptr;
		ptr=Next;
	}
	return prev;
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
    printf("Reverse Linked list:");
    head=reverse(head);
    print(head);
}
