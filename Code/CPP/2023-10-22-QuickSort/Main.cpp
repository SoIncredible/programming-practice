#include<iostream>
#include<vector>
#include"Head.h"

using namespace std;

int main(){

	int number = 0;
	cout << "Input UnSorted Array:" << endl;
	vector<int> unSort;
	while(cin >> number){
		unSort.push_back(number);
	}

	int size = unSort.size();
	int arr[size];

	for(int i = 0; i < size; i++){
		arr[i] = unSort[i];
	}

	QuickSort(arr, size);
	PrintArr(arr, size);

	return 0;
}


void Swap(int &x, int &y){

	int temp = x;
	x = y;
	y = temp;

}

void PrintArr(int *arr, int size){

	cout << "Sorted Array:" << endl;
	for(int i = 0; i < size; i++){
		cout << arr[i] << " ";
	}
	cout << "\n";

}

void QuickSort(int *arr, int size){
	InnerQuickSort(arr, 0, size - 1);
}

void InnerQuickSort(int *arr, int begin, int end){

	if(begin <= end){

		int cur = begin; 
		int pivot = begin;

		while(cur <= end){
			if(arr[cur] < arr[begin])  ++pivot;
			++cur;
		}	

		Swap(arr[pivot], arr[begin]);

		int begin1 = begin;
		int begin2 = pivot + 1;
		int end1 = pivot - 1;
		int end2 = end;

		InnerQuickSort(arr, begin1, end1);
		InnerQuickSort(arr, begin2, end2);
	}


}
