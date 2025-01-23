#include<iostream>
#include<vector>
// 操作dll相关头文件
#include<dlfcn.h>
using namespace std;

typedef void (*BubbleSort)(int*,int);
typedef void (*PrintArr)(int*,int);

int main(){
  
  void *handle = dlopen("Utils.dylib",RTLD_LAZY);
  
  if(handle == nullptr){
    cout << "Load DLL Fail!" << endl;
    return 1;
  }
  
  BubbleSort bubbleSort = reinterpret_cast<BubbleSort>(dlsym(handle,"BubbleSort"));
  PrintArr printArr = reinterpret_cast<PrintArr>(dlsym(handle,"PrintArr"));
  
  if(bubbleSort == nullptr){
    cout << "Load BubbleSort Func Fail!" << endl;
    return 1;
  }
  
  if(printArr == nullptr){
    cout << "Load PrintArr Func Fail!" << endl;
    return 1;
  }
  
  cout << "Input Random Numbers:(Press X and then Press Enter to End Input)" << endl;
  
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
  
  bubbleSort(arr,size);
  printArr(arr,size);
  
  dlclose(handle);
  
  return 0;
}
