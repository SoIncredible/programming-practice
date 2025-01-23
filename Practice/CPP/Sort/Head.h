#ifndef HEAD_H
#define HEAD_H
	extern "C" void Swap(int &x, int &y);
	extern "C" void PrintArr(int *arr, int size);
	
	// 排序算法
	extern "C" void BubbleSort(int *arr, int size);
	extern "C" void QuickSort(int *arr, int size);
	void InnerQuickSort(int *arr, int begin, int end);
	
#endif
