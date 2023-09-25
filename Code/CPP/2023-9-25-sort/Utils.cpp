#include"Head.h"
#include<iostream>
using namespace std;
void Swap(int &x, int &y){
	
	int temp = x;
	x = y;
	y = temp;

}

void PrintArray(int *array, int size){
	
	cout << "Sorted Array:" << endl;
	for(int i = 0; i < size; i++){
		cout << array[i] << " ";
	}
	cout << "\n";

}
