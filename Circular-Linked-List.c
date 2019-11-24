#include<stdio.h>
#include<stdlib.h>

struct Node{
	int val;
	struct Node* next;
};

//The only difference between Circular Linked List and a Linear Linked List is that the next pointer of the last node isn't NULL, it is a pointer to the root node of the Linked List

struct Node *root;

int length(){
	struct Node *ptr = root;
	int count=0;
	if(root==NULL)
		return 0;
	do{
		ptr = ptr->next;
		count++;
	}
	while(ptr!=root);
	return count;
}

void display(){
	struct Node *ptr = root;
	if(root==NULL)
		printf("\nNothing to display.\n");
	do{
		printf("%d ",ptr->val);
		ptr=ptr->next;
	}
	while(ptr!=root);
}

void insert_at_end(){
	struct Node *temp, *ptr;
	temp = (struct Node*)malloc(sizeof(struct Node));
	int data;
	printf("\nEnter the element to enter: ");
	scanf("%d",&data);
	temp->val = data;
	temp->next = NULL;
	ptr = root;
	while(ptr->next!=root){
		ptr=ptr->next;
	}
	temp->next = root;
	ptr->next = temp;
}

void insert_at_front(){
	struct Node *temp, *ptr;
	temp = (struct Node*)malloc(sizeof(struct Node));
	int data;
	printf("\nEnter the element to enter: ");
	scanf("%d",&data);
	temp->val = data;
	temp->next = NULL;
	ptr = root;
	while(ptr->next!=root)
		ptr=ptr->next;
	temp->next = root;
	ptr->next = temp;
	root = temp;
}

void delete_last_node(){
	if(root==NULL)
		printf("Nothing to delete.\n");
	else{
		struct Node *ptr;
		ptr= root;
		while(ptr->next->next!=root)
			ptr=ptr->next;
		ptr->next->next = NULL;
		ptr->next = root;
	}
}

void delete_first_node(){
	if(root==NULL)
		printf("Nothing to delete\n");
	else{
		struct Node *ptr;
		ptr= root;
		while(ptr->next!=root)
			ptr = ptr->next;
		ptr->next = root->next;
		root = root->next;
	}
}


int main(){
	root = (struct Node*)malloc(sizeof(struct Node));
	root->val = 1;
	root->next = root;
	int x=1, choice;
	while(x){
		printf("      MENU      \nEnter 1 for Inserting at end\nEnter 2 for Inserting at Front\nEnter 3 for Displaying\nEnter 4 for Deleting First Node\nEnter 5 for Deleting Last Node\nEnter 6 for finding the length of the list\nEnter 7 for exit\n\n");
		scanf("%d",&choice);
		switch(choice){
			case 1: insert_at_end(); break;
			case 2: insert_at_front(); break;
			case 3: display(); break;
			case 4: delete_first_node(); break;
			case 5: delete_last_node(); break;
			case 6: length(); break;
			case 7: x=0; break;
			default: printf("\nEnter a valid choice\n");
		}
	}
	return 0;
}
