#include<iostream>
#include"Head.h"
#include<vector>
using namespace std;

int main(){
	cout << "Input UnSorted Array:" << endl;
	int number;
	vector<int> unSort;
	
	while(cin >> number){
		unSort.push_back(number);
	}

	int size = unSort.size();
	int* arr = new int[size];
	
	for(int i = 0; i < size; i++){
		arr[i] = unSort[i];
	}

	MergeSort(arr, size);
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

void MergeSort(int* arr, int size){

	InnerMergeSort(arr, 0, size - 1, size);
}

void InnerMergeSort(int* arr, int low, int high, int size){
	
	if(low >= high) return;
	int mid = (low + high) / 2;
	
	InnerMergeSort(arr, low, mid, size);
	InnerMergeSort(arr, mid + 1, high, size);

	Merge(arr, low, mid, high, size);
}

void Merge(int *arr, int low, int mid, int high, int size){
	
	int index; 
	int left;
	int right;

	// 开辟新的内存空间
	int* temp = new int[size];

	for(index = low; index <= high; index++){
		temp[index] = arr[index];
	}

	// 二路归并
	for(index = low, left = low, right = mid + 1; left <= mid && right <= high && index <= high; index++){
		if(temp[left] < temp[right]){
			arr[index] = temp[left++];
		}else{
			arr[index] = temp[right++];
		}
	}

	while(left <= mid) arr[index++] = temp[left++];
	while(right <= high) arr[index++] = temp[right++];

	delete[] temp;
}
