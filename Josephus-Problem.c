#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

struct Node *root = NULL;

int survivor(int m){
	//Delete mth node until only one node is present in the list
	struct Node *temp = root;
	struct Node *ptr = root;
	int i;
	while(temp->next!=temp){
		for(i=0; i<m-1;i++){
            ptr = temp;
            temp = temp->next;
		}
		ptr->next = temp->next;
		printf("\n%d killed.",temp->data);
		free(temp);
		temp = ptr->next;
	}
	root = temp;

	return temp->data;
}

void create(){
	struct Node *temp;
	int n;
	printf("Enter the element: ");
	scanf("%d",&n);
	temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = n;
	temp->next = NULL;
	if(root==NULL){
		temp = root;
	}
	else{
		struct Node *ptr;
		ptr = root;
		while(ptr->next!=root){
			ptr = ptr->next;
		}
		temp->next = root;
		ptr->next = temp;
	}
}

void display(){
	struct Node *ptr = root;
	do{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	while(ptr!=root);
}

int main(){
	root = (struct Node*)malloc(sizeof(struct Node));
	root->data = 1;
	root->next = root;
	int gap;
	create();
	create();
	create();
	create();
	printf("The persons involved are: \n");
	display();
	printf("\nEnter the people to skip: ");
	scanf("%d",&gap);
	printf("\nThe person surviving is: %d",survivor(gap));
	return 0;
}
