import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class 알고리즘의_수행_시간6 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int n = Integer.parseInt(br.readLine());
		long sum = 0;
		long preSum = 0;
		for(int i = 1; i <= n-2; i++) {
			sum += (preSum + i);
			preSum += i;
		}
		bw.write(String.valueOf(sum) + "\n");
		bw.write("3");
		
		bw.flush();
		bw.close();
		br.close();
	}
}
