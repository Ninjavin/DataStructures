#include<stdio.h>
#define SIZE 10

int dequeue[SIZE], front=-1, rear=-1;

int isFull(){
	if(front==0 && rear==SIZE-1)
		return 1;
	return 0;
}

int isEmpty(){
	if(front==-1)
		return 1;
	return 0;
}

void insert_at_rear(){
	int ele;
	printf("\nEnter the element to enter: ");
	scanf("%d",&ele);
	if(isFull()){
		printf("\nQueue is Full.\n");
	}
	else{
		if(front==-1)
			front=0;
		dequeue[++rear] = ele;
		printf("\nInserted Successfully\n");
	}
}

void delete_at_end(){
	if(isEmpty())
		printf("\nQueue is Empty. Nothing to Delete\n");
	else{
		if(front==rear)
			front=rear=-1;
		else if(rear==0)
			rear=SIZE-1;
		else
			--rear;
	}
}
//Bugs Present
void insert_at_front(){
	if(isFull()){
		printf("\nQueue is full.\n");
	}
	else{
		int ele;
		printf("\nEnter the element to enter: ");
		scanf("%d",&ele);
		if(front==-1){
			front=0;
			rear=0;
			dequeue[rear]=ele;
		}
		else if(front==0){
			front=SIZE-1;
			dequeue[front]=ele;
		}
		else{
			dequeue[--front]=ele;
		}
	}
}
//Bugs

void delete_at_front(){
	if(isEmpty())
		printf("\nNothing to Delete.\n");
	else{
		if(front==rear)
			front=rear=-1;
		else if(front==SIZE-1)
			front=0;
		else
			++front;
	}
}

void display(){
	if(isEmpty())
		printf("\nNothing to Delete");
	else{
		int i;
		for(i=front; i<=rear; i++)
			printf("%d ",dequeue[i] );
		printf("\nDisplayed\n");
	}
}

int main(){
	int x=1, choice;
	while(x){
		printf("\n      MENU      \n1.Enter 1 for InsertionAtEnd\n2.Enter 2 for DeletionAtEnd\n3.Enter 3 for InsertionAtFront\n4.Enter 4 for DeletionAtFront\n5.Enter 5 for Displaying the Queue\n6.Enter 6 to exit\n\n");
		scanf("%d",&choice);
		switch(choice){
			case 1: insert_at_rear(); break;
			case 2: delete_at_end(); break;
			case 3: insert_at_front(); break;
			case 4: delete_at_front(); break;
			case 5: display(); break;
			case 6: x=0; break;
			default: printf("\nEnter a valid choice.");
		}
	}
	return 0;
}
