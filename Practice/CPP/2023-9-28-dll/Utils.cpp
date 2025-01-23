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

extern "C" void BubbleSort(int *arr, int size){

	cout << " 执行重新编译后的结果" << endl;
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size - 1 - i; j++){

			if(arr[j] > arr[j+1]){
				// int temp = arr[j];
				// arr[j] = arr[j+1];
				// arr[j+1] = temp;
				Swap(arr[j], arr[j+1]);
			}

		}
	}

}
