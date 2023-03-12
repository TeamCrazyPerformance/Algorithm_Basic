import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class 이차원_배열의_합 {

	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		StringTokenizer st = null;
		
		st = new StringTokenizer(br.readLine());
		
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		
		int NM_arr[][] = new int[N][M];
		for(int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j = 0; j < M; j++) 
				NM_arr[i][j] = Integer.parseInt(st.nextToken());
		}
		
		int K = Integer.parseInt(br.readLine());
		int K_arr[][] = new int[K][4];
		
		for(int i = 0; i < K; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j = 0; j < 4; j++) 
				K_arr[i][j] = Integer.parseInt(st.nextToken());
		}
		
		for(int l = 0; l < K; l++) {
			int i = K_arr[l][0];
			int j = K_arr[l][1];
			int x = K_arr[l][2];
			int y = K_arr[l][3];
			int sum = 0;
			int tmp = j;
			
			for(; i <= x; i++) {
				for(; j <= y; j++)
					sum += NM_arr[i-1][j-1];
				j = tmp;
			}
			bw.write(String.valueOf(sum) + "\n");
		}
		bw.flush();
		bw.close();
		br.close();
  }
}
