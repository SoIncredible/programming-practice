using System.Text.RegularExpressions;

class Program{

	static void Main(string[] args){
		Console.WriteLine("Input UnSorted Array");
		string? input = Console.ReadLine();

		if(input == null) return;

		Regex regex = new Regex(@"\d+");
		MatchCollection matches = regex.Matches(input);
		
		List<int> unSort = new List<int>();
		foreach(Match match in matches){
			if(int.TryParse(match.Value,out int number)){
				unSort.Add(number);
			}
		}

		int[] arr = unSort.ToArray();
		for(int i = 0; i < arr.Length; i++){
			int min = i;
			for(int j = i + 1; j < arr.Length; j++){
				if(arr[min] > arr[j]){
					min = j;
				}
			}
			int temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}

		Console.WriteLine("Sorted Array:");
		for(int i = 0; i < arr.Length; i++){
			Console.Write(arr[i] + " ");
		}
		Console.Write("\n");
	}

}
