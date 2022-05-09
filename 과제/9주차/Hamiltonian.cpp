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
bool promising(int i) //������ 2������. �ϴ� ������ �������϶��� �� �������� 1�� ����Ǿ��־����.
{
	//i�� 1�� ��
	bool flag;
	//flag = 1;
	int idx=1;
	if (i == G - 1 && graph[visit[G-1]][visit[0]]!=1) //i���������� 
	{
		flag = false;
	}
	else if (i>0&&graph[visit[i]][visit[i-1]]!= 1)
	{
		flag = false;
	}
	else //���⼭�� ���������. ��������尡 �ƴϴϱ�
	{
		flag = true;
		while (idx < i) //���� �湮�� ��尡 i��.
		{
			if (visit[idx] == visit[i]) //������ �ΰ��� ����Ǿ��־���ϰ� �湮�Ѱ��̾ƴϿ�����.
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
	if (promising(i)) //���� �˻縦 ���� �� �����Ѱ�?
	{
		if (i == G - 1) // ������ ������ n-1�� �϶� �����ؾ���
		{
			cnt++; //��� �߰�
		}
		else
		{
			for (int j = 2; j <= G; j++)
			{
				visit[i + 1] = j; //���� �湮�Ѱ��� ������ �����. ������ ��ġ�� ��� Ż���ϰ� �ٽ� �ݺ��� ���ư�.
				hamiltonian(i + 1);
			}
		}
	}
}