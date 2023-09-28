#include<dlfcn.h>
#include<iostream>
using namespace std;
int main(){

	void *handle = dlopen("./Utils.dylib", RTLD_LAZY);
	if(handle == nullptr){
		cout << "Load DLL Fail!" << endl;
		return 1;
	}

	typedef void (*SayHello)();
	SayHello sayHello = reinterpret_cast<SayHello>(dlsym(handle,"SayHello"));

	if(sayHello == nullptr){
		cout << "Find SayHello Func Fail!" << endl;
		return 1;
	}

	
	sayHello();

	dlclose(handle);
	
	return 0;
}
