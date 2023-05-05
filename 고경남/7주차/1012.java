import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 유기농_배추 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st = null;
	static int[][] visited;
	static int[][] cabbage;

	public static void main(String[] args) throws IOException{
		int T = Integer.parseInt(br.readLine());
		int[] T_arr = new int[T];
		for(int i=0; i<T; i++) {
			st = new StringTokenizer(br.readLine());
			int M = Integer.parseInt(st.nextToken());
			int N = Integer.parseInt(st.nextToken());
			int K = Integer.parseInt(st.nextToken());
			visited = new int[N][M];
			cabbage = new int[N][M];
			enter_cabbage(K);

			for(int y = 0; y<N; y++) {
				for(int x = 0; x<M; x++) {
					if(cabbage[y][x] == 1 && visited[y][x] == 0) {
						T_arr[i]++;
						DFS(x,y);
					}
				}
			}
		}
    
		for(int i=0; i<T; i++) //정답 출력
			System.out.println(T_arr[i]);
	}
	
	public static void enter_cabbage(int K) throws IOException{ //배추 위치 입력 함수
		for(int i=0; i<K; i++) {
			st = new StringTokenizer(br.readLine());
			int Y = Integer.parseInt(st.nextToken());
			int X = Integer.parseInt(st.nextToken());
			cabbage[X][Y] = 1;
		}
	}
	
	public static void DFS(int x, int y){
		if(x == cabbage[0].length || y == cabbage.length || x < 0 || y < 0) {
			return;
		}
		if(cabbage[y][x] == 1 && visited[y][x] == 0) {
			visited[y][x] = 1;
			DFS(x-1, y);
			DFS(x+1, y);
			DFS(x, y-1);
			DFS(x, y+1);
		}
		
	}
}
