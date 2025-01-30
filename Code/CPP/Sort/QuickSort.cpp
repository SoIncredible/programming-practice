#include <iostream>
using namespace std;

void Swap(int *arr, int x, int y)
{
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

void InnerQuickSort(int *arr, int beginIndex, int endIndex)
{
    if (beginIndex >= endIndex)
    {
        return;
    }

    int left = beginIndex + 1;
    int right = endIndex;
    int pivotValue = arr[beginIndex]; // 选择起始位置的元素作为枢轴

    while (left <= right)
    {
        // 找到左侧第一个大于等于 pivot 的元素
        while (left <= right && arr[left] < pivotValue)
        {
            left++;
        }

        // 找到右侧第一个小于 pivot 的元素
        while (left <= right && arr[right] >= pivotValue)
        {
            right--;
        }

        // 如果左指针和右指针没有交错，交换它们
        if (left < right)
        {
            Swap(arr, left, right);
        }
    }

    int cur = beginIndex;
    int pivot = beginIndex;

    while (cur <= endIndex)
    {
        if (arr[cur] < arr[beginIndex])
            ++pivot;
        ++cur;
    }
    // 将枢轴放到正确的位置
    Swap(arr, beginIndex, pivot);

    // 递归地对左右子数组排序
    InnerQuickSort(arr, beginIndex, right - 1);
    InnerQuickSort(arr, right + 1, endIndex);
}

void QuickSort(int *arr, int size)
{
    // 选择pivot
    // 能够标记两个子序列
    InnerQuickSort(arr, 0, size - 1);
}

int main()
{
    int arr[10] = {26, 99, 10, 77, 55, 89, 44, 32, 17, 18};

    QuickSort(arr, 10);

    for (int i = 0; i < 10; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}