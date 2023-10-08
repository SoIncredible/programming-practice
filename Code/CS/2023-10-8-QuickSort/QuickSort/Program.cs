using System.Text.RegularExpressions;
using QuickSort;
using SortUtils;

namespace Program{


	public class Program{

		public static void Main(string[] args){
			
			Console.WriteLine("Input UnSorted Array:");

			string? input = Console.ReadLine();

			if(input == null){
				return;
			}

			Regex regex = new Regex(@"\d+");
			
			MatchCollection matches = regex.Matches(input);

			List<int> unSort = new List<int>();

			foreach(Match match in matches){
				if(int.TryParse(match.Value,out int number)){
					unSort.Add(number);
				}
			}

			int[] arr = unSort.ToArray();
			QuickSort.Sort.QuickSort(arr);
			SortUtils.Utils.PrintArr(arr);
		}
	}


}
