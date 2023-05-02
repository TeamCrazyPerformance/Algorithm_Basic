import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class 제곱수의_합 {
	
	static int answer = 1000000;
	static Integer[] arr;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		arr = new Integer[N+1];
		arr[0] = 0;
		arr[1] = 1;
		int max = 100000;
		dp(N, max);
		
		System.out.println(arr[N]);		
	}
	
	public static int dp(int N, int max) {
		for(int i=1; i<=N/2+1; i++) {
			if(i*i > N) {
				max = i-1;
				break;
			}
		}
		
		if(arr[N] == null) {
			for(int i=max; i>0; i--) {
				int tmp = dp(N - (i*i), i) + 1;
				if(arr[N] == null || tmp < arr[N])
					arr[N] = tmp;
			}
		}
		return arr[N];
	}
}
