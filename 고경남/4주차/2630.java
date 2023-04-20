import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 색종이_만들기 {
	
	static int white = 0;
	static int blue = 0;

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		
		int N = Integer.parseInt(br.readLine());
		int N_arr[][] = new int[N][N];
		
		for(int i=0; i<N;i ++) { //색 입력
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<N; j++) {
				N_arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		partition(0,0,N,N_arr);
		
		System.out.println(white);
		System.out.println(blue);
		
	}
	
	public static void partition(int row, int col, int size, int[][] N_arr) {
		boolean sameColor = true; //한 블럭이 같은 색인지 확인할 변수
		
		int color = N_arr[row][col]; //기준 색
		
		for(int i = row; i < row + size; i++) {
			for(int j = col; j < col + size; j++) {
				if(N_arr[i][j] != color) { //기준 색과 다른 색이 존재하면
					sameColor = false;
				}
			}
		}
		
		if(sameColor) { //전부 동일한 색인 경우
			if(N_arr[row][col] == 0)
				white++;
			else
				blue++;
			return;
		}
		
		size /= 2;
		
		partition(row, col, size, N_arr);
		partition(row, col + size, size, N_arr);
		partition(row + size, col, size, N_arr);
		partition(row + size, col + size, size, N_arr);
	}
}
