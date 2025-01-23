#include"Head.h"

void SelectionSort(int *arr, int size){
	
	for(int i = 0; i < size; i++){
		int tempMin = arr[i];
		int tempMinJ = i;
		for(int j = i + 1; j < size; j++){
			if(tempMin > arr[j]){
				tempMin = arr[j];
				tempMinJ = j;
			} 
		}
		Swap(arr[i], arr[tempMinJ]);
	}

}
