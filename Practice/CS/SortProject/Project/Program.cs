using System.Text.RegularExpressions;
using SortLib;

class Program{

	static void Main(string[] args){
		
		Console.WriteLine("Input UnSorted Array:");
		string? input = Console.ReadLine();
		if(input == null){
			Console.WriteLine("The Array is NULL!");
			return;
		}

		Regex regex = new Regex(@"\d+");
		MatchCollection matches = regex.Matches(input);

		List<int> unSortedArr = new List<int>();
		foreach(Match match in matches){
			if(int.TryParse(match.Value,out int number)){
				unSortedArr.Add(number);
			}
		}

		int[] arr = unSortedArr.ToArray();
		SortLib.Utils.Sort(arr);
	}

}
