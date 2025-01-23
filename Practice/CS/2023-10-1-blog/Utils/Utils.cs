using System;
namespace Utils{
  public class Utils{
    public static void Swap(ref int x, ref int y){
      int temp = x;
      x = y;
      y = temp;
    }
    
    public static void PrintArr(int[] arr){
      Console.WriteLine("Sorted Array:");
      for(int i = 0; i < arr.Length; i++){
        Console.Write($"{arr[i]} ");
      }
      Console.Write("\n");
    }
  }
}
