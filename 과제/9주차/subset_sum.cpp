#include <iostream>
#include <vector>
#include <string>
using namespace std;
int n,W;
int sum = 0;
int total = 0;
int cnt = 0;
vector<int>seq;
vector<int>sub;
//void subset(vector<int>& sub, int i, int add);
//bool promising(int i, vector<int>& sub,int &add);
void subset(int i, int weight, int total);
bool promising(int i, int weight, int total);
vector<int>include(100000,0);
vector<string>str;
int main()
{
	cin >> n>>W;
	//vector<int>sum(n, 0);
	sub.resize(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> sub[i];
		total = total + sub[i];
	}
	subset(0, 0,total);
	cout << cnt<<endl;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == "")
			cout <<endl;
		else
		{  
			if (str[i + 1] == "")
				cout << str[i];
			else
				cout << str[i]<<" ";
			}
	}
}

void subset(vector<int>& sub, int i,int add)
{
	if (promising(i,sub,add))
	{
		if (add == W)
		{
			cnt++;
			for (int j = 1; j <= i; j++)
			{
				//cout << seq[j]<< " ";
				cout << include[j] << " ";
			}
			cout << endl;
			//seq.resize();
		}
		else
		{
			subset(sub, i + 1,add); //한칸이동하고 더하고 안더하고를 구해야함.
			include[i] = false;
			add = add - sub[i];
			subset(sub, i + 1, add);
			//seq배열을 중단시점에서 끌어와야함.
		}
	}
}
bool promising(int i, vector<int>& sub,int &add)
{
	int result = 0;
	for (int j = 1; j < i; j++)
	{
		result = result + sub[j];
	}
	if (sub[i] + add > W || add + total -result < W) //sum은  더해준 총 합. sub[i]는 그때의 무게
	{
		//if(seq.size()>0)
			//seq.pop_back();
		return 0;
	}
	//seq.push_back(sub[i]);
	add = add+ sub[i];
	include[i] = true;
	return 1;
	//더해줘야함.
}
void subset(int i, int weight, int total) {
	if (promising(i, weight, total)) {
		if (weight == W)
		{
			cnt++;
			string ab = "";
			for (int j = 1; j <= i; j++)
			{
				if (include[j] == 1)
					//ab += to_string(sub[j]);
					//str[cnt].push_back(ab[j-1]);
					str.push_back(to_string(sub[j]));
				//ab += to_string(sub[include[j]]); //ab에 저장됨.
				//str[cnt].push_back(to_string(include[i]));
				//cout << include[j] << " ";
				//str[cnt].push_back(ab);
			}
			str.push_back("");
			//ab에 저장된걸 스트링 배열에 넣고싶음
		}
		else
		{
			include[i + 1] = true;
			subset(i + 1, weight + sub[i + 1], total - sub[i + 1]);
			include[i + 1] = false;
			subset(i + 1, weight, total - sub[i + 1]);
		}
	}
}
bool promising(int i, int weight, int total) {
	return (weight + total >= W) && (weight == W || weight + sub[i + 1] <= W);
}