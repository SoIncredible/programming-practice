#include<iostream>
#include"Head.h"
#include<vector>
using namespace std;

int main(){
    cout << "Input Sorted Array:" << endl;
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

void PrintArr(int* arr, int size){
    cout << "Sorted Array:" << endl;
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void MergeSort(int* arr, int size){
    for(int length = 1; length < size; length *= 2){
        for(int index = 0; index < size - length; index += (2 * length)){
            Merge(arr, index, index + length - 1, (index + (2 * length) > size? size - 1 : index + (2 * length) - 1), size);
        }
    }
}

void Merge(int* arr, int begin, int mid, int end, int size){
    int* temp = new int[size];
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