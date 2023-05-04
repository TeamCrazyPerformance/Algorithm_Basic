import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class N과M_1 {
	static int arr[];   //M자리의 숫자를 저장할 배열
	static int visit[]; //N개의 숫자 방문 여부 체크 배열

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		
		arr = new int[M];
		visit = new int[N+1];
		
		DFS(N, M, 0);
	}
	
	public static void DFS(int N, int M, int point) {
		if(point == M) { //현재 지점이 M값과 같다면 arr배열 값 출력
			for(int i=0; i<M; i++) {
				System.out.print(arr[i] + " ");
			}
			System.out.println();
			return;
		}
		
		for(int i=1; i<=N; i++) {
			if(visit[i] == 0) { //방문하지 않은 경우
				visit[i] = 1;     //방문으로 변경
				arr[point] = i;   //배열에 point 지점에 값 저장
				DFS(N, M, point+1);
				visit[i] = 0;     //방문 해제
			}
		}
	}
}
