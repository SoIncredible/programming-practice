using System.Text.RegularExpressions;
using Utils;
using SortUtils;

Console.WriteLine("input numbers:");
string? input = Console.ReadLine();
if(input == null){
	Console.WriteLine("input number is null!");
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


int[] array = numbers.ToArray();
SortUtils.SortUtils.BubbleSort(array);

Utils.Utils.PrintArray(array);
