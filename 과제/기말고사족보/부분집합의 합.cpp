//total�� ���� ���� �����Ŀ� ���ҵ��� ��ü������ �տ��� ���°�.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int n, W;
int sum = 0;
int total = 0;
int cnt = 0;
vector<int> seq;
vector<int> sub;
int cc;
void subset(int i, int weight, int total);
bool promising(int i, int weight, int total);
vector<int> include;
vector<string> str;
int big(int i, int j)
{
    return i > j;
}
int main()
{
    cin >> n >> W;
    // vector<int>sum(n, 0);
    sub.resize(n + 1);
    include.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> sub[i];
        total = total + sub[i];
    }
    sort(sub.begin() + 1, sub.end(), big);
    for (int i = 1; i <= sub.size() - 1; i++)
    {
        cout << sub[i] << " ";
    }
    cout << endl;
    subset(0, 0, total);
    cout << cnt << endl;
    /*
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == "")
            cout << endl;
        else
        {
            if (str[i + 1] == "")
                cout << str[i];
            else
                cout << str[i] << " ";
        }
    }
    */
    //cout << cc << endl;
}
void subset(int i, int weight, int total)
{
    if (promising(i, weight, total))
    {
        if (weight == W)
        {
            // cc++;
            cnt++;
            string ab = "";
            for (int j = 1; j <= i; j++)
            {
                if (include[j] == 1)
                    // ab += to_string(sub[j]);
                    // str[cnt].push_back(ab[j-1]);
                    str.push_back(to_string(sub[j]));
                // ab += to_string(sub[include[j]]); //ab�� �����.
                // str[cnt].push_back(to_string(include[i]));
                // cout << include[j] << " ";
                // str[cnt].push_back(ab);
            }
            str.push_back("");
        }
        else
        {
            include[i + 1] = true;                                  // ���ҰŶ�� ��
            subset(i + 1, weight + sub[i + 1], total - sub[i + 1]); //���߰� ���� �ܰ�� ���� ���� ��͸� Ż���Ѵٸ�

            include[i + 1] = false;                                 //�ȴ��Ѵٴ� ��.
            subset(i + 1, weight, total - sub[i + 1]);              //�ȴ��ϰ� ���� �ܰ�� ����
            if (i + 1 == 2)
            {
                //cout<<"�ȴ������ �˻�" << "" << weight<<"" << total<<endl;
            }
        }
        if (i + 1 == 3)
        {
            cout << "�˻�" << "" << weight << "" << total << endl;
        }
    }
    if (i + 1 == 3)
    {
        cout << "�˻�" << "" << weight << "" << total << endl;
    }
    // cc++;
}
bool promising(int i, int weight, int total)
{
    return (weight + total >= W) && (weight == W || weight + sub[i + 1] <= W);
    //���� ���� ���� weight���� weight��+ ���� weight���� total���� ���� ���Ϸ��� W���� �۴ٸ� �� ���ʿ䰡 ����.
    // ���� ���� ���� weight�� ���� ���ҷ��� weight�� W�� �Ѵ´ٸ� Ž������
}