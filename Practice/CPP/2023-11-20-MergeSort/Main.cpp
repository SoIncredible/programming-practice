#include<iostream>
#include"Head.h"
#include<vector>
using namespace std;

int main(){
	cout << "Input Unsorted Array:" << endl;
	int number;
	vector<int> unsortedArr;
	
	while(cin >> number){
		unsortedArr.push_back(number);
	}

	int size = unsortedArr.size();
	int* arr = new int[size];
	
	for(int i = 0; i < size; i++){
		arr[i] = unsortedArr[i];
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

void InnerMergeSort(int* arr, int begin, int end, int size){

	if(begin >= end) return;
	int mid = (begin + end) / 2;
	
	InnerMergeSort(arr, begin, mid, size);
	InnerMergeSort(arr, mid + 1, end, size);
	Merge(arr, begin, mid, end, size);
}

void Merge(int* arr, int begin, int mid, int end, int size){

	// 开辟新的内存空间
	int* temp = new int[size];

	for(int index = begin; index <= end; index++){
		temp[index] = arr[index];
	}

	// 二路归并
	int left;
	int right;
	int index;
	for(index = begin, left = begin, right = mid + 1; left <= mid && right <= end && index <= end; index ++){
		if(temp[left] >= temp[right]){
			arr[index] = temp[right++];
		}else{
			arr[index] = temp[left++];
		}	
	}

	while(left <= mid){
		arr[index++] = temp[left++];
	}
	
	while(right <= end){
		arr[index++] = temp[right++];
	}
	
	delete[] temp;

}
