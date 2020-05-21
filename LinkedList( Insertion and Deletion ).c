#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
int main()
{
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
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
        temp->next = NULL;
    }
    temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
    int key;
    scanf("%d",&key);
    temp=head;
    struct Node* prev = NULL;
    while(temp!=NULL){
        if(temp->data==key){
            if(temp==head){
                head=temp->next;
            }
            else if(temp->next == NULL){
                prev->next = NULL;
            }
            else{
                prev->next = temp->next;
            }
            break;

        }
        prev=temp;
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}