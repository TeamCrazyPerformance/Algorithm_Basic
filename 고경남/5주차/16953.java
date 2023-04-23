import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class AtoB_16953 {
	
	static boolean check = false; 

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		st = new StringTokenizer(br.readLine());
		
		long A = Integer.parseInt(st.nextToken());
		long B = Integer.parseInt(st.nextToken());
		
		int answer = 0;
		
		BFS(A, B, answer);
		if(!check)
			System.out.println(-1);
	}
	
	public static void BFS(long A, long B, int answer) {
		if(check)
			return;
		if(A == B) {
			System.out.println(answer + 1);
			check = true;
			return;
		}
		if(A > B)
			return;
		
		answer++;
		
		BFS(A*2, B, answer);
		BFS(A*10 + 1, B, answer);
	}
}
