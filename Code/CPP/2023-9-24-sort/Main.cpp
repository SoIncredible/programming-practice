#include<iostream>
#include"Head.h"
#include<vector>
using namespace std;
int main(){
	cout << "Input Random Numbers:(press x and then press enter to end input)" << endl;

	int inputNumber;
	vector<int> numberVec;
	while(cin >> inputNumber){
		numberVec.push_back(inputNumber);
	}

	int array[numberVec.size()];
	cout << "vector size is: " << numberVec.size() << endl;
	for(int i = 0; i < numberVec.size();i++){
		array[i] = numberVec[i];
	}
	
	int length = GetArrayLength(array);

	cout << "The Length in Main is: " << length << endl;

	BubbleSort(array,numberVec.size());

	PrintArray(array,numberVec.size());

	return 0;
}
