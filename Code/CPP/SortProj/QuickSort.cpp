#include"Head.h"

extern "C" void QuickSort(int *arr, int size){

	InnerQuickSort(arr, 0, size - 1);
}


int InnerQuickSort(int *arr, int begin, int end){
	
	if(begin >= end) return 0;

	int pivot = begin;
	int cur = begin;
	
	while(cur <= end){
		if(arr[cur] < arr[begin]) pivot++;
		cur++;
	}
	
	Swap(arr[begin], arr[pivot]);

	int begin1 = begin; 
	int begin2 = pivot + 1;
	int end1 = pivot - 1;
	int end2 = end;

	InnerQuickSort(arr, begin1, end1);
	InnerQuickSort(arr, begin2, end2);
	
	return 0;
}
