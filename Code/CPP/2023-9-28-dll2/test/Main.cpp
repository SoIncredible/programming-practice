#include<iostream>
#include<dlfcn.h>
using namespace std;

typedef void (*Test1)();
typedef void (*Test2)();
int main(){
	
	void *handle = dlopen("Utils.dylib",RTLD_LAZY);

	if(handle == nullptr){
		cout << " Load DLL Fail! " << endl;
		return 1;
	}

	Test1 test1 = reinterpret_cast<Test1>(dlsym(handle,"Test1"));
	Test2 test2 = reinterpret_cast<Test2>(dlsym(handle,"Test2"));

	if(test1 == nullptr){
		cout << " Test1 Load Fail " << endl;
		return 1;
	}

	if(test2 == nullptr){
		cout << " Test2 Load Fail " << endl;
		return 1;
	}


	test1();
	test2();

	dlclose(handle);
	return 0;
}
