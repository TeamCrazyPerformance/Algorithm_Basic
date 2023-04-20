import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Z {
	
	static int visitCnt = 0;

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int r = Integer.parseInt(st.nextToken());
		int c = Integer.parseInt(st.nextToken());
		
		partition(N, r, c);
		
		System.out.println(visitCnt);
	}
	
	public static void partition(int N, int r, int c) {
		int size = (int)Math.pow(2, N-1);
		
		if(N == 1) {
			if(r == 0 && c == 1)
				visitCnt++;
			else if(r == 1 && c == 0)
				visitCnt += 2;
			else if(r == 1 && c == 1)
				visitCnt += 3;
			return;
		}
		
		if(r < size && c < size) {
			partition(N-1, r, c);
		}
		else if(r < size && c >= size) {
			visitCnt += Math.pow(2, N-1) * Math.pow(2, N-1);
			partition(N-1, r, c-size);
		}
		else if(r >= size && c < size) {
			visitCnt += Math.pow(2, N-1) * Math.pow(2, N-1) * 2;
			partition(N-1, r-size, c);
		}
		else {
			visitCnt += Math.pow(2, N-1) * Math.pow(2, N-1) * 3;
			partition(N-1, r-size, c-size);
		}
	}
}
