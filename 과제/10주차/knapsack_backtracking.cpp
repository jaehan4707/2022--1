/*
1.��Ʈ��ŷ�� Ȱ���� �賶����
2.��� �������� �׷��� �������Դ� �̵��� ������������ ������.
3. 0-1 knapsack�̶� ������ �ɰ��� ���� �� �ִ�.
4. ��� ��带 �湮�ϴ� DFS������� ������ Ǯ���ҿ���
5. weight(���� ���� ����)�� W(������ �뷮)�� ���ϸ鼭 ����ġ��
6. Bound�� Maxprofit�� �����ؼ� Bound(���Ǵ� �̵�?)�� Maxprofit���� ������ ���� Ž���� �ʿ䰡 ����. ����ġ��
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int n, W,maxprofit,total,bound;
vector<int>weight;
vector<int>profit;
vector<int>include(10000);
vector<int>best(10000);
bool promising(int i, int Profit, int Weight, int& bound);
void knapsack_4(int i, int Profit, int Weight);
int main()
{
	cin >> n >> W;
	weight.resize(n+1);
	profit.resize(n+1);
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
			if (profit[i] / weight[i] < profit[j] / weight[j])
			{
				swap(profit[i], profit[j]);
				swap(weight[i], weight[j]);
			}
		}
	}
	knapsack_4(0, 0, 0);
	cout << maxprofit<<endl;
	int cnt = 0,temp=0;
	for (int i = 1; i <= n; i++)
	{
		if (best[i] == 1)
		{
			cnt++;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (best[i] == 1)
		{
			temp++;
			if (temp != cnt)
				cout << weight[i] << " " << profit[i] << endl;
			else
				cout << weight[i] << " " << profit[i];
		}
	}
	//while (getchar() != '\n');
}
void knapsack_4(int i, int Profit, int Weight) 
//root �湮�ϰ� profit�̶� weight �ڰ� bound�����������. bound�� ���� ������ �ִ� �ִ����� ��ġ
{
	if (Weight <= W && Profit > maxprofit)
	{
		maxprofit = Profit;
		copy(include.begin(), include.end(), best.begin());

	}
	if (promising(i, Profit, Weight,bound)) {
		include[i + 1] = true;
		knapsack_4(i + 1, Profit + profit[i+ 1], Weight+weight[i+ 1]); //��°��
		//include = 0,1,0,1 �� �ִ밪�̴�.
		include[i + 1] = false; //�ǵ��ƿ�����
		knapsack_4(i + 1, Profit, Weight); //�ȴ�������� 
	}
}
bool promising(int i, int Profit, int Weight,int &bound) //Profit�� ���� ���� ���� ��ġ Weight�� ���� ���� �뷮
{
	if (Weight > W) //���� ���� ���԰� ����뷮���� ���̴ٸ� ? �ٽ� �ǵ��ư�����.
	{
		cout << i << " " << Weight << " " << Profit << " " << bound << " " << maxprofit;
		cout << endl;
		return false;
	}
	else //���� ���� ���ִٸ�?
	{
		//���԰� �ʰ����Ҷ����� bound�� �־���.
		//������� ���Ը� �����ϰ� bound�� �ְ� ���� �ڿ� �־���.
		int k = i + 1;
		bound = Profit;
		total = Weight;
		while (k <= n && total+weight[k] <= W) //total+ ���� ���� �뷮�� W���� �۾ƾ���. �װ� ũ�ٸ� ���� ������ �ɾ ���� ���Ը�ŭ bound�� �־��ָ��.
		{
			total += weight[k];
			bound += profit[k];
			k++;
		}
		if(k <= n)//���� ���� ���԰� �ʰ��� k��°���� ���� �� ������ �����Ŵϱ� k�� �������.
		{
			bound += (W - total) * (profit[k] / weight[k]);
		}
		cout << i << " "<<Weight <<" "<<  Profit <<" "<< bound <<" "<< maxprofit;
		cout << endl;
		if (bound > maxprofit)
			return true;
		else
			return false;//bound�� maxprofit���� Ŭ�� promising ����.
	}
}