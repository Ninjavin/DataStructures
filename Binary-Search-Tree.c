#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *prev;
	struct Node *next;
};

struct Node *root = NULL;

void append(){
	int n;
	printf("\nEnter the value to enter: ");
	scanf("%d",&n);
	struct Node *temp;
	temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = n;
	temp->prev = NULL;
	temp->next = NULL;
	if(root==NULL){
		root = temp;
	}
	else{
		struct Node *current, *parent;
		current = root;
		parent = NULL;
		while(1){
			parent = current;
			if(n <= parent->data){
				current = current->prev;
				if(current==NULL){
					parent->prev = temp;
					return;
				}
			}
			else{
				current = current->next;
				if(current==NULL){
					parent->next = temp;
					return;
				}
			}
		}

	}
}


void in_order(struct Node *root){
	if(root!=NULL){
		in_order(root->prev);
		printf(" %d ",root->data);
		in_order(root->next);
	}
}

void pre_order(struct Node *root){
	if(root!=NULL){
		printf(" %d ",root->data);
		pre_order(root->prev);
		pre_order(root->next);
	}
}

void post_order(struct Node *root){
	if(root!=NULL){
		post_order(root->prev);
		post_order(root->next);
		printf(" %d ",root->data);
	}
}

struct Node * minimum(struct Node *current){
	if(current->prev==NULL){
		return current;
	}
	return minimum(current->prev);
}

struct Node * delete(struct Node *root,int n){
	if(root==NULL)
		return root;
	else if(root->data <n)
		root->next = delete(root->next, n);
	else if(root->data >n)
		root->prev = delete(root->prev, n);
	else{
		if(root->prev==NULL){
            struct Node *temp = root->next;
            free(root);
            return temp;
		}
		else if(root->next==NULL){
            struct Node *temp = root->prev;
            free(root);
            return temp;
		}
		else{
			struct Node *temp = minimum(root->next);
			root->data = temp->data;
			root->next = delete(root->next,temp->data);
		}
	}
	return root;
}
int main(){
	append();
	append();
	append();
	append();
	append();
	append();
	append();
	printf("\nInorder : ");
	in_order(root);
	printf("\nPreOrder : ");
	pre_order(root);
	printf("\nPostOrder : ");
	post_order(root);
	root = delete(root, 15);
	printf("\nInorder : ");
	in_order(root);
	printf("\nPreOrder : ");
	pre_order(root);
	printf("\nPostOrder : ");
	post_order(root);

	return 0;
}
