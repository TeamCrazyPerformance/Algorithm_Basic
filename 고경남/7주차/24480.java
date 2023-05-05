import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class 알고리즘_수업_깊이_우선_탐색_2 {
	
	static ArrayList<ArrayList<Integer>> line = new ArrayList<>();
	static int[] visited;
	static int[] arr;
	static int point = 1;
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
			
		st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int R = Integer.parseInt(st.nextToken());
			
		visited = new int[N];
		arr = new int[N];
		
		for(int i=0; i<N+1; i++) {
			line.add(new ArrayList<>());
		}
			
		for(int i=0; i<M; i++) {
			st = new StringTokenizer(br.readLine());
			int first = Integer.parseInt(st.nextToken());
			int second = Integer.parseInt(st.nextToken());
			line.get(first).add(second);
			line.get(second).add(first);
		}
			
		for(int i=0; i<N+1; i++) {
			Collections.sort(line.get(i), Collections.reverseOrder());
		}
			
		DFS(R);
		for(int i=0; i<N; i++) {
			System.out.println(arr[i]);
		}
		
	}
		
	public static void DFS(int R) {
		visited[R-1] = 1;
		arr[R-1] = point;
		for(int i = 0; i<line.get(R).size(); i++) {
				if(visited[line.get(R).get(i)-1] == 0) {
					point++;
					DFS(line.get(R).get(i));
				}
		}
	}
}
