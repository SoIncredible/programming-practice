#ifndef HEAD_H
#define HEAD_H
	extern "C" void Swap(int &x, int &y);
	extern "C" void PrintArr(int *arr, int size);
	
	extern "C" void BubbleSort(int *arr, int size);
	extern "C" void QuickSort(int *arr, int size);
	int InnerQuickSort(int *arr, int begin, int end);

	extern "C" void Sort(int *arr, int size);
	int *GenArr(int *arr, int size);
#endif
