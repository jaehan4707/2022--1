/*
1.�ع����� ȸ���� ���� ��� ����ϵ� ����.
2.�ع��� ȸ�ζ� ��������� ��� ��带 �湮�ϰ� �������� �ٽ� ��������� ���� ����Ǽ���. ���⼭ ���������� ��� ��带 �� �ѹ��� �湮�ؾ��Ѵٴ����̴�.
3.������ �ع��� ����� ���� ��������� ���� �ٸ���.
4.������ ���� n*m�̴�. ���� ������ i�� n*m�� �ɋ��̸� �ɰ��̴�.
5.kngiht�� �̵��� �� �ִ� ������ 8�����̴�.
6.����Ʈ�� �������� �� ���ִ� ��θ� �̴°� �����Ű�����
7.ü������ 0������ n*m-1������ 1���� �迭�� �����.
8.�� �������� �� �� �ִ� ����
*/
//�ع���ȸ�θ� �Ű澲��.
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
	cin >> n >> m; // n�� row, m�� col
	Size = n * m - 1;
	visit.resize(n * m);
	// Visit.resize(n * m);
	//graph.resize(n * m, vector<int>(m * n, 0));
	
	board.resize(n, vector<int>(m, -1));
	board[0][0] = 1;
	knight(0, 0, 0, 0);
	cout <<cnt<<endl; //cnt�� ȸ�� Cnt�� ���
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int row, col;
		cin >> row >> col; //�̰� �װɷ� �ٲ����.
		int s = row * m + col;
		cnt = 0; Cnt = 0;
		board.assign(n, vector<int>(m, -1)); //�̰� �� �ʱ�ȭ �ȵǳ�?
		board[row][col] = 1;
		knight(row, col, s, 0);
		if (i < T - 1)
			cout << Cnt << endl;
		else
			cout << Cnt;
	}

}
bool promising(int x, int y, int i) //�ش� ��ΰ� ��ȿ����,�湮���������� üũ����.
{
	if (x < 0 || x >= n || y < 0 || y >= m)
		return false;
	if (board[x][y] != -1)//�̹� �湮�� ���̶�� �ʱ⿡ board�� -1�� �ʱ�ȭ�ϰ� �湮�ϸ� ���� �ٲ���.
		return false;
	return true;
}
void knight(int x, int y, int start,int i) //������� ��ǥȭ �ؾ���. start�� �� 8�̸� row��  8
{
	if (i == n * m-1) //������ �� ������ ���
	{
		//ȸ�� ��� üũ�������. ȸ�δ� �ٽ� ���ƿ;�����. �׷��� ������ǥ���� ��������� �;���.
		for (int k = 0; k < 8; k++)
		{
			//n�� 3 m�� 4�϶�
			int startR = start / m;
			int startC = start % m;
			if (x + mx[k] == startR && y + my[k] == startC)
			{
				cnt++; //�ǵ��ư��ٸ� ȸ�� ����.
			}
		}
		Cnt++; // �ǵ��ư������ٸ� ��θ� ++����.
	}
	else
	{
		for (int j= 0; j < 8; j++)
		{
			int xx = x + mx[j];
			int yy = y + my[j];
			if (promising(xx, yy, i)) //�����ִٸ�?
			{
				board[xx][yy] = i + 1; //�湮�ҰԿ�
				knight(xx, yy, start, i + 1);
				board[xx][yy] = -1; //�����ٸ� -1�� �ʱ�ȭ �湮
			}
		}
	}
}
*/