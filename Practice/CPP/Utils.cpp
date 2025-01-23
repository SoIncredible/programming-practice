#include"Head.h"
#include<iostream>
using namespace std;
extern "C" void Swap(int &x, int &y){
	int temp = x;
	x = y;
	y = temp;
}

extern "C" void PrintArr(int *arr, int size){
	
	cout << "Sorted Array:" << endl;
	for(int i = 0; i < size; i++){
		cout << arr[i] << " ";
	}
	cout << "\n";
} 
