#include <iostream>
#include <vector>

using namespace std;
typedef struct bag {
	int weight;
	int profit;
	int perweight;
	int id;
}bag;
int n, t, lim,Max,total;
vector<bag>bagvector;
vector<bag>knap;
void knapsack(vector<bag>&knap, int& maxprofit, int& totweight,bag *c);
int main()
{

	cin >> n;
	bag* b = new bag[n];
	bag* c = new bag[n];
	vector<int>weight;
	vector<int>profit;
	for (int i = 0; i < n; i++)
	{
		int w;
		cin >> w;
		weight.push_back(w);
	}
	for (int i = 0; i < n; i++)
	{
		int p;
		cin >> p;
		profit.push_back(p);
	}
	int i = 0;
	for (int i = 0; i<n; i++)
	{		
		if (weight[i] == 0 || profit[i] == 0)
		{
			continue;
		}
		else {
			b[i].weight = weight[i];
			b[i].profit = profit[i];
			b[i].perweight = profit[i] / weight[i];
			knap.push_back(b[i]);
		}
	}
	for (int i = 0; i < knap.size(); i++)
	{
		for (int j = i + 1; j <knap.size(); j++)
		{
			if (knap[i].perweight < knap[j].perweight)
			{
				swap(knap[i], knap[j]);
			}
		}
	}
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> lim;
		knapsack(knap, Max, total,c);
		cout << Max << "\n";
		for (int j = 0; j < bagvector.size(); j++)
		{
			if (i == t - 1 && j == bagvector.size() - 1)
				cout << bagvector[i].weight << " " << bagvector[j].profit;
			else
				cout << bagvector[j].weight << " " << bagvector[j].profit<<"\n";
		}
		bagvector.resize(0);
	}
}
void knapsack(vector<bag>&b,int &maxprofit,int &totweight,bag *c)
{
	maxprofit = totweight = 0;
	for (int i = 0; i < b.size(); i++)
	{
		if (totweight + b[i].weight <= lim) {//²ËÂû¶§±îÁö °è¼Ó³Ö´Â´Ù
			maxprofit += b[i].profit;
			totweight += b[i].weight;
			c[i].profit = b[i].profit;
			c[i].weight = b[i].weight;
			bagvector.push_back(c[i]);
		}
		else
		{
			c[i].profit = (lim - totweight) * b[i].perweight;
			c[i].weight = (lim - totweight);
			if(c[i].profit!=0 && c[i].weight!=0)
				bagvector.push_back(c[i]);
			maxprofit += (lim - totweight) * b[i].perweight;
			totweight += (lim - totweight);
			break;
		}
	}
}