import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class 좋은_친구 {

	public static void main(String[] args) throws IOException{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		
		st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());
		
		Queue<Integer>[] queue = new Queue[19];
		
		for(int i = 0; i<19; i++)
			queue[i] = new LinkedList<>();
		
		long answer = 0;
		
		for(int i=1; i<=N; i++) {
			int len = br.readLine().length();
			while(queue[len - 2].size() > 0 && i - queue[len - 2].peek() > K) {
				queue[len - 2].poll();
			}
			
			answer += queue[len - 2].size();
			queue[len - 2].add(i);
		}
		
		System.out.println(answer);
	}
}
