#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* halfReverse(struct Node* head){
    struct Node* temp = head;
    struct Node *prev=NULL,*nextNode=temp->next;
    while(1){
        temp->next = prev;
        if(nextNode==NULL){
            return temp;
        }
        prev=temp;
        temp=nextNode;
        nextNode=temp->next;
    }
}
int main()
{
   struct Node* head= (struct Node*)malloc(sizeof(struct Node));
struct Node* temp = head;
int x,len=0;
scanf("%d",&x);
if(x!=-1){
    len++;
    temp->data = x;
    while(1){
        scanf("%d",&x);
        if(x==-1){
            break;
        }
        else{
            len++;
            struct Node* new = (struct Node*)malloc(sizeof(struct Node));
            new->data = x;
            temp->next = new;
            temp=temp->next;
        }
    }
}
temp->next = NULL;
temp=head;
struct Node *s_ptr=head,*f_ptr=head,*prev=NULL,*head1;
while(f_ptr->next!=NULL && f_ptr->next->next!=NULL){
    prev=s_ptr;
    s_ptr=s_ptr->next;
    f_ptr=f_ptr->next->next;
}
if(len%2==0){
    head1 = s_ptr->next;
    s_ptr->next = NULL;
    head = halfReverse(head);
    head1= halfReverse(head1);
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = head1;
}
else{
    head1 = s_ptr->next;
    prev->next = NULL;
    head=halfReverse(head);
    head1=halfReverse(head1);
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = s_ptr;
    s_ptr->next = head1;
}
temp=head;
while(temp!=NULL){
    printf("%d ",temp->data);
    temp=temp->next;
}
}