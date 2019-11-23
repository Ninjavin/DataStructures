#include<stdio.h>
#include<stdlib.h>

struct Node{
    int val;
    struct Node* next;
};

struct Node *root;

void append(struct Node *root){
    int x;
    printf("Enter the number to append: ");
    scanf("%d",&x);
    struct Node *temp;
    temp = (struct Node*)malloc(sizeof(struct Node*)); //C automatically typecasts
    temp->val = x;
    temp->next = NULL;
    if(root==NULL){
        root = temp;
    }
    else{
        struct Node *ptr = root;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next = temp;
    }
}

void insert_at_pos(struct Node *root){
    int pos,x;
    printf("Enter the number to enter: ");
    scanf("%d",&x);
    printf("\nEnter the position: ");
    scanf("%d",&pos);
    struct Node* temp;
    struct Node* ptr;
    ptr = root;
    temp = (struct Node*)malloc(sizeof(struct Node*));
    temp->val = x;
    temp->next = NULL;
    if(pos==1){
        temp->next = root;
        root = temp;
    }
    else{
        while(pos-2!=0){
            ptr = ptr->next;
            pos--;
        }
        temp->next = ptr->next;
        ptr->next = temp;
    }
}

void deleteNode(struct Node *root){
    int pos;
    printf("Enter position to delete: ");
    scanf("%d",&pos);
    struct Node *ptr = root;
    while(pos-2!=0){
        ptr=ptr->next;
        pos--;
    }
    ptr->next = ptr->next->next;
}

void display(struct Node *root){
    printf("\n");
    struct Node* ptr = root;
    while(ptr->next!=NULL){
        printf("%d ",ptr->val);
        ptr=ptr->next;
    }
    printf("%d\n",ptr->val);
    printf("DISPLAYED\n");
}

int main(){
    root = (struct Node*)malloc(sizeof(struct Node));
    root->val = 1;
    root->next = NULL;
    int t=1;
    int choice;
    while(t){
    printf("      MENU      \n1.Enter 1 to append\n2.Enter 2 to insert at a position\n3.Enter 3 to delete a particular node\n4.Enter 4 to display the entire Linked List\n5.Enter 5 to exit.\n\n");
    scanf("%d",&choice);
        switch(choice){
            case 1: append(root); break;
            case 2: insert_at_pos(root); break;
            case 3: deleteNode(root); break;
            case 4: display(root); break;
            case 5: t=0; break;
            default: printf("Enter a valid choice.");
        }
    }
    return 0;
}
