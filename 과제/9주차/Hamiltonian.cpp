#include <iostream>
#include <vector>

using namespace std;

int G, V,cnt=0;
vector < vector<int>>graph;
vector<int>visit;
bool promising(int i);
void hamiltonian(int i);
int main()
{
	cin >> G >> V;
	graph.resize(G + 1, vector<int>(G + 1, 0));
	visit.resize(G + 1);
	for (int i = 0; i < V; i++)
	{
		int s, f;
		cin >> s >> f;
		graph[s][f] = 1, graph[f][s] = 1;
	}
	visit[0] = 1;
	hamiltonian(0);
	cout << cnt;
}
bool promising(int i) //조건이 2개있음. 일단 마지막 도착지일때는 그 도착지와 1이 연결되어있어야함.
{
	//i가 1일 때
	bool flag;
	//flag = 1;
	int idx=1;
	if (i == G - 1 && graph[visit[G-1]][visit[0]]!=1) //i가현재정점 
	{
		flag = false;
	}
	else if (i>0&&graph[visit[i]][visit[i-1]]!= 1)
	{
		flag = false;
	}
	else //여기서는 돌아줘야함. 마지막노드가 아니니까
	{
		flag = true;
		while (idx < i) //내가 방문한 노드가 i임.
		{
			if (visit[idx] == visit[i]) //조건은 두개가 연결되어있어야하고 방문한곳이아니여야함.
			{
				flag = false;
			}
			idx++;
		}
	}
	return flag;
}
void hamiltonian(int i)
{
	if (promising(i)) //조건 검사를 햇을 떄 적절한가?
	{
		if (i == G - 1) // 간선의 개수가 n-1개 일때 종료해야함
		{
			cnt++; //경로 추가
		}
		else
		{
			for (int j = 2; j <= G; j++)
			{
				visit[i + 1] = j; //현재 방문한곳에 정점을 찍어줌. 정점이 겹치면 재귀 탈출하고 다시 반복문 돌아감.
				hamiltonian(i + 1);
			}
		}
	}
}