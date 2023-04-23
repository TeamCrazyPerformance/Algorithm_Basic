import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 동전0 {

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());
		int coin_arr[] = new int[N];
		
		for(int i=0; i<N; i++)
			coin_arr[i] = Integer.parseInt(br.readLine());
		
		int answer = 0;
		int idx = N - 1;
		
		while(K != 0) {
			if(coin_arr[idx] <= K) {
				K -= coin_arr[idx];
				answer++;
			}
			else {
				idx--;
			}
		}
		
		System.out.println(answer);
	}
}
