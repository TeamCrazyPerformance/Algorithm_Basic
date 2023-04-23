import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 주유소 {

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;	
		
		int N = Integer.parseInt(br.readLine());
		int distance_arr[] = new int[N-1];
		int price_arr[] = new int[N];
		
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<N-1; i++) 
			distance_arr[i] = Integer.parseInt(st.nextToken());
		
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<N; i++)
			price_arr[i] = Integer.parseInt(st.nextToken());
		
		long answer = (long)distance_arr[0] * (long)price_arr[0];
		
		int min_price = price_arr[0];
		
		for(int i=1; i<N - 1; i++) {
			if(price_arr[i] < min_price) {
				min_price = price_arr[i];
				answer += (long)distance_arr[i] * (long)min_price;
			}
			
			else {
				answer += (long)distance_arr[i] * (long)min_price;
			}
		}
		System.out.println(answer);
	}
}
