using System.Text.RegularExpressions;

Console.WriteLine("input numbers:");
string? input = Console.ReadLine();
if(input == null){
	Console.WriteLine("input string is null!");
	return;
}
Regex regex = new Regex(@"\d+");
MatchCollection matches = regex.Matches(input);
List<int> numbers = new List<int>();
foreach(Match match in matches){
	int number;
	if(int.TryParse(match.Value, out number)){
		numbers.Add(number);
	}
}

Console.WriteLine("input numbers:");
foreach(int number in numbers){
	Console.Write(number + " ");
}
Console.WriteLine();
Console.Write("Hello");
