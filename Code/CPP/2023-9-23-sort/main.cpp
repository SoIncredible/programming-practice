#include<iostream>
#include<vector>
#include"head.h"
using namespace std;

int main(){
	cout << "Input numbers: (press x and then press enter to end input)" << endl;

	int value = 0;

	vector<int> ivect;
	while(cin >> value){
		ivect.push_back(value);
	}
	int array[ivect.size()];

	for(int i = 0; i < ivect.size(); i++){
		array[i] = ivect[i];
	}


	int arrayLength = sizeof(array) / sizeof(array[0]);

	for(int i = 0; i < arrayLength; i++){
		for(int j = 0; j < arrayLength - i - 1; j++){
			if(array[j] > array[j+1]) Swap(array[j],array[j + 1]);
		}
	}


	cout << "Sorted Array:" << endl;
	for(int i : array){
		cout << i << " ";
	}
	cout << "\n";

	return 0;
}

