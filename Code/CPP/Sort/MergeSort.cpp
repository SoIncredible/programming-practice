#include <iostream>
#include <vector>
using namespace std;

// 1. 传入一个数组, 数组长度为size
// 2. 分治, 将数组分成size个长度为1的子数组, 这些数组默认是有序的.
// 3. 合并, 将这size个长度为1的子数组合并成$\frac{size} {2} $个长度为2的子数组.注意, 如果size为奇数, 就要分成$\frac{size - 1} {2} $个长度为2的子数组和一个长度为1的子数组
// 4. 重复第2、3步操作, 直到子数组的长度变为`size`.

void MergeSort(int *arr, int size);
void Merge(int *arr, int size, int begin, int mid, int end);

void MergeSort(int *arr, int size)
{
    for (int curSize = 1; curSize < size; curSize *= 2)
    {
        // 此处对边界值的判定
        for (int index = 0; index < size - curSize; index += 2 * curSize)
        {
            Merge(arr, size, index, index + curSize, index + 2 * curSize - 1 > size - 1 ? size - 1 : index + 2 * curSize - 1);
        }
    }
}

void Merge(int *arr, int size, int begin, int mid, int end)
{
    int *temp = new int[size];
    for (int i = 0; i < size; i++)
    {
        temp[i] = arr[i];
    }

    int index = begin;
    int left = begin;
    int right = mid;

    while (left <= mid - 1 && right <= end)
    {
        // 左边大于右边
        if (temp[left] > temp[right])
        {
            arr[index++] = temp[right++];
        }
        else // 右边大于左边
        {
            arr[index++] = temp[left++];
        }
    }

    while (left <= mid - 1)
        arr[index++] = temp[left++];
    while (right <= end)
        arr[index++] = temp[right++];

    delete[] temp;
}

int main()
{
    int arr[10] = {26, 99, 10, 77, 55, 89, 44, 32, 17, 18};
    MergeSort(arr, 10);

    for (int i = 0; i < 10; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}