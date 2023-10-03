#include"Head.h"
#include<iostream>

using namespace std;

extern "C" void Swap(int &x, int &y){

	int temp = x;
	x = y;
	y = temp;

}


extern "C" void PrintArr(int *arr, int size){

	cout << "Sorted Array:" << endl;
	for(int i = 0; i < size; i++){
		cout << arr[i] << " ";
	}
	cout << "\n";
}


extern "C" void Sort(int *arr, int size){
	int* bubbleArr = GenArr(arr, size);	
	cout << "Execute Bubble Sort..." << endl;
	BubbleSort(bubbleArr, size);
	cout << "Bubble Sort Result:" << endl;
	PrintArr(bubbleArr, size);

	cout << "\n";
	cout << "\n";

	for(int i = 0; i < 20; i++){
		cout << "*";
	}
	cout << "\n";

	cout << "\n";
	cout << "\n";

	int *quickArr = GenArr(arr, size);
	cout << "Execute Quick Sort..." << endl;
	QuickSort(quickArr, size);
	cout << "Quick Sort Result:" << endl;
	PrintArr(quickArr, size);
}

int *GenArr(int *arr, int size){
	int *array = new int[size];
	for(int i = 0; i < size; i++){
		array[i] = arr[i];
	}
	return array;
}
