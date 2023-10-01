namespace Utils
{
	public class Utils
	{	
		public void Swap(ref int x, ref int y){
			int temp = x;
			x = y;
			y = temp;
		} 

		public void PrintArr(int[] arr){
			Console.WriteLine("Sorted Array:");
			for(int i = 0; i < arr.Length; i++){
				Console.WriteLine(arr[i] + " " );
			}
			Console.Write("\n");
		}
	}
}		
