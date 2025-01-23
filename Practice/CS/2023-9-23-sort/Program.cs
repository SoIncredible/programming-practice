using System.Text.RegularExpressions;
using Utils;



Console.WriteLine("Input Numbers:");


string? input = Console.ReadLine();

if(input == null){
	Console.WriteLine("input is null");
	return;
}	


Regex regex = new Regex(@"\d+");
MatchCollection matches = regex.Matches(input);

List<int> numberList = new List<int>();

foreach(Match match in matches){
	if(int.TryParse(match.Value,out int number)){
		
			numberList.Add(number);
	}			

}	


int[] numbersArray = numberList.ToArray();


for(int i = 0; i < numbersArray.Length; i++){
	Console.Write(numbersArray[i] + " ");
}
Console.Write("\n");



for(int i = 0; i < numbersArray.Length; i++){
	for(int j = 0; j < numbersArray.Length - i - 1; j++){
		if(numbersArray[j] > numbersArray[j + 1]){
			Utils.Utils.Swap(ref numbersArray[j], ref numbersArray[j+1]);
		}
	}
}



Console.WriteLine("Sorted Array:");
for(int i = 0; i < numbersArray.Length; i++){
	Console.Write(numbersArray[i]+" ");
}
Console.Write("\n");

