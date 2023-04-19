package FirstWeek;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class 수_찾기 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = null;
		
		int N = Integer.parseInt(br.readLine());
		int arr1[] = new int[N];
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<N; i++) {
			arr1[i] = Integer.parseInt(st.nextToken());
		}
		
		quickSort(arr1, 0, arr1.length - 1);
		
		int M = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<M; i++) {
			int num = Integer.parseInt(st.nextToken());
			int left = 0;
			int right = arr1.length - 1;
			int mid;
			boolean check = false;
			
			while(left <= right) { //이분탐색
				mid = (left + right) / 2;
				if(arr1[mid] < num) left = mid + 1;
				else if(arr1[mid] > num) right = mid - 1;
				else {
					check = true;
					break;
				}
			}
			if(check)
				bw.write("1\n");
			else
				bw.write("0\n");
		}
		
		bw.flush();
		bw.close();
		br.close();
	}
	
	private static void quickSort(int[] arr, int start, int end) { //pivot을 중간값으로 설정
		if(start >= end)
			return;
		
		int pivot = partition(arr, start, end);

		quickSort(arr, start, pivot);
		quickSort(arr, pivot + 1, end);
	}
	
	private static int partition(int[] arr, int start, int end) {
		int left = start - 1;
		int right = end + 1;
		int pivot = arr[(start + end) / 2];
		
		while(true) {
			do {
				left++;
			} while(arr[left] < pivot);
			
			do {
				right--;
			} while(arr[right] > pivot && left <= right);
			
			if(left >= right) {
				return right;
			}
			swap(arr, left, right);
		}
	}
	
	private static void swap(int[] arr, int i, int j) {
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}
