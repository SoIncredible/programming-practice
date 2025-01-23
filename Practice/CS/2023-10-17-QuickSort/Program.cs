using System.Text.RegularExpressions;

public class Program{

	public static void Main(string[] args){

		Console.WriteLine("Input UnSorted Array");
		
		string? input = Console.ReadLine();
	
		if(input == null){
			return;
		}

		List<int> unSort = new List<int>();
		Regex regex = new Regex(@"\d+");
		MatchCollection matches = regex.Matches(input);

		foreach(Match match in matches){
			if(int.TryParse(match.Value,out int number)){
				unSort.Add(number);
			}
		}

		int[] arr = unSort.ToArray();

		QuickSort(arr);

		Console.WriteLine("Sorted Array:");
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
		
		int cur = begin;
		int pivot = begin;

		while(cur <= end){
			if(arr[cur] < arr[begin]){
				++pivot;
			}
			++cur;
		}

		Swap(ref arr[begin], ref arr[pivot]);

		int begin1 = begin;
		int begin2 = pivot + 1;
		int end1 = pivot - 1;
		int end2 = end;
		InnerQuickSort(arr, begin1, end1);
		InnerQuickSort(arr, begin2, end2);
	}	

	private static void Swap(ref int x, ref int y){

		int temp = x;
		x = y;
		y = temp;
	}

}
