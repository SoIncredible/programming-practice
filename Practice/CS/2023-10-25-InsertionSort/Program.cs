using System;
using System.Text.RegularExpressions;

public class Program{


	public static void Main(string[] args){
		Console.WriteLine("Input UnSorted Array:");

		string? input = Console.ReadLine();
		if(input == null) return;

		List<int> unSort = new List<int>();
		Regex regex = new Regex(@"\d+");
		MatchCollection matches = regex.Matches(input);

		foreach(Match match in matches){
			if(int.TryParse(match.Value, out int number)){
				unSort.Add(number);
			}
		}

		int[] arr = unSort.ToArray();
		InsertionSort(arr);
		PrintArr(arr);
	}

	public static void InsertionSort(int[] arr){
		for(int i = 0; i < arr.Length; i++){
			int curIndex = i - 1;
			while(curIndex >= 0){
				if(arr[curIndex] > arr[curIndex + 1]){
					Swap(ref arr[curIndex], ref arr[curIndex + 1]);
					--curIndex;
					continue;
				}
				break;
			}
		}
	}

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
