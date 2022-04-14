/*
directed graph
v1을 첫시작으로 뽑음.v1에서 가장 가까운 vertex를 선정해서 Y집합에 넣음.
Y집합(v1, v2) V- Y(v3, v4, v5) 그 다음 Y집합에서 가까운 것과 V - Y가까운것 대신 Y집합 노드를경유하는 결과값으로 해야함.
prim알고리즘과 dijkstra알고리즘은 비슷하다.차이는 nearest, distance 배열을 쓰는 prim이지만
dijkstra는 touch배열과 length배열을 사용한다.
touch배열은 v[i]->v1로 가는데 가까운 노드
length배열은 y집합에서 vi 까지 최소비용 경로
*/
#define INF 999999
#include <iostream>
#include <vector>

using namespace std;
typedef vector<vector<int>> matrix;
void dijkstra(int n, matrix& t, vector<pair<int, int>>& F);
int find(vector<int>& v, int n);
int n, m;
vector<int> touch(n + 1), length(n + 1);
int main()
{
    cin >> n >> m;
    touch.resize(n + 1, 0);
    length.resize(n + 1, 0);
    matrix a(n + 1, vector<int>(n + 1, INF));
    vector<pair<int, int>> b;
    vector<int> weight;
    for (int i = 0; i < m; i++)
    {
        int s, f, w;
        cin >> s >> f >> w;
        a[s][f] = w;
    }
    dijkstra(n, a, b);
    for (int i = 0; i < b.size(); i++)
    {
        int u = b[i].first, v = b[i].second;

        cout << u << " " << v << " " << a[u][v] << endl;
    }

    int number, aa;
    cin >> number;
    for (int i = 0; i < number; i++)
    {
        // touch값이 1이 될때까지 넘김
        cin >> aa;
        vector<int> bb;
        while (aa != 1)
        {
            bb.push_back(aa);
            aa = touch[aa];
        }
        bb.push_back(1);
        for (int i = bb.size() - 1; i >= 0; i--)
        {
            if (i > 0)
                cout << bb[i] << " ";
            else
                cout << bb[i];
        }
        cout << endl;
    }
}
void dijkstra(int n, matrix& t, vector<pair<int, int>>& F)
{
    int vnear, min;
    F.clear();
    for (int i = 2; i <= n; i++) // v1을 고정시작점으로 하기 때문이다.
    {
        touch[i] = 1;
        length[i] = t[1][i];
    }
    for (int i = 2; i <= n; i++)
    {
        if (i < n)
            cout << touch[i] << " ";
        else
            cout << touch[i];
    }
    cout << endl;

    for (int i = 0; i < n - 1; i++)
    {
        min = INF;
        for (int i = 2; i <= n; i++)
        {
            if (0 <= length[i] && length[i] < min)
            {
                min = length[i];
                vnear = i;
            }
        }
        F.push_back(make_pair(touch[vnear], vnear)); //간선을 f에 넣어주기
        // find(touch, vnear);
        for (int i = 2; i <= n; i++)
        {
            if (length[i] > length[vnear] + t[vnear][i]) //기존 y조합에서의 dintance와 추가된 v간의 거리 계산
            {
                length[i] = length[vnear] + t[vnear][i];
                touch[i] = vnear;
            }
        }
        for (int i = 2; i <= n; i++)
        {
            if (i < n)
                cout << touch[i] << " ";
            else
                cout << touch[i];
        }
        cout << endl;
        length[vnear] = -1;
        // num++;
    }
}
