import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class 파도반_수렬 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		long N_arr[] = new long[T];
		long max = 0;
		for(int i=0; i<T; i++) {
			N_arr[i] = Long.parseLong(br.readLine());
			if(N_arr[i] > max)
				max = N_arr[i];
		}
		
		long P_arr[] = new long[(int) max];
		P_arr[0] = 1;
		P_arr[1] = 1;
		P_arr[2] = 1;
		
		for(int i=3; i<max; i++)
			P_arr[i] = P_arr[i-3] + P_arr[i-2];
		
		for(int i=0; i<T; i++)
			System.out.println(P_arr[(int) (N_arr[i] - 1)]);
	}
}
