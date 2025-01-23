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
	InsertionSort(arr, size);
	PrintArr(arr, size);
	// 删除动态申请的内存
	delete[] arr;
	return 0;
}

void Swap(int& x, int &y){
	int temp = x;
	x = y;
	y = temp;
}

void PrintArr(int* arr, int size){
	cout << "Sorted Array:" << endl;
	for(int i = 0; i < size; i++){
		cout << arr[i] << " ";
	}
	cout << "\n";
}

void InsertionSort(int* arr, int size){
	// 默认一个已经排序好的数列，遍历未排序的数列，将未排序的数列的元素插入进已排序数列的正确位置
	for(int i = 1; i < size; i++){
		int temp = arr[i];
		int index = i - 1; 
		while(index >= 0){
			if(arr[index] > arr[index + 1]){
				Swap(arr[index], arr[index + 1]);
				index--;
				continue;
			}
			break;
		}
	}	
}
