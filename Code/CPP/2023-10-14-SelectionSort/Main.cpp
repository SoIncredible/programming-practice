#include<iostream>
#include<vector>
#include"Head.h"

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
	
	SelectionSort(arr, size);
	PrintArr(arr, size);

	return 0;
}

void SelectionSort(int *arr, int size){
	for(int i = 0; i < size; i++){
		int tempIdx = i;
		for(int j = i + 1; j < size; j++){
			if(arr[tempIdx] > arr[j]){
				tempIdx = j;
			}
		}
		Swap(arr[tempIdx], arr[i]);
	}
}


void Swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

void PrintArr(int *arr, int size){
	cout << "Sorted Array:" << endl;
	for(int i = 0; i < size; i++){
		cout << arr[i] << " ";
	}
	cout << "\n";
}



