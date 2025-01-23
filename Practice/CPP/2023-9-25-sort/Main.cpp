#include<iostream>
#include<vector>
#include"Head.h"

using namespace std;

int main(){
	
	cout << "Input Unsorted Array: (Press X and then Press Enter to End Input" << endl;

	int inputElem;
	vector<int> inputVec;
	while(cin >> inputElem){
		inputVec.push_back(inputElem);
	}
	
	int array[inputVec.size()];

	for(int i = 0; i < inputVec.size(); i++){
		array[i] = inputVec[i];
	}
	
	BubbleSort(array, inputVec.size());
	PrintArray(array, inputVec.size());
	
	return 0;
}
