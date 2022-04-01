/*
#include <iostream>
#include <vector>
#define INF 999
using namespace std;
void printary(int row, int col, vector<vector<int>>& ary);
void path(vector<vector<int>>& P, int u, int v, vector<int>& p);
void floyd(int n, vector<vector<int>>& graph, vector<vector<int>>& D, vector<vector<int>>& P);
void makeary(int row, int col, vector<vector<int>>& ary);
int main()
{
    // D, P
    int N, M, u, v, w, num, start, end;
    cin >> N >> M;
    vector<vector<int>> graph(N + 1, vector<int>(N + 1, -1));
    vector<vector<int>> D(N + 1, vector<int>(N + 1, -1));
    vector<vector<int>> P(N + 1, vector<int>(N + 1, -1));
    vector<int> p(1);
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v >> w;
        graph[u][v] = w;
    }
    makeary(N, N, graph);
    floyd(N, graph, D, P);
    printary(N, N, D); // D배열출력
    cout << endl;
    printary(N, N, P);
    cout << endl;
    cin >> num; //정점개수
    for (int i = 0; i < num; i++) //정점입력
    {
        cin >> start >> end;
        if (D[start][end] == 999)
        {
            if (i < num - 1)
                cout << "NONE" << endl;
            else
                cout << "NONE";
            continue;
        }
        p[0] = start;
        path(P, start, end, p);
        p.push_back(end);
        for (int j = 0; j < p.size(); j++)
        {
            if (p[j] != 0)
            {
                if (j < p.size() - 1)
                    cout << p[j] << " ";
                else
                    cout << p[j];
            }
        }
        if (i < num - 1)
            cout << "\n";
        p.resize(1, 0);
    }
}
void makeary(int row, int col, vector<vector<int>>& ary)
{
    for (int i = 1; i <= row; i++) // 그래프 출력
    {
        for (int j = 1; j <= col; j++)
        {
            if (i == j)
            {
                ary[i][j] = 0;
            }
            else if (ary[i][j] == -1)
            {
                ary[i][j] = INF;
            }
        }
    }
}
void printary(int row, int col, vector<vector<int>>& ary)
{
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            if (j < col)
                cout << ary[i][j] << " ";
            else
                cout << ary[i][j];
        }
        if (i < row)
            cout << endl;
    }
}
void floyd(int n, vector<vector<int>>& graph, vector<vector<int>>& D, vector<vector<int>>& P)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            D[i][j] = graph[i][j];
            P[i][j] = 0;
        }
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (D[i][j] > D[i][k] + D[k][j])
                {
                    D[i][j] = D[i][k] + D[k][j];
                    P[i][j] = k;
                }
            }
        }
    }
}
void path(vector<vector<int>>& P, int u, int v, vector<int>& p)
{
    int k = P[u][v];
    if (k != 0)
    {
        path(P, u, k, p);
        p.push_back(k);
        path(P, k, v, p);
    }
}
*/