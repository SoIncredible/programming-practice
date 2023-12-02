#include<iostream>
#include"Head.h"
#include<vector>
using namespace std;

int main(){
	cout << "Input Unsorted Arr" << endl;
	vector<int> unsortedArr;
	int number;
	while(cin >> number){
		unsortedArr.push_back(number);
	}
	int size = unsortedArr.size();
	int* arr = new int[size];
	for(int i = 0; i < size; i++){
		arr[i] = unsortedArr[i];
	}

	BubbleSort(arr, size);
	PrintArr(arr, size);
	return 0;
}

void Swap(int& x, int& y){
	int temp = x;
	x = y;
	y = temp;
}

void PrintArr(int* arr, int size){
	cout << "Sorted Arr:" << endl;
	for(int i = 0; i < size; i++){
		cout << arr[i] << " ";
	}
	cout << "\n";
}

void BubbleSort(int* arr, int size){
	for(int i = 0; i < size; i++){
		int maxIndex = i;
		for(int j = 0; j < size - i - 1; j++){
			if(arr[j + 1] < arr[j]){
				Swap(arr[j+1], arr[j]);
			}
		}
	}
}	
