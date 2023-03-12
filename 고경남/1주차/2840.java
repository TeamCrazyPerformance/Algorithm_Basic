import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class 행운의_바퀴 {

	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());
		
		String arr[] = new String[N];
		
		st = new StringTokenizer(br.readLine());
		st.nextToken();
		arr[0] = st.nextToken(); //첫 번째 알파벳 배열에 추가
		
		int lastIdx = 0;
		int idx = 0;
		String alphabet;
		for(int i = 1; i < K; i++) {
			st = new StringTokenizer(br.readLine());
			idx += Integer.parseInt(st.nextToken());
			
			while(idx >= N)
				idx -= N;
			
			alphabet = st.nextToken();
			
			if(arr[idx] != null && !arr[idx].equals(alphabet)) { //같은 자리에 알파벳이 다르다면 ! 출력
				bw.write("!");
				bw.flush();
				bw.close();
				br.close();
				System.exit(0);
			}
			else 
				arr[idx] = alphabet;
			
			if(i == K-1)
				lastIdx = idx;
		}
		
		for(int i=0; i < N - 1; i++) {  //중복 알파벳 체크
			for(int j=i + 1; j<N; j++) {
				if(arr[i] != null && arr[j] != null && arr[i].equals(arr[j])) {
					bw.write("!");
					bw.flush();
					bw.close();
					br.close();
					System.exit(0);
				}
			}
		}
		
		for(int i=0; i < N; i++) {
			if(lastIdx - i < 0)
				lastIdx += N;
				
			if(arr[lastIdx - i] == null)
				bw.write("?");
			else
				bw.write(arr[lastIdx - i]);
		}
		bw.flush();
		bw.close();
		br.close();
	}
}
