import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 부분수열의_합 {

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		
		int N = Integer.parseInt(br.readLine());
		int S[] = new int[N];
		
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<N; i++) 
			S[i] = Integer.parseInt(st.nextToken());
		
		for(int i=0; i<N-1; i++) {  //선택 정렬 (오름차순)
			for(int j=i+1; j<N; j++) {
				if(S[i] > S[j]) {
					int tmp = S[i];
					S[i] = S[j];
					S[j] = tmp;
				}
			}
		}
		
		//첫 번째 수부터 i-1번째 수까지 모두 더한 값+1 이하의 수가 i번째 수에 오면 계속 이어서 만들 수 있음
		int answer = 0;
		for(int i=0; i<N; i++) {
			if(answer + 1 < S[i])
				break;
			answer += S[i];
		}
		System.out.println(answer + 1);
	}
}
