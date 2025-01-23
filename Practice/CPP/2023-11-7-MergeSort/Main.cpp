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
	int arr[size];
	for(int i = 0; i < size; i++){
		arr[i] = unSort[i];
	}
	
	int *arrSort = MergeSort(arr, size); 
	PrintArr(arrSort,size);
	return 0;
}

void PrintArr(int *arr, int size){
	cout << "Sorted Array:" << endl;
	for(int i = 0; i < size; i++){
		cout << arr[i] << " ";
	}
	cout << "\n";
}


int* Merge(int *arr1, int size1, int *arr2, int size2){

	int index1 = 0;
	int index2 = 0;

	int size = size1 + size2;
	int *arr = new int[size];
	int index = 0;
	while(index1 < size1 && index2 < size2){
		if(arr1[index1] < arr2[index2]){
			arr[index] = arr1[index1];
			index++;
			index1++;	
		}else{
			arr[index] = arr2[index2];
			index++;
			index2++;
		}
	}
	while(index1 < size1){
		arr[index] = arr1[index1];
		index++;
		index1++;
	}

	while(index2 < size2){
		arr[index] = arr2[index2];
		index++;
		index2++;
	}
	return arr;
}

int* MergeSort(int *arr, int size){

	if(size <= 1){
		return arr;
	}

	int size1 = size / 2;
	int size2 = size - size1;

	int *arr1 = new int[size1];
	int *arr2 = new int[size2];

	for(int i = 0; i < size1; i++){
		arr1[i] = arr[i];
	}
	
	for(int i = 0; i < size2; i++){
		arr2[i] = arr[size1 + i];
	}

	return Merge(MergeSort(arr1, size1), size1,  MergeSort(arr2, size2), size2); 
}
