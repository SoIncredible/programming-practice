#include<iostream>
#include<vector>
#include"Head.h"
using namespace std;

int main(){

	cout << "Input Unsorted Array:" << endl;
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

	InsertionSort(arr, size);
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

void InsertionSort(int *arr, int size){
	for(int i = 0; i < size; i++){
		int index = i - 1;
		while(index >= 0){
			if(arr[index] > arr[index + 1]){
				Swap(arr[index], arr[index+1]);
				--index;
				continue;
			}
			break;
		}
	}
}
