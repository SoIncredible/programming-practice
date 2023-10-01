#include"Head.h"
#include<iostream>
using namespace std;

extern "C" void BubbleSort(int *arr, int size){
  for(int i = 0; i < size; i++){
    for(int j = 0; j < size - i - 1; j++){
      	if(arr[j] > arr[j+1]){
          Swap(arr[j], arr[j+1]);
        }
    }
  }
}
