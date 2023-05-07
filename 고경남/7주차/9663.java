package FirstWeek;

import java.io.IOException;
import java.util.Scanner;

public class N_Queen {
	
	static int board[][];
	static int N;
	static int answer = 0;

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		board = new int[N][N];
		DFS(0);
		System.out.println(answer);
	}
	
	public static void DFS(int y) {
		if(y == N) {
			answer++;
			return;
		}
			
		for(int x=0; x<N; x++) { //x : row, y : col
			if(check_col(x, y) && check_diagonal(x, y)) { //행과 대각선에 
				board[y][x] = 1;
				DFS(y + 1);
				board[y][x] = 0;
			}
		}
	}
	
	public static boolean check_col(int x, int y) {  //행 체크
		for(int i=y; i<N; i++) {
			if(board[i][x] == 1)
				return false;
		}
		for(int i=y; i>=0; i--) {
			if(board[i][x] == 1)
				return false;
		}
		return true;
	}
	
	public static boolean check_diagonal(int x, int y) {
		int tmpX = x;
		int tmpY = y;
		do { //왼쪽 위 대각선 체크
			if(board[tmpY][tmpX] == 1)
				return false;
			tmpX--; tmpY--;
		} while(tmpX >= 0 && tmpY >= 0);
		
		tmpX = x;
		tmpY = y;
		do { //왼쪽 아래 대각선 체크
			if(board[tmpY][tmpX] == 1)
				return false;
			tmpX--; tmpY++;
		} while(tmpX >= 0 && tmpY < N);
		
		tmpX = x;
		tmpY = y;
		do { //오른쪽 위 대각선 체크
			if(board[tmpY][tmpX] == 1)
				return false;
			tmpX++; tmpY--;
		} while(tmpX < N && tmpY >= 0);
		
		do { //오른쪽 아래 대각선 체크
			if(board[y][x] == 1)
				return false;
			x++; y++;
		} while(x < N && y < N);
		return true;
	}
}
