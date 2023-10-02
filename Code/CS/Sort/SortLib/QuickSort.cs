using System;
using Utils;
namespace Sort{

	public partial class Sort{
		public static void QuickSort(int[] arr){
			
			InnerQuickSort(arr, 0, arr.Length - 1); 	

		}

		private static void InnerQuickSort(int[] arr, int begin, int end){
			if(begin >= end) return;

			int pivot = begin;
			int cur = begin;

			while(cur <= end){
				if(arr[begin] > arr[cur])pivot++;
				cur++;
			}

			Utils.Utils.Swap(ref arr[begin], ref arr[pivot]);

			int begin1 = begin ;
			int begin2 = pivot + 1 ;
			int end1 = pivot - 1 ;
			int end2 = end ;

			InnerQuickSort(arr, begin1, end1);
			InnerQuickSort(arr, begin2, end2);
		}
	}
	


}
