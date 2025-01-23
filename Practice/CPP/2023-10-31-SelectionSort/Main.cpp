#include<iostream>
#include<vector>
#include"Head.h"
using namespace std;


int main(){

	cout << "Input UnSorted Array:" << endl;
	vector<int> unSort;
	int number;
	while(cin >> number){
		unSort.push_back(number);
	}
	
	int size = unSort.size();
	int arr[size];	
	for(int i = 0; i < unSort.size(); i++){
		arr[i] = unSort[i];
	}
	SelectionSort(arr, size);
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

void SelectionSort(int *arr, int size){
	for(int i = 0; i < size; i++){
		int tempIndex = i;
		for(int j = i + 1; j < size; j++){
			if(arr[tempIndex] > arr[j]){
				tempIndex = j;
			} 
		}
		Swap(arr[i], arr[tempIndex]);
	}
}

