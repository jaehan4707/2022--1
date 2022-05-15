/*
1.배낭을 단위 무게별로 정렬시킴.
2.함수 내에서n은 남은 보석의 개수 w는 내가 담을수있는 무게.
3.DP를 사용하는데 담는경우와 안담는경우를 구분함
4.담았을때는 (n->n-1) 그리고 (w->w-w[i])로 바꿔줌 담았으니까
5.담지않았을떄는 (n->n-1), (w->w-w[i])로 바꿔줌.
6 P[i][w]의 값은 P[i-1][w] (담지 않은경우) Vs P[i-1][w-w[i]] + P[i]를 비교해야한다. 조건은 w[i]가 w보다 작거나 같아야 한다. 
7. n==0 혹은 W=0이 되었을때 중단하면 된다. n=0이라는 뜻은 이제 더이상 보석을 담을 수가 없다는 뜻이고 w=0이면 가방이 꽉 찼다는 뜻이다.

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
int Knapsack3(int n, int W, vector<int>&w, vector<int>& p, map<pair<int, int>,int>&P) //map은 n으로 오름차순 정렬함.
{
	if (n == 0 || W <= 0)
	{
		return 0;
	}
	int lvalue = (P.find(make_pair(n - 1, W)) != P.end()) ? //조건이 참이면 앞에거 아니면 뒤에거
		P[make_pair(n - 1, W)] : Knapsack3(n - 1, W, w, p, P);
	int rvalue = (P.find(make_pair(n - 1, W - w[n])) != P.end()) ?
		P[make_pair(n - 1, W)] : Knapsack3(n - 1, W - w[n], w, p, P);
	P[make_pair(n, W)] = (w[n] > W) ? lvalue : max(lvalue, p[n] + rvalue);
	return P[make_pair(n, W)];

}
*/