#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* push(struct node *head,int x)
{
    if(head==NULL)
    {
        struct node *head=(struct node*)malloc(sizeof(struct node));
        head->data=x;
        head->next=NULL;
        return head;
    }
    struct node *Node=(struct node*)malloc(sizeof(struct node));
    Node->data=x;
    Node->next=head;
    return Node;
}
struct node* append(struct node *head,int x)
{
    if(head==NULL)
    {
        struct node *head=(struct node*)malloc(sizeof(struct node));
        head->data=x;
        head->next=NULL;
        return head;
    }
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr=head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    struct node *Node=(struct node*)malloc(sizeof(struct node));
    Node->data=x;
    Node->next=NULL;
    ptr->next=Node;
    free(ptr);
    return head;
}
struct node* insert(struct node *head,int x,int idx)
{
    struct node *Node=(struct node*)malloc(sizeof(struct node));
    Node->data=x;
    Node->next=NULL;
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr=head;
    if(idx==0)
    {
        head=push(head,x);
        return head;
    }
    if(idx==len(head))
    {
        head=append(head,x);
        return head;
    }
    if(idx>len(head))
    {
        printf("Out of bounds index\n");
        return head;
    }
    for(int i=0;i<idx-1;i++)
    {
        ptr=ptr->next;
    }
    struct node *right=ptr->next;
    ptr->next=Node;
    Node->next=right;
    free(ptr);
    free(right);
    return head;
}
struct node* delete(struct node *head,int idx)
{
    if(idx==0)
    {
        struct node *temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    if(idx>=len(head))
    {
        printf("Out of bounds index\n");
        return head;
    }
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr=head;
    for(int i=0;i<idx-1;i++)
    {
        ptr=ptr->next;
    }
    struct node *right=ptr->next->next;
    ptr->next=right;
    free(ptr);
    return head;
}
int search(struct node* head,int x)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr=head;
    int position=0;
    while(ptr!=NULL)
    {
        if(ptr->data==x)
        {
            free(ptr);
            return position;
        }
        ptr=ptr->next;
        position++;
    }
    printf("Element not found\n");
    free(ptr);
    return -1;
}
int len(struct node* head)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr=head;
    int size=0;
    while(ptr!=NULL)
    {
        size++;
        ptr=ptr->next;   
    }
    free(ptr);
    return size;
}
void print(struct node* head)
{
    if(head==NULL)
    {
        printf("Empty Linked List");
    }
    else
    {
        printf("Linked List:");
        struct node *ptr=(struct node*)malloc(sizeof(struct node));
        ptr=head;
        while(ptr!=NULL)
        {
            printf("%d,",ptr->data);
            ptr=ptr->next;
        }
        free(ptr);
    }
    printf("\n");
}
int main()
{
    struct node* head=NULL;
    int option=-1;
    printf("Enter option to perform operations:\n");
    printf("\n");
    printf("0.exit\n");
    printf("1.Insertion\n");
    printf("2.Search for an element\n");
    printf("3.Length of Linked List\n");
    printf("4.Delete element\n");
    printf("5.print linked list\n");
    while(option!=0)
    {
        printf("Enter option:");
        scanf("%d",&option);
        if(option==1)
        {
            int data,idx;
            printf("Enter data to be inserted:");
            scanf("%d",&data);
            printf("Enter index at which data is to be inserted(%d to %d):",0,len(head));
            scanf("%d",&idx);
            head=insert(head,data,idx);
        }
        if(option==2)
        {
            int data;
            printf("Enter data to be searched:");
            scanf("%d",&data);
            int index=search(head,data);
            if(index!=-1)printf("Element found at index %d\n",index);
        }
        if(option==3)
        {
            printf("Length of linked list:");
            int size=len(head);
            printf("%d",size);
            printf("\n",size);

        }
        if(option==4)
        {
            int idx;
            printf("Enter index of data to be deleted:");
            scanf("%d",&idx);
            head=delete(head,idx);
        }
        if(option==5)print(head);
    }
}