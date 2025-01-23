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
	int *arr = new int[size];

	for(int i = 0; i < size; i++){

		arr[i] = unSort[i];
	}

	
	MergeSort(arr, size);
	PrintArr(arr, size);



	delete[] arr;
	
	return 0;

}

int* Merge(int *arr1, int size1, int *arr2, int size2, int *mergeArr){

	int index1 = 0;
	int index2 = 0;
	int index = 0;
	int size = size1 + size2;

	while(index1 < size1 && index2 < size2){
		if(arr1[index1] < arr2[index2]){
			mergeArr[index++] = arr1[index1++];
		}else{
			mergeArr[index++] = arr2[index2++];
		}
	}	

	while(index1 < size1){
		mergeArr[index++] = arr1[index1++];
	}

	while(index2 < size2){
		mergeArr[index++] = arr2[index2++];
	}
	return mergeArr;
}

int *InnerMergeSort(int *arr, int *mergeArr, int size){
	// mergeArr是新分配的内存空间

	if(size <= 1){
		return arr;
	}

	int size1 = size / 2;
	int size2 = size - size1;

	int *mergeArr1 = new int[size1];
	int *mergeArr2 = new int[size2];

	for(int i = 0; i < size1; i++){
		mergeArr1[i] = arr[i];
	}

	for(int i = 0; i < size2; i++){
		mergeArr2[i] = arr[size1 + i];
	}

	InnerMergeSort(mergeArr1, mergeArr, size1);
	InnerMergeSort(mergeArr2, mergeArr, size2);

	// 收容Merge之后的数组的
	Merge(mergeArr1, size1, mergeArr2, size2, mergeArr);

	delete[] mergeArr1;
	delete[] mergeArr2;

	return  mergeArr;

}


void MergeSort(int *arr, int size){

	int *mergeArr = new int[size];
	arr = InnerMergeSort(arr, mergeArr, size);
	delete[] mergeArr;

}


void PrintArr(int *arr, int size){
	cout << "Sorted Array:" << endl;
	for(int i = 0; i < size; i++){
			cout << arr[i] << " ";
	}
	cout << "\n";

}
