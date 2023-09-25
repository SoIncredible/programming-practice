using System.Text.RegularExpressions;
using Utils;
using SortUtils;


Console.WriteLine("Input Numbers:");


string? input = Console.ReadLine();
if(input == null){
	Console.WriteLine("Input Number is NULL!");
	return;
}

Regex regex = new Regex(@"\d+");

MatchCollection matches = regex.Matches(input);
List<int> numberList = new List<int>();

foreach(Match match in matches){
	if(int.TryParse(match.Value, out int number)){
			numberList.Add(number);
	}
}


int[] numberArray = numberList.ToArray();

SortUtils.SortUtils.BubbleSort(numberArray);

Utils.Utils.PrintArray(numberArray);
