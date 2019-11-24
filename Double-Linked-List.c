#include<stdio.h>
#include<stdlib.h>

struct Node{
	struct Node *prev;
	struct Node *next;
	int val;
};

struct Node *root;

void insert_at_end(){
	int n;
	printf("Enter the element to enter: ");
	scanf("%d",&n);
	struct Node *temp, *ptr;
	temp = (struct Node*)malloc(sizeof(struct Node));
	temp->val = n;
	temp->next = NULL;
	temp->prev = NULL;
	if(root==NULL){
		temp = root;
	}
	else{
		ptr = root;
		while(ptr->next!=NULL){
			ptr=ptr->next;
		}
		temp->prev = ptr;
		ptr->next = temp;
	}
}

void insert_at_pos(){
	int pos, n;
	printf("Enter the position to enter: ");
	scanf("%d",&pos);
	printf("\nEnter the value to enter: ");
	scanf("%d",&n);
	struct Node *temp, *ptr;
	temp = (struct Node*)malloc(sizeof(struct Node));
	temp->val = n;
	temp->prev = NULL;
	temp->next = NULL;
	if(pos==1){
		temp->next = root;
		root = temp;
	}
	else{
		ptr = root;
		while(pos-2!=0){
			ptr = ptr->next;
		}
		ptr->next->prev = temp;
		temp->next = ptr->next;
		temp->prev = ptr;
		ptr->next = temp;
	}
}

void display(){
	printf("\n");
	struct Node *ptr;
	ptr = root;
	while(ptr->next!=NULL){
		printf("%d ",ptr->val);
		ptr = ptr->next;
	}
	printf("%d\n",ptr->val);
	printf("Displayed\n");
}


void delete(){
	int pos;
	printf("\nEnter the position of element to delete: ");
	scanf("%d",&pos);
	struct Node *ptr;
	ptr = root;
	if(pos==1){
		root->next->prev = NULL;
		root = root->next;
	}
	else{
		while(pos-2!=0){
			ptr=ptr->next;
		}
		ptr->next->next->prev = ptr->next;
		ptr->next = ptr->next->next;
	}
	printf("Deleted\n");
	display();
}

int main(){
	root = (struct Node*)malloc(sizeof(struct Node));
	root->val = 10;
	root->next = NULL;
	root->prev = NULL;
	int t=1;
    int choice;
    while(t){
    printf("      MENU      \n1.Enter 1 to insert at end\n2.Enter 2 to insert at a position\n3.Enter 3 to delete a particular node\n4.Enter 4 to display the entire Linked List\n5.Enter 5 to exit.\n\n");
    scanf("%d",&choice);
        switch(choice){
            case 1: insert_at_end(); break;
            case 2: insert_at_pos(); break;
            case 3: delete(); break;
            case 4: display(); break;
            case 5: t=0; break;
            default: printf("Enter a valid choice.");
        }
    }
	return 0;
}
