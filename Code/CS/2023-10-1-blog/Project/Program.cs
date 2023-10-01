using System.Text.RegularExpressions;
using Utils;
using SortUtils;

public class Program{
  static void Main(string[] args){
    
    Console.WriteLine("Input Random Numbers:");
    
    string? input = Console.ReadLine();
    
    if(input == null){
      Console.WriteLine("Input Nums Null!");
      return;
    }
    
    Regex regex = new Regex(@"\d+");
    
    MatchCollection matches = regex.Matches(input);
      
    List<int> randomNums = new List<int>();
    
    foreach(Match match in matches){
      if(int.TryParse(match.Value,out int number)){
        randomNums.Add(number);
      }
    }
    
    int[] arr = randomNums.ToArray();
    
    SortUtils.SortUtils.BubbleSort(arr);
    Utils.Utils.PrintArr(arr);
  }
}
