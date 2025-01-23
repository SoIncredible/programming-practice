#include"Head.h"

void BubbleSort(int *array,int length){
	
	// int length = GetArrayLength(array);


	for(int i = 0; i < length; i++){
		for(int j = 0; j < length - i - 1; j++){
			if(*(array + j) > *(array + j+1)){
				Swap(*(array+j),*(array+j+1));
			}
		}
	}
}

