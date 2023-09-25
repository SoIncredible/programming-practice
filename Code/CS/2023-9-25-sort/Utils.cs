namespace Utils{

	public static class Utils{
		public static void Swap(ref int x, ref int y){
			int temp = x;
			x = y;
			y = temp;
		}
	
		public static void PrintArray(int[] array){
			Console.WriteLine($"Sorted Array(array length is: {array.Length}):");
			for(int i = 0; i < array.Length; i++){
				Console.Write($"{array[i]} ");
			}
			Console.Write("\n");
		}
	}
}
