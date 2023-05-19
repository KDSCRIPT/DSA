#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node
{
    char data;
    struct Node* prev;
    struct Node* next;
};
struct Node* push(struct Node *head,char x)
{
    struct Node *node=(struct Node*)malloc(sizeof(struct Node));
    if(head==NULL)
    {
        node->data=x;
        node->prev=NULL;
        node->next=NULL;
    }
    else
    {
        node->data=x;
        node->next=head;
        head->prev=node;
    }
    return node;
}
char elementAt(struct Node *head,int idx)
{
    if(head!=NULL)
    {
        struct Node *ptr=head;
        for(int i=0;i<idx;i++)
        {
            ptr=ptr->next;
        }
        return ptr->data;
    }
    else
    {
        printf("Empty Linked List");
        return '*';
    }
}
int len(struct Node *head)
{
    int size=0;
    if(head!=NULL)
    {
        struct Node *ptr=head;
        while(ptr!=NULL)
        {
            size++;
            ptr=ptr->next;
        }
        return size;
    }
    else
    {
        printf("Empty Linked List");
        return -1;
    }
}
int isPalindrome(struct Node *head)
{
    int start=0;
    int end=len(head)-1;
    while(start<=end)
    {
        if(elementAt(head,start)!=elementAt(head,end))return -1;
        start++;
        end--;
    }
    return 0;
}
int main()
{
    char str[100];
    int idx=0;
    struct Node* head=NULL;
    printf("Enter string:");
    scanf("%s",&str);
    for(int i=0;i<strlen(str);i++)head=push(head,str[i]);
    if(isPalindrome(head)==0)printf("%s is a palindrome",str);
    if(isPalindrome(head)==-1)printf("%s is not a palindrome",str);
}
