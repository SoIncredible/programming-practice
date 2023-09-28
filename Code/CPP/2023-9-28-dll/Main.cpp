#include<iostream>
#include<vector>
#include<dlfcn.h>

using namespace std;

typedef void (*BubbleSort)(int*, int);
typedef void (*PrintArr)(int*, int);

int main(){

	void *handle = dlopen("Utils.dylib",RTLD_LAZY);	

	if(handle == nullptr){
		cout << "Load DLL Fail!" << endl;
		return 1;
	}

	BubbleSort bubbleSort = reinterpret_cast<BubbleSort>(dlsym(handle,"BubbleSort"));
	PrintArr printArr = reinterpret_cast<PrintArr>(dlsym(handle,"PrintArr"));

	if(bubbleSort == nullptr){
		cout <<"Load BubbleSortFunc Fail!" << endl;
		return 1;
	}

	if(printArr == nullptr){
		cout << "Load PrintArrFunc Fail!" << endl;
		return 1;
	}

	cout << "Input Random Numbers:" << endl;
	vector<int> randomNum;
	int number;
	while(cin >> number){
		randomNum.push_back(number);
	}

	int arr[randomNum.size()];

	for(int i = 0; i < randomNum.size(); i++){
		arr[i] = randomNum[i];
	}

	bubbleSort(arr, randomNum.size());
	printArr(arr,randomNum.size());

	dlclose(handle);
	return 0;
}
