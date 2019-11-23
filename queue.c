#include<stdio.h>
#define SIZE 100
int linear_queue[SIZE], front=-1, rear=-1;
void insert_at_end(){
	int n;
	printf("Enter the number to insert: ");
	scanf("%d",&n);
	if(rear==SIZE-1){
		printf("\nNo empty space in queue\n");
	}
	else{
		if(front==-1){
			front=0;
		}
		linear_queue[++rear] = n;
        printf("Inserted Successfully\n");
	}
}

void delete(){
	if(front==rear){
		printf("\nNothing to delete in the queue.\n");
	}
	else{
		printf("The item deleted is: %d\n",linear_queue[front]);
		front++;
		if(front==rear){
			front=-1;
			rear=-1;
		}
	}
}

void display(){
	if(rear==-1){
		printf("\nQueue is empty");
	}
	else{
		int i;
		for(i=front;i<=rear;i++){
			printf("%d ",linear_queue[i]);
		}
		printf("\nDisplayed.\n");
	}
}

int main(){
	int x=1, choice;
	while(x){
		printf("      MENU      \n1.Enter 1 for Insertion\n2.Enter 2 for Deletion\n3.Enter 3 for Displaying the Queue\n4.Enter 4 to exit\n\n");
		scanf("%d",&choice);
		switch(choice){
			case 1: insert_at_end(); break;
			case 2: delete(); break;
			case 3: display(); break;
			case 4: x=0; break;
			default: printf("\nEnter a valid choice.");
		}
	}
	return 0;
}
