#include<stdio.h>
#define MAX 100
int top=-1;
char s[MAX];

int isOperand(char x){
	if((x>='a'&&x<='z')||(x>='A'&&x<='Z'))
		return 1;
	return 0;
}

void push(char x){
	s[++top] = x;
}

char pop(){
	return s[top--];
}

int priority(char x){
	if(x=='(')
		return 0;
	else if(x=='+'||x=='-')
		return 1;
	else if(x=='*'||x=='/')
		return 2;
}

int main(){
	char exp[MAX], postfix[MAX], *e;
	int p=0;
	printf("Enter the infix expression: ");
	scanf("%s",exp);
	e=exp;
	printf("\nPostfix Expression : ");
	while(*e!='\0'){
		if(isOperand(*e)){
			postfix[p] = *e;
			printf("%c",postfix[p++]);
		}
		else if(*e=='(')
			push(*e);
		else if(*e==')'){
			while(s[top]!='('){
				postfix[p]=pop();
				printf("%c",postfix[p++]);

			}
			top--;
		}
		else{
			while(priority(s[top])>=priority(*e)){
				postfix[p]= pop();
				printf("%c",postfix[p++]);
			}
			push(*e);
		}
		e++;
	}
	while(top!=-1){
		postfix[p] = pop();
		printf("%c",postfix[p++]);
	}
	return 0;
}
