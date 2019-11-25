#include<stdio.h>

void bubbleSort(int arr[], int arr_size){
	int i, j, temp;
	for(i=0; i<arr_size-1;i++){
		for(j=0; j<arr_size-1-i; j++){
			if(arr[j]>arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	for(i=0; i<arr_size; i++)
		printf("%d ",arr[i]);
}

void insertionSort(int arr[], int arr_size){
	int i, key;
	for(i=1; i<arr_size; i++){
		int j = i;
		while(j>0 && arr[j-1]>arr[j]){
			key = arr[j-1];
			arr[j-1] = arr[j];
			arr[j] = key;
			j--;
		}
	}
	for(i=0; i<arr_size;i++)
		printf("%d ",arr[i]);
}

void merge(int *arr, int start,int last){
    int mid = (start+last)/2;
	int temp[4]; //Resultant Array
	int k=start; //Iterates through resultant array
	int i=start; //Iterates through start to mid
	int j=mid+1; //Iterates through mid+1 to end
	while(i<=mid && j<=last){
		if(arr[i]<arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}
	while(i<=mid){
		temp[k++] = arr[i++];
	}
	while(j<=last)
		temp[k++] = arr[j++];

	for(i=start; i<=last; i++)
		arr[i]=temp[i];
}

void mergeSort(int arr[], int lb, int ub){
    if(lb>=ub)
        return;
	if(lb<ub){
		int mid;
		mid = (lb+ub)/2;
		mergeSort(arr, lb, mid);
		mergeSort(arr, mid+1, ub);
		merge(arr, lb, ub);
	}
}

int partition(int arr[],int lb,int ub){
	int pivot = arr[ub]; //Last Element taken as Pivot
	int j,temp;
	int i= lb-1;
	for(j=lb;j<=ub-1;j++){
		if(arr[j]<pivot){
			i++;
			temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
	}
	temp = arr[i+1];
	arr[i+1] = arr[ub];
	arr[ub] = temp;

	return i+1;
}

void quickSort(int arr[], int lb, int ub){
	if(lb<ub){
		int p = partition(arr,lb,ub);
		quickSort(arr,lb,p-1);
		quickSort(arr,p+1,ub);
	}
}

int main(){
	int arr[] = {5,1,2,0};
	int arr_size = sizeof(arr)/sizeof(arr[0]);
	int i;
	printf("Sort using Bubble Sort: ");
	bubbleSort(arr, arr_size);
	printf("\nWorst Case Time Complexity is O(n^2)");
	printf("\n\nSort using Insertion Sort: ");
	insertionSort(arr, arr_size);
	printf("\nWorst Case Time Complexity is O(n^2)");
	printf("\n\nSort using Merge Sort: ");
	mergeSort(arr,0,3);
	for(i=0;i<4;i++)
        printf("%d ",arr[i]);
    printf("\nWorst Case Time Complexity is O(nlogn)");
    printf("\n\nSort using Quick Sort: ");
    quickSort(arr,0,3);
    for(i=0;i<4;i++)
    	printf("%d ",arr[i]);

	return 0;
}
