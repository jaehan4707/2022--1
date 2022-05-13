/*
1.백트래킹을 활용한 배낭문제
2.모든 문제에서 그랫듯 단위무게당 이득을 내림차순으로 정렬함.
3. 0-1 knapsack이라 보석을 쪼개서 담을 수 있다.
4. 모든 노드를 방문하는 DFS방식으로 문제를 풀이할예정
5. weight(현재 담은 무게)와 W(가방의 용량)을 비교하면서 가지치기
6. Bound와 Maxprofit을 설정해서 Bound(기대되는 이득?)이 Maxprofit보다 작으면 굳이 탐색할 필요가 없음. 가지치기
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
//root 방문하고 profit이랑 weight 박고 bound설정해줘야함. bound는 내가 담을수 있는 최대한의 가치
{
	if (Weight <= W && Profit > maxprofit)
	{
		maxprofit = Profit;
		copy(include.begin(), include.end(), best.begin());

	}
	if (promising(i, Profit, Weight,bound)) {
		include[i + 1] = true;
		knapsack_4(i + 1, Profit + profit[i+ 1], Weight+weight[i+ 1]); //담는경우
		//include = 0,1,0,1 가 최대값이다.
		include[i + 1] = false; //되돌아왓을때
		knapsack_4(i + 1, Profit, Weight); //안담앗을때는 
	}
}
bool promising(int i, int Profit, int Weight,int &bound) //Profit은 내가 지금 담은 가치 Weight는 내가 담은 용량
{
	if (Weight > W) //내가 담은 무게가 가방용량보다 무겁다면 ? 다시 되돌아가야함.
	{
		cout << i << " " << Weight << " " << Profit << " " << bound << " " << maxprofit;
		cout << endl;
		return false;
	}
	else //만약 담을 수있다면?
	{
		//무게가 초과안할때까지 bound에 넣어줌.
		//현재담을 무게를 제외하고 bound에 넣고 넣은 뒤에 넣어줌.
		int k = i + 1;
		bound = Profit;
		total = Weight;
		while (k <= n && total+weight[k] <= W) //total+ 다음 담을 용량이 W보다 작아야함. 그게 크다면 따로 조건을 걸어서 남는 무게만큼 bound에 넣어주면됨.
		{
			total += weight[k];
			bound += profit[k];
			k++;
		}
		if(k <= n)//다음 담을 무게가 초과시 k번째에서 담을 때 가방이 터진거니까 k를 담으면됨.
		{
			bound += (W - total) * (profit[k] / weight[k]);
		}
		cout << i << " "<<Weight <<" "<<  Profit <<" "<< bound <<" "<< maxprofit;
		cout << endl;
		if (bound > maxprofit)
			return true;
		else
			return false;//bound가 maxprofit보다 클때 promising 가능.
	}
}