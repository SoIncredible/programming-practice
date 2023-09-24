using Utils;
namespace SortUtils{

	public static class SortUtils{
		public static void BubbleSort(int[] array){
			for(int i = 0; i < array.Length; i++){
				for(int j = 0; j < array.Length - i - 1; j++){
					if(array[j] > array[j+1]){
						Utils.Utils.Swap(ref array[j],ref array[j+1]);
					}
				}
			}

		}
	}
}

