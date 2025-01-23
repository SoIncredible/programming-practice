#include"Head.h"

extern "C"  void BubbleSort(int *arr, int size){
	
	for(int i = 0; i < size; i++){
		for(int j = 0; i < size - 1 - i; j++){
			if(arr[j] > arr[j+1]){
			     //	Swap(arr[i], arr[j]);
			
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}
