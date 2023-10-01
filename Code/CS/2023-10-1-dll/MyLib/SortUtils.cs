using System;
using Utils;

namespace SortUtils{

	public class SortUtils{

		public void BubbleSort(int[] arr){
	
			Utils.Utils utils = new Utils.Utils();	
			for(int i = 0; i < arr.Length; i++){
				for(int j = 0; j < arr.Length - i - 1; j++){
					if(arr[j] > arr[j+1]){
						utils.Swap(ref arr[j], ref arr[j+1]);
					}
				}
			}
		}
	}
}
