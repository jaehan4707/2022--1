/*
deadline 스케쥴링 문제
시간을 최대한 적게쓰면서 이익을 최대로 해야한다.
어떤식으로 배치해야 적은 시간을 쓰면서 최대한의 효율을 낼 수있을까?
각각의 job에는 deadline이 존재한다. deadline안에 해야 그 job은 유효하다.
deadline을 넘어선 시간대에 job을 선택하면 그것은 impossible하다.
*/
/*
#include <iostream>
#include <vector>


using namespace std;
vector<int>j, k;
typedef struct Schedule
{
	int deadline;
	int profit;
};
void schedule(int n, Schedule* s, vector<int>& j, vector<int>& k);
bool is_feasible(vector<int>& k, Schedule* s);
int main() 
{
	int n;
	cin >> n;
	Schedule* s=new Schedule[n+1];
	vector<int>deadline;
	vector<int>profit;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i].deadline;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i].profit;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (s[i].profit < s[j].profit)
			{
				swap(s[i], s[j]);
			}
		}
	}
	schedule(n, s, j, k);
	int sum = 0;
	for (int i = 1; i < j.size(); i++)
	{
		sum = sum + s[j[i]].profit;
	}
	cout << sum<<"\n";
	for (int i = 1; i < j.size(); i++)
	{
		if (i < j.size() - 1)
			cout << s[j[i]].profit << " ";
		else
			cout << s[j[i]].profit;
	}
}
void schedule(int n, Schedule* s, vector<int>& j, vector<int>& k)
{
	j.clear();
	j.push_back(0);
	j.push_back(1);
	for (int i = 2; i <= n; i++)
	{
		k.resize(j.size());
		copy(j.begin(), j.end(), k.begin());
		int cnt = 1;
		while (cnt < k.size() && s[k[cnt]].deadline <= s[i].deadline)
			cnt++;
		k.insert(k.begin() + cnt, i);
		if (is_feasible(k, s)) {
			j.resize(k.size());
			copy(k.begin(), k.end(), j.begin());
		}
	}
}
bool is_feasible(vector<int>& k, Schedule* s)
{
	for (int i = 1; i < k.size(); i++)
	{
		if (i > s[k[i]].deadline)
			return false;
	}
	return true;
}
*/