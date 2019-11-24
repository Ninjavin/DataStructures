#include<stdio.h>
#define SIZE 100

int c_queue[SIZE], front=-1, rear=-1;

int isFull(){
    if((front==0 && rear==SIZE-1)||(front==rear+1))
        return 1;
    return 0;
}

int isEmpty(){
    if(front==-1)
        return 1;
    return 0;
}

void insert(){
	int n;
	printf("\nEnter the element to enter: ");
	scanf("%d",&n);
	if(isFull()){
        printf("\nQueue is Full. Can't insert.\n");
	}
	else{
        if(front==-1)
            front=0;
        rear = (rear+1)%SIZE;
        c_queue[rear] = n;
        printf("\nInserted Successfully\n");
    }
}

void delete(){
	if(isEmpty()){
        printf("\nNothing to Delete.\n");
	}
	else{
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else{
            front=(front+1)%SIZE;
        }
	}
}

void display(){
    int i;
	if(isEmpty())
        printf("\nNothing to Delete\n");
    else{
        for(i=front;i!=rear;i=(i+1)%SIZE){
            printf("%d ",c_queue[i]);
        }
        printf("%d\n",c_queue[i]);
        printf("Displayed\n");
    }
}



int main(){
	int x=1, choice;
	while(x){
		printf("      MENU      \nEnter 1 for Insertion\nEnter 2 for Deletion\nEnter 3 for Displaying\nEnter 4 to exit\n\n");
		scanf("%d",&choice);
		switch(choice){
			case 1: insert(); break;
			case 2: delete(); break;
			case 3: display(); break;
			case 4: x=0; break;
			default: printf("\nEnter a valid choice\n");
		}
	}
	return 0;
}
