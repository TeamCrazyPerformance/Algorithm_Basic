import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 큐 {
	
	static int front = 0;
	static int back = 0;
	static int queue[] = new int[10000];
	
	public static void push(int num) {
		queue[back++] = num;
	}
	
	public static int pop() {
		if(back == front)
			return -1;
		return queue[front++];
	}
	
	public static int size() {
		return back - front;
	}
	
	public static int empty() {
		if(back - front == 0)
			return 1;
		return 0;
	}
	
	public static int front() {
		if(back - front == 0)
			return -1;
		return queue[front];
	}
	
	public static int back() {
		if(back - front == 0)
			return -1;
		return queue[back - 1];
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = null;
		
		int N = Integer.parseInt(br.readLine());
		
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			String method = st.nextToken();  //명령어
			if(st.hasMoreTokens()) {         //push의 경우 변수 하나 더 선언
				int num = Integer.parseInt(st.nextToken());
				push(num);
			}
			switch(method) {
				case "pop":
					sb.append(pop() + "\n");
					break;
				case "size":
					sb.append(size() + "\n");
					break;
				case "empty":
					sb.append(empty() + "\n");
					break;
				case "front":
					sb.append(front() + "\n");
					break;
				case "back":
					sb.append(back() + "\n");
					break;
			}
		}
		System.out.print(sb);
		br.close();
	}
}
