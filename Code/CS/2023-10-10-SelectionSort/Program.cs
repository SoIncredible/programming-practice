using System.Text.RegularExpressions;

public class Program{

	public static void Main(string[] args){
		Console.WriteLine("Input UnSorted Array");

		string? input = Console.ReadLine();
		if(input == null){
			return;
		}

		Regex regex = new Regex(@"\d+");
		MatchCollection matches = regex.Matches(input);
		
		List<int> unSort = new List<int>();

		foreach(Match match in matches){
			if(int.TryParse(match.Value, out int number)){
				unSort.Add(number);
			}
		}

		int[] arr = unSort.ToArray();

		SelectionSort(arr);
		Console.WriteLine("Sorted Array:");
		for(int i = 0; i < arr.Length; i++){
			Console.Write(arr[i] + " ");
		}
		Console.Write("\n");
	}

	private static void SelectionSort(int[] arr){
		
		for(int i = 0; i < arr.Length; i++){
			int tempIndex = i;
			for(int j = i + 1; j < arr.Length; j++){
				if(arr[tempIndex] > arr[j]){
					tempIndex = j;
				}
			}
			Swap(ref arr[tempIndex], ref arr[i]);
		}
	}
	
	private static void Swap(ref int x, ref int y){
		int temp = x;
		x = y;
		y = temp;
	}

}
