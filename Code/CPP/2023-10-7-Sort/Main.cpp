#include<iostream>
#include"Head.h"
#include<vector>
using namespace std;

int main(){
	
	cout << "Input Unsorted Numbers:" << endl;
	int number = 0;
	vector<int> unSortedArr;
	while(cin >> number){
		unSortedArr.push_back(number);
	}
	int size = unSortedArr.size();
	int arr[size];

	for(int i = 0; i < size; i++){
		arr[i] = unSortedArr[i];
	}

	QuickSort(arr, size);
	PrintArr(arr, size);

	return 0;
}
