#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *left,*right;
};
void inorder(struct Node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
int main(){
    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = root;
    temp->left = NULL;
    temp->right=NULL;
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
                temp=root;
                while(1){
                    if(x>temp->data){
                        if(temp->right==NULL){
                            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
                            newNode->left = NULL;
                            newNode->right = NULL;
                            newNode->data = x;
                            temp->right = newNode;
                            break;
                        }
                        else{
                            temp=temp->right;
                        }
                    }
                    else{
                        if(temp->left==NULL){
                            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
                            newNode->data = x;
                            newNode->left = NULL;
                            newNode->right = NULL;
                            temp->left = newNode;
                            break;
                        }
                        else{
                            temp=temp->left;
                        }
                    }
                }
            }
        }
    }

inorder(root);
}