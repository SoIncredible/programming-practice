#include"Head.h"
#include<iostream>
using namespace std;

extern "C" void Test1(int *arr, int size){

	for(int i = 0; i < size; i++){
		cout << arr[i] << endl;
	}
	cout << "Test1" << endl;
}	
