#include"Head.h"
#include<iostream>
using namespace std;
void Swap(int &x, int &y){
	int temp = x;
	x = y;
	y = temp;
}

int GetArrayLength(int array[]){

	//int *beg = begin(array);
	//int *end = end(array);


	int length = 0;

	//while(beg != end){
	//	length++;
	//	begin++;
	//}

	return length;
}

void PrintArray(int *array, int length){

	cout << "Sorted Array:" << endl;


	// int length = GetArrayLength(array);
	
	cout << "the length is: " << length << endl;

	for(int i = 0; i < length; i++){
		cout << array[i] << " ";
	}
	cout << "\n";
}
	
