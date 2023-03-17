import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class 스택 {
	
	static int stack[] = new int[10000];
	static int point = -1;
	static int top = 0;
	
	public static void push(int num) {
		stack[++point] = num;
	}
	
	public static int pop() {
		if(point < 0) {
			return -1;
		}
		return stack[point--];
	}
	
	public static int top() {
		if(point == -1)
			return -1;
		return stack[point];
	}
	
	public static int empty() {
		if(point >= 0)
			return 0;
		else 
			return 1;
	}

	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		StringTokenizer st = null;
		
		int N = Integer.parseInt(br.readLine());
		
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			String method = st.nextToken();
			if(st.hasMoreElements()) {
				int num = Integer.parseInt(st.nextToken());
				push(num);
			}
			
			switch (method) {
				case "pop" :
					bw.write(String.valueOf(pop()) + "\n");
					break;
				case "top" :
					bw.write(String.valueOf(top()) + "\n");
					break;
				case "empty" :
					bw.write(String.valueOf(empty()) + "\n");
					break;
				case "size" :
					bw.write(String.valueOf(point + 1) + "\n");
					break;
			}
		}
		bw.flush();
		bw.close();
		br.close();		
	}
}
