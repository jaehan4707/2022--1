/*
Spanning Tree�� connected,weighted,undirected graph�� ������ ������.
���� weight���� ���� ��η� �������Ѵ�. Spanning tree�� edge�� ���� �׷����� ������ ���� -1���̴�.
���� �˰����� �̿�
���� �˰����� �������� v1���� ���صд�.  V1�� Y����, V-Y�� Y'���� �����Ѵ�.
Y���տ��� V-Y���� �ּ����� edge�� ã�� edge�� �迭�� �߰����ְ� �׶� vertex�� Y���տ� �߰����ش�. �̷� ������ �ݺ��ؼ�
Y�� V���հ� �������� �׸��д�.
nearest �迭
F���տ� �߰��Ǵ� ������ ����ϱ�
ù��° ������ ��߷� �����ϴ� ����
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
    vector<int> nearest(n + 1), distance(n + 1); //nearest�� vi�� ���� ����� Y�� ���� vertex 
    //distance�� vi�� nearest[i]�� �ε����� �� ���� �����ϴ� ���߼��� ��ġ
    for (int i = 2; i <= n; i++) //v1�� ���������� ��������� �ʱ⼳�� 
    {
        nearest[i] = 1;
        distance[i] = w[1][i];
        if (i < n)
            cout << nearest[i] << " ";
        else
            cout << nearest[i];
    }
    cout << endl;

    for (int i = 0; i < n - 1; i++) //�����ذ�
    {
        min = INF;
        for (int j = 2; j <= n; j++) //1�� ������ 2������ ���� ����� j�� ã��
        {
            if (0 <= distance[j] && distance[j] < min)
            {
                min = distance[j];
                vnear = j;
            }
        }
        f.push_back(make_pair(vnear, nearest[vnear])); // edge vnear->nearest[vnear]�� �־������. vnear->nearest[vnerar] , �׶� ����ġ.
        distance[vnear] = -1; //�̹� �湮�Ѱ��� -1 ó��
        for (int j = 2; j <= n; j++)
        {
            if (distance[j] > w[j][vnear]) //���� ���տ����� distance�� vertex�� �߰��� ���տ� distance�� ����. �߰��� distance�� �۴ٸ� ditance�� �ٲ���
            {
                distance[j] = w[j][vnear];
                nearest[j] = vnear;  //�׶��� near���� vnear ������ �Ű���.
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