namespace Utils{

	public static class Utils{
	

		public static void Swap(ref int x, ref int y){
			int temp = x;
			x = y;
			y = temp;
		}


		public static void PrintArray(int[] array){
			Console.WriteLine("Sorted Array:");
			foreach(int item in array){
				Console.Write($"{item} ");
			}
			Console.Write("\n");
		}

	}
}

