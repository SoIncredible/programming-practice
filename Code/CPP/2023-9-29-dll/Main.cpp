#include<iostream>
#include<vector>
#include<dlfcn.h>

using namespace std;


typedef void (*BubbleSort)(int *, int);
typedef void (*PrintArr)(int *, int);
int main(){

	void *handle = dlopen("Utils.dylib",RTLD_LAZY);

	if(handle == nullptr){
		cout << "Load DLL Fail" << endl;
		return 1;
	}

	BubbleSort bubbleSort = reinterpret_cast<BubbleSort>(dlsym(handle,"BubbleSort"));
	PrintArr printArr = reinterpret_cast<PrintArr>(dlsym(handle,"PrintArr"));
	
	if(bubbleSort == nullptr){
		cout << "Load BubbleSort Func Fail" << endl;
		return 1;
	}

	if(printArr == nullptr){
		cout << "Load PrintArr Func Fail" << endl;
		return 1;
	}

	cout << "Input Random Numbers:(Press X and then Press Enter to end Input)" << endl;

	int number = 0;
	vector<int> randomNums;

	while(cin >> number){
		randomNums.push_back(number);
	}

	int arr[randomNums.size()];

	for(int i = 0; i < randomNums.size(); i++){
		arr[i] = randomNums[i];
	}
		
	bubbleSort(arr,randomNums.size());

	printArr(arr,randomNums.size());

	return 0;
}	
