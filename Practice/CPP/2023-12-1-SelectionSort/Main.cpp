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
		
	SelectionSort(arr, size);
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


void SelectionSort(int* arr, int size){
	// 遍历所有元素，每次遍历将该次遍历的最小的元素与未排序的数列的头一个元素进行交换
	for(int i = 0; i < size; i++){
		int minIndex = i;
		for(int j = i; j < size; j++){
			if(arr[minIndex] > arr[j]){
				minIndex = j;
			}
		}
		Swap(arr[i], arr[minIndex]);
	}
}

void Swap(int& x, int& y){
	int temp = x;
	x = y;
	y = temp;
}
