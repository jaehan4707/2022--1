/*
deadline 스케쥴링 문제
시간을 최대한 적게쓰면서 이익을 최대로 해야한다.
어떤식으로 배치해야 적은 시간을 쓰면서 최대한의 효율을 낼 수있을까?
각각의 job에는 deadline이 존재한다. deadline안에 해야 그 job은 유효하다.
deadline을 넘어선 시간대에 job을 선택하면 그것은 impossible하다.
#include <iostream>
#include <vector>
using namespace std;
vector<int> j, k;
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
    Schedule* s = new Schedule[n + 1];
    vector<int> deadline;
    vector<int> profit;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i].deadline;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i].profit;
    }
    for (int i = 1; i <= n; i++) //profit이 큰 순서대로 정렬한다.
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (s[i].profit < s[j].profit)
            {
                swap(s[i], s[j]);
            }
        }
    }
    schedule(n, s, j, k); //n은 회의 갯수,s는 구조체,j
    int sum = 0;
    //j가 feasible set이다.
    for (int i = 1; i < j.size(); i++)
    {
        sum = sum + s[j[i]].profit; //j배열에 순서대로 넣어줌.
    }
    cout << sum << "\n";
    for (int i = 1; i < j.size(); i++) //j배열에 순서가 job의 순서임.
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
        k.resize(j.size()); //만약 적절하지않다면 k를 원래대로 돌려놓음.
        copy(j.begin(), j.end(), k.begin());
        int cnt = 1;
        //i가 내가 넣어줄려는 job cnt만큼 증가시켜주고 그 자리에 넣어줌.
        //그 자리가 들어가야할 위치임 k에 들어가는 job은 데드라인이 작은순서대로 정렬되어있음. deadline이 같더라더 그 이익이 더 작기때문에 후순위에 배치됨.
         //s[i]의 deadline보다 k배열에 deadline이 커질때 그 자리에 넣어줌. 같으면 넣어주면 안됨. 후순위로 배치해야함.
        while (cnt < k.size() && s[k[cnt]].deadline <= s[i].deadline)
            cnt++;
        k.insert(k.begin() + cnt, i); //해당위치에 job을 넣어줌.
        if (is_feasible(k, s)) //지금 넣어준 job의 집합이 적절한지 체크함.
        {
            j.resize(k.size()); //적절하면 j에 k를 복사.
            copy(k.begin(), k.end(), j.begin());
        }
    }
}
bool is_feasible(vector<int>& k, Schedule* s)
{
    for (int i = 1; i < k.size(); i++)
    {
        if (i > s[k[i]].deadline) //job이 위치한 i와 job에 deadline을 비교해서 만약 i가 크다면 그 작업은 유효하지않다.
            return false;
    }
    return true;
}
*/