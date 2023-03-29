import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 기타_레슨 {

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		
		st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		
		st = new StringTokenizer(br.readLine());
		int max = 0;
		int sum = 0;
		int N_arr[] = new int[N];
		for(int i=0; i<N; i++) {
			N_arr[i] = Integer.parseInt(st.nextToken());
			if(N_arr[i] > max)
				max = N_arr[i];
			sum += N_arr[i];
		}
		
		int front = max;
		int rear = sum;
		while(front <= rear) {
			int middle = (front+rear)/2;			
			sum = 0;
			int count = 0;
			for(int i=0; i<N; i++) {
				if(sum + N_arr[i] > middle) {
					sum = 0;
					count++;
				}
				sum += N_arr[i];
			}
			if(count >= M) { //블루레이 크기를 늘려야 함
				front = middle + 1;
			} else {
				rear = middle - 1;
			}
		}
		System.out.println(front);
	}
}
