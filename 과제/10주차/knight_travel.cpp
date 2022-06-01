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
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int n, m, T, cnt = 0, Cnt;
vector<int>visit;
int Size;
vector<vector<int>>graph;
void Move(int i);
void knight(int i,int node,int start,int now);
bool promising(int i,int node, int first);
int main()
{
	cin >> n >> m; //n은 row, m은 col
	Size = n * m-1;
	visit.resize(n * m);
	//Visit.resize(n * m);
	graph.resize(n*m, vector<int>(m*n, 0));
	for (int i = 0; i <= Size; i++)
	{
		Move(i); //
	}
	knight(0,0,0,0);
	visit.resize(n * m, 0);
	cout << cnt<<endl;
	Cnt = 0;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int s, f;
		cin >> s >> f;
		int vv = s * m + f;
		visit[0] = vv;
		knight(0, 0,vv,0); //i,node,start,now
		if (i < T - 1)
		{
			cout << Cnt << endl;
		}
		else
			cout << Cnt;
		Cnt = 0;
	}
}
void knight(int i,int node,int start,int now)
{
	bool opt = true;
	if (promising(i,node,start)) // node는 내가 가려는 곳 start는 출발 정점.
	{
		if (i == n*m-1)
		{
			cnt++;
		}
		else
		{
			for (int j = 0; j <= Size; j++)
			{
				//visit[i]기준으로 갈 수 있는 방향을 선정해야함.
				
				if (graph[visit[i]][j] == 1) //경로가 있고
				{
					visit[i + 1] = j;
					knight(i + 1, j, start, visit[i]); //knight탈출하면 방문안햇다는 뜻임.
					visit[i + 1] = 0;
				}
				
			}
		}
	}
}
bool promising(int i,int node,int start) //방문한곳이면 안간다. 그리고 갈 수있는 곳은 미리 체크하는게 나을까? 경로가 없으면 0 경로가 있으면 1이다. node가 내가 갈곳 start는 내가있는곳
{
	//마지막 정점일때는 거기서 출발점까지의 경로가 무조건 있어야함.
	bool flag=true;
	bool opt;
	int now=0;
	if (i == Size&& graph[visit[Size]][start]!=1) //회로는 출발점을 다시 돌아와야함. //visit[Size]가 맨 마지막에 방문한 노드일거다 아마.
	{
		flag = false;
	}
	if (i ==Size&&graph[visit[i]][visit[i-1]]==1)//경로는 출발점을 다시 안와도됨. //이미 방문한 노드여도 cnt가 ++됨. 
	{
		opt = true; //초기는 하고 만약에 같은게 없다면 flag는 true이므로
		for (int k = 0; k <i; k++) //Size를 i보다 작을때로 바꿈 자기자신은 검사할필요가없네
		{
			//cout << visit[k] << " ";
			if (visit[i] == visit[k])//이미 방문한 곳이라면
			{
				opt = false;
				flag = false;
			}
		}//반복문이 안걸리고 나오면 트루라는뜻
		if (opt == true)
		{
			Cnt++;
		}
	}
	else if (i>0 && graph[visit[i]][visit[i-1]]!=1) //연결안되어있는건 걍 재낌.
	{
		flag = false;
	}
	else //연결되어있다면 방문했는지 안했는지 체크를 해야함.
	{
		flag = true;
		while (now <i)
		{
			if (visit[now] == visit[i])
			{
				flag = false;
			}
			now++;
		}
	}
	return flag;
}
void Move(int i)
{
	int row = i / m;
	int col = i % m;
	if (row - 2 >= 0 && col - 1>=0)
	{
	
		graph[i][(row-2)*m+col-1] = 1;
		graph[(row-2)*m+col-1][i] = 1;
	}
	if (row - 2 >= 0 && col + 1 <= m - 1)
	{
		graph[i][(row-2)*m+col+1] = 1;
		graph[(row - 2) * m + col + 1][i] = 1;
	}
	if (row + 2 <= n - 1 && col + 1 <= m - 1)
	{
		graph[i][(row + 2) * m + col + 1] = 1;
		graph[(row + 2) * m + col + 1][i] = 1;
	}
	if (row + 2 <= n - 1 && col - 1 >= 0)
	{
		graph[i][(row + 2) * m + col - 1] = 1;
		graph[(row+2)*m+col-1][i] = 1;
	}
	if (row + 1 <= n- 1 && col- 2 >= 0)
	{
		graph[i][(row + 1) * m + col - 2] = 1;
		graph[(row + 1) * m + col - 2][i] = 1;
	}
	if (row + 1 <= n- 1 && col + 2 <= m - 1)
	{
		graph[i][(row + 1) * m + col + 2] = 1;
		graph[(row + 1) * m + col + 2][i] = 1;
	}
	if (row - 1 >= 0 && col + 2 <= m - 1)
	{
		graph[i][(row - 1) * m + col + 2]=1;
		graph[(row - 1) * m + col + 2][i] = 1;
	}
	if (row - 1 >= 0 && col - 2 >= 0)
	{
		graph[i][(row - 1) * m + col - 2] = 1;
		graph[(row - 1) * m + col - 2][i] = 1;
	}
}