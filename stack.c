#include<stdio.h>
#define SIZE 10

int stack[SIZE], top=-1;

int isFull(){
	if(top==SIZE-1)
		return 1;
	return 0;
}

int isEmpty(){
	if(top==-1)
		return 1;
	return 0;
}

void push(){
	if(isFull())
		printf("\nStack Overflow\n");
	else{
		int n;
		printf("\nEnter the element to enter: ");
		scanf("%d",&n);
		stack[++top] = n;
	}
}

void pop(){
	if(isEmpty())
		printf("\nNothing to delete\n");
	else{
		--top;
	}
}

void display(){
	if(isEmpty())
		printf("\nNothing to display.\n");
	else{
		int i;
		for(i=0; i<=top; i++)
			printf("%d ",stack[i]);
		printf("\nDisplayed\n");
	}
}

int main(){
	int x=1, choice;
	while(x){
		printf("\n      MENU      \n1.Enter 1 for Push\n2.Enter 2 for Pop\n3.Enter 3 for Display\n4.Enter 4 to exit\n\n");
		scanf("%d",&choice);
		switch(choice){
			case 1: push(); break;
			case 2: pop(); break;
			case 3: display(); break;
			case 4: x=0; break;
			default: printf("\nEnter a valid choice.");
		}
	}
	return 0;
}