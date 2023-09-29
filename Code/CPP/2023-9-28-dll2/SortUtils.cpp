#include"Head.h"
#include<iostream>
using namespace std;
extern "C"  void BubbleSort(int *arr, int size){
	cout << " 开始执行排序算法 " << endl;
	cout << " 待排序数组为: ";
	for(int i = 0; i < size; i++){
		cout << arr[i] << " ";
	}
	
	cout << " 数组的长度为: " << size << endl;

	for(int i = 0; i < size; i++){
		cout << " 进行第"<< i+1 << "轮排序 " << endl;
		for(int j = 0; j < size - 1 - i; j++){
			cout << "  进行第" << j+1 << "次比较，比较的Number为: " << arr[j] << " " << arr[j+1] << endl; 
			if(arr[j] > arr[j+1]){
			     	Swap(arr[j], arr[j+1]);
				cout << "    交换的Number为: " << arr[j] << " " << arr[j+1] << endl;
			}
		}
	}
	
	PrintArr(arr,size);
	
}
