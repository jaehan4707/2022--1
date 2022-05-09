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
	cin >> n; //보드 크기
	board.resize(n + 1);
	n_queen(0);
	cout << sum << endl << Max;
}
void n_queen(int i)
{
	if (promising(i) == 1) //promising이 1이면 안짜르고 0이면 가지치기
	{
		if (i == n) // 끝까지 다 검사햇다는 뜻
		{
			for (int i = 1; i < board.size(); i++)
			{
				a += to_string(board[i]);
				//cout << board[i] << " ";
				//board[i]를 string에 넣어서 
			}
			//cout << a << endl;
			long long int temp = stoll(a); //문자열을 long long 으로 바꿈
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
bool promising(int i) //promising 할떄 가지치기해야함.
{
	int idx = 1;
	bool flag = true;
	while (idx < i && flag) // idx가 넘지 않을 때 까지 반복, 그리고 참인값을 찾으면 promising 종료
	{
		if (board[i] == board[idx] || abs(board[i] - board[idx]) == abs(i - idx)) //같은열과 대각선 전부다 제외
		{
			flag = false;
		}
		idx++;
	}
	return flag;
}