#include<stdio.h>

int josephus(int n, int k){
	if(n==1)
		return 1;
	return ((josephus(n-1,k)+(k-1))%n)+1;
}

int main(){
	int n,k;
	printf("Enter the number of people: ");
	scanf("%d",&n);
	printf("\nEnter the shift: ");
	scanf("%d",&k);
	printf("\nThe person surviving will be: %d",josephus(n,k));
	return 0;
}
