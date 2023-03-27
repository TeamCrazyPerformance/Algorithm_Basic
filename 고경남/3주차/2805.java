package FirstWeek;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 나무_자르기 {

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		
		st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int height[] = new int[N];
		
		st = new StringTokenizer(br.readLine());
		int max_height = 0;
		for(int i=0; i<N; i++) {
			height[i] = Integer.parseInt(st.nextToken());
			if(height[i] > max_height)
				max_height = height[i];
		}
		
		long front = 0;
		long rear = max_height;
		long middle = (front + rear)/2;
		while(front <= rear) {
			long sum = 0;
			for(int i=0; i<N; i++) {
				if(height[i] > middle) {
					sum += height[i] - middle;
				}
			}
			if(sum == M) {  //2진탐색
				break;
			}
			else if(sum > M) {
				front = middle + 1;
			}
			else {
				rear = middle - 1;
			}
			middle = (front + rear)/2;
		}
		
		System.out.println(middle);
		br.close();
	}
}
