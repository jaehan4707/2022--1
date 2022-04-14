/*
�ּҽ����� ũ�罺Į �˰����̿�.
���� �κ������� ���� ==dset
edge�� ����ġ���� ������.
1.�� ���� edge�� vertex���� ����.
2.�� vertex�� �κ������� ���������� ����
1,2�� �ݺ�
3.���� ��ġ�� �κ������� �ΰ� �� �̹� �������ִٸ� discard �ϰ� ����  edge �������� �Ѿ
���� ������ ũ�Ⱑ n-1�� �� �� ���� �ݺ��� �ֳ��ϸ� edge���� n-1�������ϱ⶧����
init�Լ��� �κ������� �ʱ�ȭ��. �����ϱ� ���ϰ� �׳� ���� vertex������ �ʱ�ȭ��.
p=find(i)�� p�� �ε��� i�� �����ϰ� �ִ� ������ ����Ű����
merge(p,q)�� p�� q�� ����Ű�� ������ ��ħ.
equal(p,q)�� �� ������ ������������ �˻��ϴ� �Լ�
*/
#define INF 9999999
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef struct edge
{
    int u, v, w;
} edge;
vector<int> dset;
void init(int n);
int find(int n);
void merge(int p, int q);
void kruskal(int n, int m, vector<int>& w, vector<pair<int, int>>& F, edge* e); // F�� ���� ���
int main()
{
    int n, m, s, f, w, min;
    cin >> n >> m;
    edge* e = new edge[m];
    //e=m;
   // edge *e = (edge *)malloc(sizeof(edge) * m);

    vector<vector<int>> p(n + 1, vector<int>(n + 1, INF));
    vector<int> weight;
    vector<pair<int, int>> F;
    for (int i = 0; i < m; i++)
    {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }

    for (int i = 0; i < m; i++) //����ġ ���� �����ϱ�
    {
        min = e[i].w;
        for (int j = i; j < m; j++)
        {
            if (min > e[j].w)
            {
                min = e[j].w;
                swap(e[i], e[j]);
            }
        }
    }
    kruskal(n, m, weight, F, e);
    for (int i = 0; i < F.size(); i++)
    {
        int u = F[i].first, v = F[i].second;
        if (i < F.size() - 1)
            cout << u << " " << v << " " << weight[i] << endl;
        else
            cout << u << " " << v << " " << weight[i];
    }
}
void init(int n)
{
    dset.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        dset[i] = i;
    }
}
int find(int n)
{
    while (dset[n] != n)
    {
        n = dset[n];
    }
    return n;
}
void merge(int p, int q)
{
    dset[p] = q;
}
void kruskal(int n, int m, vector<int>& w, vector<pair<int, int>>& F, edge* e) // F�� ���� ���
{
    int p, q, num = 0;
    pair<int, int> a;
    init(n);
    while (F.size() < n - 1) // ��ʹ��ذ�
    {
        p = find(e[num].u); //��������
        q = find(e[num].v);
        if (p != q) //����������
        {
            merge(p, q);
            a.first = e[num].u;
            a.second = e[num].v;
            w.push_back(e[num].w);
            F.push_back(a);
        }
        num++;
    }
}