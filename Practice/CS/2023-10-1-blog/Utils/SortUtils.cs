using System;
using Utils;
namespace SortUtils{
  public class SortUtils{
    public static void BubbleSort(int[] arr){
      for(int i = 0; i < arr.Length; i++){
        for(int j = 0; j < arr.Length - i - 1; j++){
          if(arr[j] > arr[j+1]) Utils.Utils.Swap(ref arr[j], ref arr[j+1]);
        }
      }
    }
  }
}
