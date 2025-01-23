#include<iostream>
#include<dlfcn.h>
using namespace std;
typedef void (*SayHello)();

int main(){
	void *handle = dlopen("./Utils.dylib",RTLD_LAZY);
	if(handle == nullptr){
		cout << " Load DLL Fail" << endl;
		return 1;
	}

	SayHello sayHello = reinterpret_cast<SayHello>(dlsym(handle,"SayHello"));

	if(sayHello == nullptr){
		cout << " Function Load Fail " << endl;
		return 1;
	}

	sayHello();

	dlclose(handle);

	return 0;
}
