#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

struct Node *root1 = NULL;
struct Node *root2 = NULL;

void display(struct Node *temp){
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
}

void merge(){
	struct Node *temp1 = root1;
	struct Node *temp2 = root2;
	struct Node *result;

	result = (struct Node*)malloc(sizeof(struct Node));
	struct Node *root = result;
	while(temp1!=NULL && temp2!=NULL){
		if(temp1->data <= temp2->data){
			result->next = temp1;
			temp1 = temp1->next;
		}
		else{
			result->next = temp2;
			temp2 = temp2->next;
		}
		result = result->next;
	}
	while(temp1!=NULL){
		result->next = temp1;
		temp1=temp1->next;
		result = result->next;
	}
	while(temp2!=NULL){
		result->next = temp2;
		temp2=temp2->next;
		result = result->next;
	}
	display(root->next);
}



int main(){
	struct Node *one = (struct Node*)malloc(sizeof(struct Node));
	struct Node *two = (struct Node*)malloc(sizeof(struct Node));
	struct Node *three = (struct Node*)malloc(sizeof(struct Node));
	struct Node *four = (struct Node*)malloc(sizeof(struct Node));
	struct Node *five = (struct Node*)malloc(sizeof(struct Node));
	struct Node *six = (struct Node*)malloc(sizeof(struct Node));
	struct Node *seven = (struct Node*)malloc(sizeof(struct Node));
	struct Node *eight = (struct Node*)malloc(sizeof(struct Node));
	struct Node *nine = (struct Node*)malloc(sizeof(struct Node));

	root1 = one;
	root2 = two;

	one->data = 50;
	one->next = three;

	two->data = 25;
	two->next = four;

	three->data = 50;
	three->next = five;

	four->data = 45;
	four->next = six;

	five->data = 50;
	five->next = seven;

	six->data = 65;
	six->next = eight;

	seven->data = 50;
	seven->next = nine;

	eight->data = 85;
	eight->next = NULL;

	nine->data = 50;
	nine->next = NULL;

	printf("\nBefore Merging: \n");
	printf("Linked List 1: ");
	display(root1);
	printf("\nLinked List 2: ");
	display(root2);
	printf("\nAfter Merging: \n");
	merge();
	return 0;
}
