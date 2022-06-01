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
	cin >> n >> m; //n�� row, m�� col
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
	if (promising(i,node,start)) // node�� ���� ������ �� start�� ��� ����.
	{
		if (i == n*m-1)
		{
			cnt++;
		}
		else
		{
			for (int j = 0; j <= Size; j++)
			{
				//visit[i]�������� �� �� �ִ� ������ �����ؾ���.
				
				if (graph[visit[i]][j] == 1) //��ΰ� �ְ�
				{
					visit[i + 1] = j;
					knight(i + 1, j, start, visit[i]); //knightŻ���ϸ� �湮���޴ٴ� ����.
					visit[i + 1] = 0;
				}
				
			}
		}
	}
}
bool promising(int i,int node,int start) //�湮�Ѱ��̸� �Ȱ���. �׸��� �� ���ִ� ���� �̸� üũ�ϴ°� ������? ��ΰ� ������ 0 ��ΰ� ������ 1�̴�. node�� ���� ���� start�� �����ִ°�
{
	//������ �����϶��� �ű⼭ ����������� ��ΰ� ������ �־����.
	bool flag=true;
	bool opt;
	int now=0;
	if (i == Size&& graph[visit[Size]][start]!=1) //ȸ�δ� ������� �ٽ� ���ƿ;���. //visit[Size]�� �� �������� �湮�� ����ϰŴ� �Ƹ�.
	{
		flag = false;
	}
	if (i ==Size&&graph[visit[i]][visit[i-1]]==1)//��δ� ������� �ٽ� �ȿ͵���. //�̹� �湮�� ��忩�� cnt�� ++��. 
	{
		opt = true; //�ʱ�� �ϰ� ���࿡ ������ ���ٸ� flag�� true�̹Ƿ�
		for (int k = 0; k <i; k++) //Size�� i���� �������� �ٲ� �ڱ��ڽ��� �˻����ʿ䰡����
		{
			//cout << visit[k] << " ";
			if (visit[i] == visit[k])//�̹� �湮�� ���̶��
			{
				opt = false;
				flag = false;
			}
		}//�ݺ����� �Ȱɸ��� ������ Ʈ���¶�
		if (opt == true)
		{
			Cnt++;
		}
	}
	else if (i>0 && graph[visit[i]][visit[i-1]]!=1) //����ȵǾ��ִ°� �� �糦.
	{
		flag = false;
	}
	else //����Ǿ��ִٸ� �湮�ߴ��� ���ߴ��� üũ�� �ؾ���.
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