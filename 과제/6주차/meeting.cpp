/*
Ž���, ���� ���� ����Ÿ���� ���� �� ���� ���.
for�� ������ ��Ÿ�� �����½ð��� k��° �����ϴ� �ð��� ũ�ų� ������ k�� �־��ְ� �� �ٽ� �ݺ���
�ּ��� ������ ��� �ϱ� ������ �ּ��� �� �ۿ�����.
*/
#include <iostream>
#include <vector>

using namespace std;
typedef struct room
{
    int s;
    int f;
} room;
int main()
{
    int n;
    cin >> n;
    vector<room> r(n);

    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        r[i].s = u;
        r[i].f = v;
    }

    // cout<<1;
    int idx = 0, num = 1;
    vector<pair<int, int>> d;
    d.push_back(make_pair(r[idx].s, r[idx].f));
    for (int i = 1; i < n; i++)
    {
        if (r[idx].f <= r[i].s)
        {
            d.push_back(make_pair(r[i].s, r[i].f));
            idx = i;
            num++;
        }
    }
    cout << num << endl;
    for (int i = 0; i < d.size(); i++)
    {
        if (i < d.size() - 1)
            cout << d[i].first << " " << d[i].second << endl;
        else
            cout << d[i].first << " " << d[i].second;
    }
}