import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class 요세푸스_문제 {

	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());
		
		Queue<Integer> queue = new LinkedList<>();
		for(int i = 1; i < N+1; i++) {
			queue.add(i);
		}
		
		bw.write("<");
		int count = 1;
		while(queue.size() >= 2) {
			if(count == K) {
				bw.write(String.valueOf(queue.poll()) + ", ");
				count = 1;
			}
			else {
				int num = queue.poll();
				queue.add(num);
				count++;
			}
		}
		bw.write(String.valueOf(queue.poll()) + ">");
		
		bw.flush();
		bw.close();
		br.close();
	}
}
