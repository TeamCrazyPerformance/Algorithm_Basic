import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	static int stack[] = new int[100000];
	static int point = -1;
	
	public static void push(int num) {
		stack[++point] = num;	
	}
	
	public static int pop() {
		if(point < 0) {
			return -1;
		}
		return stack[point--];
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int n = Integer.parseInt(br.readLine());
		int current_num = 1;  //1~n까지 오름차순
		int idx = 0;          //입력 배열의 인덱스
		int n_arr[] = new int[n]; //입력 배열
		for(int i=0; i<n; i++) {
			n_arr[i] = Integer.parseInt(br.readLine());
		}
		
		while(current_num <= n) {
			if(current_num == n && point == -1) {  //스택에 들어갈 숫자가 n과 같고 다음에 더 이상 들어갈 숫자가 없다면, 1~n까지 오름차순으로 입력된 경우
				sb.append("+\n");
				sb.append("-");
				System.out.println(sb);
				br.close();
				System.exit(0);
			}
			if(current_num == n_arr[idx]) {   //push와 pop을 둘 다 해야하는경우
				sb.append("+\n");
				sb.append("-\n");
				push(current_num);
				pop();
				current_num++;
				idx++;	
			}
			else if(current_num > n_arr[idx]) {  
				sb.append("-\n");
				int popNum = pop();
				if(popNum != n_arr[idx]) {
					System.out.println("NO");
					br.close();
					System.exit(0);
				}
				idx++;
			}
			else {
				sb.append("+\n");
				push(current_num);
				current_num++;
			}
		}
		
		while(idx < n) { //n_arr에 남은 숫자들은 내림차순이어야 한다
			if(idx == n-1) {
				sb.append("-");
				break;
			}
			if(n_arr[idx] < n_arr[idx+1]) {
				System.out.println("NO");
				br.close();
				System.exit(0);
			}
			else {
				sb.append("-\n");
				idx++;
			}
		}
		System.out.println(sb);
		br.close();
	}
}
