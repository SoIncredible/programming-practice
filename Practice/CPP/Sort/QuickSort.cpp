#include"Head.h"

extern "C" void QuickSort(int *arr, int size){
	
	// 基本思想
	// 从数列中挑出一个数作为基准数
	// 将数列中所有比基准数小的数小的数摆放在基准前面，所有比基准大的数摆在基准后面
	// 递归地将小于基准元素的子数列和大于基准元素的子数列排序

	InnerQuickSort(arr, 0, size - 1);
}

void InnerQuickSort(int *arr, int begin, int end){
	
	if(begin < end)
	{
	
		int pivot = begin;
		int cur = begin;

		while(cur <= end){

			if(arr[cur] < arr[begin]){
				pivot++;
			}	

			cur++;
		}

		Swap(arr[begin], arr[pivot]);

		int begin1 = begin;
		int  begin2 = pivot + 1;
		int end1 = pivot - 1; 
		int end2 = end;

		InnerQuickSort(arr, begin1, end1);
		InnerQuickSort(arr, begin2, end2);
	
	}	
}
