/*
최소신장비용 크루스칼 알고리즘이용.
서로 부분집합을 만듬 ==dset
edge를 가중치별로 정렬함.
1.젤 낮은 edge를 vertex끼리 연결.
2.그 vertex의 부분집합을 합집합으로 연결
1,2을 반복
3.만약 합치는 부분집합이 두개 다 이미 합쳐져있다면 discard 하고 다음  edge 집합으로 넘어감
간선 집합의 크기가 n-1이 될 때 까지 반복함 왜냐하면 edge수는 n-1개여야하기때문에
init함수는 부분집합을 초기화함. 이해하기 편하게 그냥 각자 vertex값으로 초기화함.
p=find(i)는 p가 인덱스 i를 포함하고 있는 집합을 가리키게함
merge(p,q)는 p와 q가 가리키는 집합을 합침.
equal(p,q)는 두 집합이 동일집합인지 검사하는 함수
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
void kruskal(int n, int m, vector<int>& w, vector<pair<int, int>>& F, edge* e); // F가 저장 노드
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

    for (int i = 0; i < m; i++) //가중치 별로 정렬하기
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
void kruskal(int n, int m, vector<int>& w, vector<pair<int, int>>& F, edge* e) // F가 저장 노드
{
    int p, q, num = 0;
    pair<int, int> a;
    init(n);
    while (F.size() < n - 1) // 사례미해결
    {
        p = find(e[num].u); //선택절차
        q = find(e[num].v);
        if (p != q) //적절성점검
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