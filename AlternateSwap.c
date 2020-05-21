#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
int main()
{
     struct Node* head= (struct Node*)malloc(sizeof(struct Node));
struct Node* temp = head;
int x;
scanf("%d",&x);
if(x!=-1){
    temp->data = x;
    while(1){
        scanf("%d",&x);
        if(x==-1){
            break;
        }
        else{
            struct Node* new = (struct Node*)malloc(sizeof(struct Node));
            new->data = x;
            temp->next = new;
            temp=temp->next;
        }
    }
}
temp->next = NULL;
temp=head;
struct Node* prev=NULL;
struct Node* inter = temp->next;
while(1){
    temp->next=inter->next;
    inter->next = temp;
    if(prev==NULL){
        head=inter;
    }
    else{
        prev->next = inter;
    }
    prev=temp;
    temp=temp->next;
    if(temp==NULL || temp->next==NULL){
        break;
    }
    inter = temp->next;

}
temp=head;
while(temp!=NULL){
    printf("%d ",temp->data);
    temp=temp->next;
}

}