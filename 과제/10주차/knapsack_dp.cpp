/*
1.�賶�� ���� ���Ժ��� ���Ľ�Ŵ.
2.�Լ� ������n�� ���� ������ ���� w�� ���� �������ִ� ����.
3.DP�� ����ϴµ� ��°��� �ȴ�°�츦 ������
4.��������� (n->n-1) �׸��� (w->w-w[i])�� �ٲ��� ������ϱ�
5.�����ʾ������� (n->n-1), (w->w-w[i])�� �ٲ���.
6 P[i][w]�� ���� P[i-1][w] (���� �������) Vs P[i-1][w-w[i]] + P[i]�� ���ؾ��Ѵ�. ������ w[i]�� w���� �۰ų� ���ƾ� �Ѵ�. 
7. n==0 Ȥ�� W=0�� �Ǿ����� �ߴ��ϸ� �ȴ�. n=0�̶�� ���� ���� ���̻� ������ ���� ���� ���ٴ� ���̰� w=0�̸� ������ �� á�ٴ� ���̴�.

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int n, W;
vector<int>profit;
vector<int>weight;
int Knapsack3(int n, int W, vector<int>& w, vector<int>& p, map<pair<int, int>, int>& P);
int main()
{
	cin >> n;
	profit.resize(n+1);
	weight.resize(n+1);
	map<pair<int, int>, int>P;
	for (int i = 1; i <= n; i++)
	{
		cin >> weight[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> profit[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (profit[i]/weight[i]<profit[j]/weight[j])
			{
				swap(profit[i], profit[j]);
				swap(weight[i], weight[j]);
			}
		}
	}
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> W;
		int cnt = 0;
		cout<<Knapsack3(n, W, weight, profit, P)<<endl;
		//cout << P.size();
		for (auto iter = P.begin(); iter != P.end(); iter++)
		{
			cout << iter->first.first<<" "<< iter->first.second <<" "<<iter->second;
			cnt++;
			if (i == t - 1 && cnt==P.size())
			{
				continue;
			}
			else 
				cout << endl;
		}
		P.erase(P.begin(),P.end());
	}
}
int Knapsack3(int n, int W, vector<int>&w, vector<int>& p, map<pair<int, int>,int>&P) //map�� n���� �������� ������.
{
	if (n == 0 || W <= 0)
	{
		return 0;
	}
	int lvalue = (P.find(make_pair(n - 1, W)) != P.end()) ? //������ ���̸� �տ��� �ƴϸ� �ڿ���
		P[make_pair(n - 1, W)] : Knapsack3(n - 1, W, w, p, P);
	int rvalue = (P.find(make_pair(n - 1, W - w[n])) != P.end()) ?
		P[make_pair(n - 1, W)] : Knapsack3(n - 1, W - w[n], w, p, P);
	P[make_pair(n, W)] = (w[n] > W) ? lvalue : max(lvalue, p[n] + rvalue);
	return P[make_pair(n, W)];

}
*/