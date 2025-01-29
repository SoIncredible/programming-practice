#include <iostream>
using namespace std;

// 遍历整个数组,每次遍历的时候从未排序的数组里面遍历出最小的值,将其与未排序部分的第一个元素交换,重复该操作直到未排序数组长度为0

void Swap(int *arr, int x, int y)
{
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

void SelectionSort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int tempMinIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            // 找到最小的
            if (arr[tempMinIndex] > arr[j])
            {
                tempMinIndex = j;
            }
        }
        Swap(arr, tempMinIndex, i);
    }
}

int main()
{
    int arr[10] = {26, 99, 10, 77, 55, 89, 44, 32, 17, 18};
    SelectionSort(arr, 10);

    for (int i = 0; i < 10; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}