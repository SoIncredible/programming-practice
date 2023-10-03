#include<iostream>
#include<vector>
#include<dlfcn.h>

using namespace std;

typedef void (*Sort)(int*,int);

int main(){

	void *handle = dlopen("SortLib.dylib",RTLD_LAZY);
	if(handle == nullptr){
		cout << "Load SortLib DLL Fail!" << endl;
		return 1;
	}

	Sort sort = reinterpret_cast<Sort>(dlsym(handle,"Sort"));
	if(sort == nullptr){
		cout << "Load Sort Func Fail!" << endl;
		return 1;
	}

	cout << "Input UnSorted Array (Press X and Then Press Enter To End Input):" << endl;
	
	int number = 0;
	vector<int> unsortedArr;

	while(cin >> number){
		unsortedArr.push_back(number);
	}

	int size = unsortedArr.size();
	int arr[size];

	for(int i = 0; i < size; i++){
		arr[i] = unsortedArr[i];
	}
	
	sort(arr, size);
	
	dlclose(handle);

	return 0;
}
