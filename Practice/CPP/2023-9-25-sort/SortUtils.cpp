#include"Head.h"

void BubbleSort(int *array, int size){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size - i - 1; j++){
			if(array[j] > array[j+1]) Swap(array[j],array[j+1]);
		}
	}		
}
