#include<iostream>
#include<vector>
#include<dlfcn.h>

using namespace std;

typedef void (*QuickSort)(int *, int);
typedef void (*PrintArr)(int *, int);

int main(){

	void *handle = dlopen("SortLib.dylib",RTLD_LAZY);

	if(handle == nullptr){
		cout << "Load DLL Fail!" << endl;
		return 1;
	}

	QuickSort quickSort = reinterpret_cast<QuickSort>(dlsym(handle,"QuickSort"));
	PrintArr printArr = reinterpret_cast<PrintArr>(dlsym(handle,"PrintArr"));

	if(quickSort == nullptr){
		cout << "Load QuickSort Func Fail" << endl;
		return 1;
	}

	if(printArr == nullptr){
		cout << "Load PrintArr Func Fail" << endl;
		return 1;
	}

	cout << "Input Random Numbers:(Press X and Enter to End Input" << endl;

	int number = 0;
	vector<int> randomNums;
	while(cin >> number){
		randomNums.push_back(number);
	}

	int size = randomNums.size();
	int arr[size];

	for(int i = 0; i < size; i++){
		arr[i] = randomNums[i];
	}

	quickSort(arr,size);
	printArr(arr,size);
	
	return 0;
}

