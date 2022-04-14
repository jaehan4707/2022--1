/*
Spanning Tree는 connected,weighted,undirected graph의 성격을 가진다.
가장 weight값이 적은 경로로 만들어야한다. Spanning tree의 edge는 원래 그래프에 정점의 개수 -1개이다.
프림 알고리즘을 이용
프림 알고리즘은 시작점을 v1으로 정해둔다.  V1은 Y집합, V-Y를 Y'으로 정의한다.
Y집합에서 V-Y까지 최소한의 edge를 찾고 edge를 배열에 추가해주고 그때 vertex도 Y집합에 추가해준다. 이런 과정을 반복해서
Y가 V집합과 같아지면 그만둔다.
nearest 배열
F집합에 추가되는 간선을 출력하기
첫번째 정점을 출발로 선택하는 전략
*/

#include <iostream>
#include <vector>
#define INF 999999
using namespace std;
void prim(int n, vector<vector<int>>& w, vector<pair<int, int>>& f);
int main()
{
    int n, m, u, v, w;
    cin >> n >> m;
    vector<vector<int>> p(n + 1, vector<int>(n + 1, INF));
    vector<pair<int, int>> f(0);
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        p[u][v] = w, p[v][u] = w;
    }
    prim(n, p, f);
    for (int i = 0; i < f.size(); i++) // f.size==4
    {
        int u = f[i].first, v = f[i].second;
        if (i < f.size() - 1)
            cout << u << " " << v << " " << p[u][v] << endl;
        else
            cout << u << " " << v << " " << p[u][v];
    }
    return 0;
}
void prim(int n, vector<vector<int>>& w, vector<pair<int, int>>& f)
{
    int vnear, min;
    vector<int> nearest(n + 1), distance(n + 1); //nearest는 vi에 가장 가까운 Y에 속한 vertex 
    //distance는 vi와 nearest[i]가 인덱스인 두 마디를 연결하는 이중선의 가치
    for (int i = 2; i <= n; i++) //v1을 시작점으로 잡았을때의 초기설정 
    {
        nearest[i] = 1;
        distance[i] = w[1][i];
        if (i < n)
            cout << nearest[i] << " ";
        else
            cout << nearest[i];
    }
    cout << endl;

    for (int i = 0; i < n - 1; i++) //문제해결
    {
        min = INF;
        for (int j = 2; j <= n; j++) //1번 이후인 2번부터 가장 가까운 j를 찾음
        {
            if (0 <= distance[j] && distance[j] < min)
            {
                min = distance[j];
                vnear = j;
            }
        }
        f.push_back(make_pair(vnear, nearest[vnear])); // edge vnear->nearest[vnear]을 넣어줘야함. vnear->nearest[vnerar] , 그때 가중치.
        distance[vnear] = -1; //이미 방문한곳은 -1 처리
        for (int j = 2; j <= n; j++)
        {
            if (distance[j] > w[j][vnear]) //원래 집합에서의 distance와 vertex가 추가된 집합에 distance를 구함. 추가된 distance가 작다면 ditance를 바꿔줌
            {
                distance[j] = w[j][vnear];
                nearest[j] = vnear;  //그때의 near값을 vnear 값으로 옮겨줌.
            }
        }
        for (int j = 2; j <= n; j++)
        {
            if (j < n)
                cout << nearest[j] << " ";
            else
                cout << nearest[j];
        }
        cout << endl;
    }
}