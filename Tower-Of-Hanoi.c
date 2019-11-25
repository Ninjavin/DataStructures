#include<stdio.h>

void tower_of_Hanoi(char from, char to, char via, int n){
	if(n==1){
		printf("Move the disc from %c to %c",from, to);
		return;
	}
	tower_of_Hanoi(from, via, to, n-1);
	printf("\nMove %dth disk from %c to %c \n",n,from,to);
	tower_of_Hanoi(via, to, from, n-1);
}

int main(){
    char A, B, C;
	tower_of_Hanoi('A','C','B',3);
	return 0;
}
