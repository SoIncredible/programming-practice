using System.Text.RegularExpressions;


public class Program{

	public static void Main(string[] args){
		
		Console.WriteLine("Input UnSorted Array:");
		string? input = Console.ReadLine();
		if(input==null) return;

		Regex regex = new Regex(@"\d+");
		List<int> unSort = new List<int>();
		
		MatchCollection matches = regex.Matches(input);
		foreach(Match match in matches){
			if(int.TryParse(match.Value, out int number)){
				unSort.Add(number);
			}
		}

		int[] arr = unSort.ToArray();
		SelectionSort(arr);
		PrintArr(arr);

		
	}

	private static void SelectionSort(int[] arr){
		
		for(int i = 0; i < arr.Length; i++){
			int index = i;
			for(int j = i + 1; j < arr.Length; j++){
				if(arr[index] > arr[j]){
					index = j;
				}
			}
			Swap(ref arr[index], ref arr[i]);
		}

	}

	private static void Swap(ref int x, ref int y){
		int temp = x;
		x = y;
		y = temp;
	}

	private static void PrintArr(int[] arr){
		Console.WriteLine("Sorted Array");
		for(int i = 0; i < arr.Length; i++){
			Console.Write($"{arr[i]} ");
		}
		Console.Write("\n");
	}
}
