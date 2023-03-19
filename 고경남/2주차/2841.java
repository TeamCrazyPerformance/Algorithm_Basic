import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Stack;
import java.util.StringTokenizer;

public class 외계인의_기타_연주 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		
		st = new StringTokenizer(br.readLine());
		
		int N = Integer.parseInt(st.nextToken());
		int P = Integer.parseInt(st.nextToken());   //딱히 필요없음
		
		ArrayList<Integer>[] list = new ArrayList[N];  //ArrayList<Integer> 배열 생성
		for(int i=0; i<N; i++) {
			list[i] = new ArrayList<Integer>();
		}
		
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			int line = Integer.parseInt(st.nextToken()); //줄번호 입력
			int fret = Integer.parseInt(st.nextToken()); //음번호 입력
			list[line].add(fret);  //줄번호에 맞는 음번호 순차적으로 입력
		}
		
		int answer = 0; //정답 변수 선언
		Stack<Integer> stack = new Stack<>();
		
		for(int i=0; i<N; i++) {
			if(list[i].size() == 0)  //i번째 줄에 쳐야할 음이 없으면 다음 줄로 이동
				continue;
      
			for(int j=0; j<list[i].size(); j++) {  
				int tmp = list[i].get(j);
				if(stack.isEmpty() || stack.peek() < tmp) { //스택이 비어있거나 현재 누르는 프렛보다 더 높은 음일경우
					answer++;
					stack.push(tmp);
				}
				else if(stack.peek() == tmp) {
					continue;
				}
				else {
					while(!stack.isEmpty() && stack.peek() > tmp) {
						answer++;
						stack.pop();
					}
					if(!stack.isEmpty() && stack.peek() == tmp)
						continue;
					answer++;
					stack.push(tmp);
				}
			}
      
			stack.clear();
		}
		System.out.println(answer);
	}
}
