#include<iostream>
#include"Head.h"
#include<vector>
using namespace std;

int main(){

	cout << "Input Unsorted Array:" << endl;
	
	int number;
	vector<int> unsortedArray;
	while(cin >> number){
		unsortedArray.push_back(number);
	}
	
	int size = unsortedArray.size();
	int* arr = new int[size];

	for(int i = 0; i < size; i++){
		arr[i] = unsortedArray[i];
	}

	QuickSort(arr, size);
	PrintArr(arr, size);
	
	return 0;
}

void PrintArr(int* arr, int size){
	cout << "Sorted Array:" << endl;
	for(int i = 0; i < size; i++){
		cout << arr[i] << " ";
	}
	cout << "\n";
}

void QuickSort(int* arr, int size){
	InnerQuickSort(arr, 0, size - 1);
}

void InnerQuickSort(int* arr, int begin, int end){
	if(begin >= end){
		return;
	}
	
	int pivot = begin;
	int cur = begin;

	while(cur <= end){
		if(arr[cur] < arr[pivot]){
			pivot++;
		}
		cur++;
	}	
	Swap(arr[begin], arr[pivot]);

	int begin1 = begin;
	int end1 = pivot -1;
	int begin2 = pivot + 1;
	int end2 = end;
	
	InnerQuickSort(arr, begin1, end1);
	InnerQuickSort(arr, begin2, end2);
}

void Swap(int& x, int& y){
	int temp = x;
	x = y;
	y = temp;
}
