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
	while (1) //��� �ݺ��ؼ� ������ �߰�����.
	{
		draw(idx, val, opt);
		if(opt==1) //val������ �� ĥ�� ��� �׶��� val���� �ּ��� �����̰� cnt�� �ּ��� ����� ĥ�� �� �ִ� ����Ǽ�
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
		if (g[i][j] == 1 && color[i] == color[j])  //����ġ�� ����. �����߰�, ������ ���� ���
		{
			//return 0; �ٷ� �����ϸ� �ȵ� ������ Ž���� ����. �ѹ��̶� if���� ���� ĥ�ϸ�ȵǴ°Ŵϱ� flag�� 0�� �־���.
			flag = false;
		}
		j++;
	}
	return flag;
}
void draw(int i,int m , int &opt)
{
	if (promising(i))//�����ϸ� �����ϰ� �������� ������ �Ѿ.
	{
		if (i == N) //������ �� ĥ���� ��
		{
			cnt++;
			opt = 1;
		}
		else
		{
			for (int j = 1; j <=m; j++) //�������� m���� �ݺ����� ����
			{
				color[i+1] = j; //i+1 �� j�� ĥ�ϰ� draw(i+1)ȣ���ߴµ� �������� ������ �ٽ� �ǵ��ƿͼ� ���������� ĥ����.
				draw(i+1,m,opt); //����ĭ�� ĥ�ϰ� �������� �˻���.
			}
		}	
	}
}
*/