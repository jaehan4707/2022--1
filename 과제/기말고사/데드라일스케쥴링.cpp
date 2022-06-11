/*
deadline �����층 ����
�ð��� �ִ��� ���Ծ��鼭 ������ �ִ�� �ؾ��Ѵ�.
������� ��ġ�ؾ� ���� �ð��� ���鼭 �ִ����� ȿ���� �� ��������?
������ job���� deadline�� �����Ѵ�. deadline�ȿ� �ؾ� �� job�� ��ȿ�ϴ�.
deadline�� �Ѿ �ð��뿡 job�� �����ϸ� �װ��� impossible�ϴ�.
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
    for (int i = 1; i <= n; i++) //profit�� ū ������� �����Ѵ�.
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (s[i].profit < s[j].profit)
            {
                swap(s[i], s[j]);
            }
        }
    }
    schedule(n, s, j, k); //n�� ȸ�� ����,s�� ����ü,j
    int sum = 0;
    //j�� feasible set�̴�.
    for (int i = 1; i < j.size(); i++)
    {
        sum = sum + s[j[i]].profit; //j�迭�� ������� �־���.
    }
    cout << sum << "\n";
    for (int i = 1; i < j.size(); i++) //j�迭�� ������ job�� ������.
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
        k.resize(j.size()); //���� ���������ʴٸ� k�� ������� ��������.
        copy(j.begin(), j.end(), k.begin());
        int cnt = 1;
        //i�� ���� �־��ٷ��� job cnt��ŭ ���������ְ� �� �ڸ��� �־���.
        //�� �ڸ��� ������ ��ġ�� k�� ���� job�� ��������� ����������� ���ĵǾ�����. deadline�� ������� �� ������ �� �۱⶧���� �ļ����� ��ġ��.
         //s[i]�� deadline���� k�迭�� deadline�� Ŀ���� �� �ڸ��� �־���. ������ �־��ָ� �ȵ�. �ļ����� ��ġ�ؾ���.
        while (cnt < k.size() && s[k[cnt]].deadline <= s[i].deadline)
            cnt++;
        k.insert(k.begin() + cnt, i); //�ش���ġ�� job�� �־���.
        if (is_feasible(k, s)) //���� �־��� job�� ������ �������� üũ��.
        {
            j.resize(k.size()); //�����ϸ� j�� k�� ����.
            copy(k.begin(), k.end(), j.begin());
        }
    }
}
bool is_feasible(vector<int>& k, Schedule* s)
{
    for (int i = 1; i < k.size(); i++)
    {
        if (i > s[k[i]].deadline) //job�� ��ġ�� i�� job�� deadline�� ���ؼ� ���� i�� ũ�ٸ� �� �۾��� ��ȿ�����ʴ�.
            return false;
    }
    return true;
}
*/