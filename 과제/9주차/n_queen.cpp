#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
using namespace std;
int n;
vector<int>board;
void n_queen(int i);
bool promising(int i);
unsigned long long sum = 0, Max = 0;
string a = "";
int main()
{
	cin >> n; //���� ũ��
	board.resize(n + 1);
	n_queen(0);
	cout << sum << endl << Max;
}
void n_queen(int i)
{
	if (promising(i) == 1) //promising�� 1�̸� ��¥���� 0�̸� ����ġ��
	{
		if (i == n) // ������ �� �˻��޴ٴ� ��
		{
			for (int i = 1; i < board.size(); i++)
			{
				a += to_string(board[i]);
				//cout << board[i] << " ";
				//board[i]�� string�� �־ 
			}
			//cout << a << endl;
			long long int temp = stoll(a); //���ڿ��� long long ���� �ٲ�
			if (Max < temp)
				Max = temp;
			a = "";
			sum++;
		}
		else
			for (int j = 1; j <= n; j++)
			{
				board[i + 1] = j;
				n_queen(i + 1);
			}
	}
}
bool promising(int i) //promising �ҋ� ����ġ���ؾ���.
{
	int idx = 1;
	bool flag = true;
	while (idx < i && flag) // idx�� ���� ���� �� ���� �ݺ�, �׸��� ���ΰ��� ã���� promising ����
	{
		if (board[i] == board[idx] || abs(board[i] - board[idx]) == abs(i - idx)) //�������� �밢�� ���δ� ����
		{
			flag = false;
		}
		idx++;
	}
	return flag;
}