using System.Text.RegularExpressions;
using Utils;

3 1 2 9 8 6 7
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

// List TO Array

int[] array = numbers.ToArray();

// 使用冒泡排序

for(int i = 0; i < array.Length; i++){
	for(int j = 0; j < array.Length - i - 1; j++){
		if(array[j] > array[j+1])Utils.Utils.Swap(ref array[j],ref array[j+1]);
	} 
}  
Console.WriteLine("Sorted Array:");

for(int i = 0; i < array.Length; i++){
	Console.Write(array[i] + " ");
}

Console.Write("\n");



