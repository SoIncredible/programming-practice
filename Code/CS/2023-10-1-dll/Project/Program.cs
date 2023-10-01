using System;
using System.Text.RegularExpressions;
using SortUtils;
using Utils;
class Program{

	static void Main(string[] args){
	
		Console.WriteLine("Input Random Numbers:");
		string? input = Console.ReadLine();
	
		if(input == null){
			Console.WriteLine("Input Number is Null!");
			return;
		}

		Regex regex = new Regex(@"\d+");

		MatchCollection matches = regex.Matches(input);

		List<int> numbers = new List<int>();

		foreach(Match match in matches){
			if(int.TryParse(match.Value, out int number)){
				numbers.Add(number);
			}
		}

		int[] arry = numbers.ToArray();
		SortUtils.SortUtils sortUtils = new SortUtils.SortUtils();
		sortUtils.BubbleSort(arry);

		Utils.Utils utils = new Utils.Utils();
		utils.PrintArr(arry);

	}
}
