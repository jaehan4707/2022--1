/*
1.해밀턴의 회로의 수는 어디서 출발하든 같다.
2.해밀턴 회로란 출발점에서 모든 노드를 방문하고 마지막에 다시 출발점으로 오는 경로의수다. 여기서 주의할점은 모든 노드를 딱 한번만 방문해야한다는점이다.
3.하지만 해밀턴 경로의 수는 출발정점에 따라 다르다.
4.정점의 수는 n*m이다. 종료 조건은 i가 n*m이 될떄이면 될것이다.
5.kngiht가 이동할 수 있는 방향은 8가지이다.
6.나이트가 정점마다 갈 수있는 경로를 뽑는게 좋을거같은데
7.체스판을 0번부터 n*m-1번까지 1차원 배열로 만든다.
8.각 정점마다 갈 수 있는 수는
*/
//해밀턴회로만 신경쓰자.
/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int n, m, T, cnt = 0, Cnt;
vector<int> visit;
int Size;
void knight(int x, int y, int start, int i);
bool promising(int x, int y, int i);
int mx[8] = { 1,1,-1,-1,2,2,-2,-2 };
int my[8] = { 2,-2,2,-2,1,-1,1,-1 };
vector<vector<int>>board;
int main()
{
	cin >> n >> m; // n은 row, m은 col
	Size = n * m - 1;
	visit.resize(n * m);
	// Visit.resize(n * m);
	//graph.resize(n * m, vector<int>(m * n, 0));
	
	board.resize(n, vector<int>(m, -1));
	board[0][0] = 1;
	knight(0, 0, 0, 0);
	cout <<cnt<<endl; //cnt가 회로 Cnt가 경로
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int row, col;
		cin >> row >> col; //이걸 그걸로 바꿔야함.
		int s = row * m + col;
		cnt = 0; Cnt = 0;
		board.assign(n, vector<int>(m, -1)); //이거 왜 초기화 안되냐?
		board[row][col] = 1;
		knight(row, col, s, 0);
		if (i < T - 1)
			cout << Cnt << endl;
		else
			cout << Cnt;
	}

}
bool promising(int x, int y, int i) //해당 경로가 유효한지,방문한지안한지 체크해줌.
{
	if (x < 0 || x >= n || y < 0 || y >= m)
		return false;
	if (board[x][y] != -1)//이미 방문한 곳이라면 초기에 board를 -1로 초기화하고 방문하면 값을 바꿔줌.
		return false;
	return true;
}
void knight(int x, int y, int start,int i) //출발점을 좌표화 해야함. start의 가 8이면 row는  8
{
	if (i == n * m-1) //끝까지 다 돌았을 경우
	{
		//회로 경로 체크해줘야함. 회로는 다시 돌아와야하죠. 그러면 현재좌표에서 출발점으로 와야함.
		for (int k = 0; k < 8; k++)
		{
			//n이 3 m이 4일때
			int startR = start / m;
			int startC = start % m;
			if (x + mx[k] == startR && y + my[k] == startC)
			{
				cnt++; //되돌아간다면 회로 맞음.
			}
		}
		Cnt++; // 되돌아갈수없다면 경로를 ++해줌.
	}
	else
	{
		for (int j= 0; j < 8; j++)
		{
			int xx = x + mx[j];
			int yy = y + my[j];
			if (promising(xx, yy, i)) //갈수있다면?
			{
				board[xx][yy] = i + 1; //방문할게요
				knight(xx, yy, start, i + 1);
				board[xx][yy] = -1; //나간다면 -1로 초기화 방문
			}
		}
	}
}
*/