#include<iostream>
#include"Head.h"
#include<vector>

using namespace std;

int main(){

	cout << "Input UnSorted Array:" << endl;

	int number = 0;
	vector<int> unSort;

	while(cin >> number){
		unSort.push_back(number);
	}
	int size = unSort.size();

	int arr[size];
	for(int i = 0; i < size; i++){
		arr[i] = unSort[i];
	}

	SelectionSort(arr, size);
	PrintArr(arr, size);
	return 0;
}
