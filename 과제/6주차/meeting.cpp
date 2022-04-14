/*
탐욕법, 가장 작은 런닝타임을 가진 것 부터 출발.
for문 돌리고 전타임 끝나는시간과 k번째 시작하는 시간이 크거나 같으면 k를 넣어주고 또 다시 반복문
최선의 선택을 계속 하기 때문에 최선일 수 밖에없다.
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