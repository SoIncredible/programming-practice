using System.Text.RegularExpressions;

public class Program{

	public static void Main(string[] args){

		Console.WriteLine("Input Unsorted Array:");

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

		QuickSort(arr);

		Console.WriteLine("Sorted Array");
		for(int i = 0; i < arr.Length; i++){
			Console.Write(arr[i] + " ");
		}
		Console.Write("\n");
		
	}

	private static void QuickSort(int[] arr){
		InnerQuickSort(arr, 0, arr.Length - 1);
	}

	private static void InnerQuickSort(int[] arr, int begin, int end){
		
		if(begin >= end) return;
		int pivot = begin;
		int cur = begin;

		while(cur <= end){
			if(arr[cur] < arr[begin]){
				pivot++;
			}
			cur++;
		}
		
		int temp = arr[begin];
		arr[begin] = arr[pivot];
		arr[pivot] = temp;

		int begin1 = begin;
		int begin2 = pivot + 1;
		int end1 = pivot - 1;
		int end2 = end;

		InnerQuickSort(arr, begin1, end1);
		InnerQuickSort(arr, begin2, end2);
	}

}
