#include<iostream>
#include"Head.h"
#include<vector>
using namespace std;

// 编写自下而上的归并排序算法

int main(){
    cout << "Input Unsorted Array:" << endl;
    int number;
    vector<int> unsortedArr;

    while(cin >> number){
        unsortedArr.push_back(number);
    }

    int size = unsortedArr.size();
    int* arr = new int [size];

    for(int i = 0; i < size; i++){
        arr[i] = unsortedArr[i];
    }
    
    MergeSort(arr, size);
    PrintArr(arr, size);

    delete[] arr;
    return 0;
}

void MergeSort(int* arr, int size){
    for(int curSize = 1; curSize < size; curSize*=2){
        // curSize代表的是当前遍历轮数数组的长度
        // lo代表要将这一轮的所有数组全部Merge掉
        for(int lo = 0; lo < size - curSize; lo += (2*curSize)){
            Merge(arr, lo, lo + curSize - 1, (lo + 2 * curSize < size)? lo + 2 * curSize - 1 : size - 1, size);
        }
    }    
}

void Merge(int* arr, int begin, int mid, int end, int size){
    // 开辟新的内存空间
    int* temp = new int [size];
    int index;
    for(index = begin; index <= end; index++){
        temp[index] = arr[index];
    }

    int left;
    int right;

    for(index = begin, left = begin, right = mid + 1; index <= end && left <= mid && right <= end; index++){
        if(temp[left] < temp[right]){
            arr[index] = temp[left++];
        }else{
            arr[index] = temp[right++];
        }
    }

    while(left <= mid) arr[index++] = temp[left++];
    while(right <= end) arr[index++] = temp[right++];

    delete[] temp;
}

void PrintArr(int* arr, int size){
    cout << "Sorted Arr:" << endl;
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}