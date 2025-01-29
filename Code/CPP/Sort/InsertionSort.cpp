#include <iostream>
using namespace std;

void InsertionSort(int *arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        int preIndex = i - 1;
        int current = arr[i];
        // 从
        while (preIndex >= 0 && arr[preIndex] > current)
        {
            arr[preIndex + 1] = arr[preIndex];
            preIndex--;
        }
        arr[preIndex + 1] = current;
    }
}

int main()
{
    int arr[10] = {26, 99, 10, 77, 55, 89, 44, 32, 17, 18};
    InsertionSort(arr, 10);

    for (int i = 0; i < 10; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}