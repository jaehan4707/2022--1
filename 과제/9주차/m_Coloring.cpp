/*
#include <iostream>
#include <vector>
using namespace std;
int N, k, cnt = 0,val=0,opt=0;
vector<vector<int>>g;
vector<int>color;
bool promising(int i);
void draw(int col, int m, int &opt);
int main()
{
	cin >> N >> k;
	g.resize(N+1, vector<int>(N+1, 0));
	for (int i = 0; i < k; i++)
	{
		int s, f = 0;
		cin >> s >> f;
		g[s][f] = 1, g[f][s] = 1;
	}
	color.resize(N+1, 0);
	int idx = 0;
	while (1) //계속 반복해서 색깔을 추가해줌.
	{
		draw(idx, val, opt);
		if(opt==1) //val값으로 다 칠한 경우 그때의 val값이 최소의 색깔이고 cnt가 최소의 색깔로 칠할 수 있는 경우의수
		{
			cout << val<<endl;
			cout << cnt;
			break;
		}
		else
			val++;
	}

	//cout <<m<<endl<<cnt;
}
bool promising(int i)
{
	int j = 1;
	bool flag = true;
	while (i > j&&flag)
	{
		if (g[i][j] == 1 && color[i] == color[j])  //가지치기 조건. 인접했고, 색깔이 같을 경우
		{
			//return 0; 바로 종료하면 안됨 끝까지 탐색을 못함. 한번이라도 if문을 들어가면 칠하면안되는거니까 flag에 0을 넣어줌.
			flag = false;
		}
		j++;
	}
	return flag;
}
void draw(int i,int m , int &opt)
{
	if (promising(i))//적절하면 실행하고 적절하지 않으면 넘어감.
	{
		if (i == N) //끝까지 다 칠했을 때
		{
			cnt++;
			opt = 1;
		}
		else
		{
			for (int j = 1; j <=m; j++) //지정해준 m까지 반복문을 돌림
			{
				color[i+1] = j; //i+1 에 j를 칠하고 draw(i+1)호출했는데 적절하지 않으면 다시 되돌아와서 다음색깔을 칠해줌.
				draw(i+1,m,opt); //다음칸에 칠하고 적절한지 검사함.
			}
		}	
	}
}
*/