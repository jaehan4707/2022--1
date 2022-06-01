/*
각 정점에 대한 bound값이 있음. 그 값은 바로 그 정점에서 최소비용으로 갈 수있는 경로의 가중치
그렇게 정점마다 bound값을 뽑아서 다 더 하면 그 값이 여행경로 길이의 하한일것이다.
이 길이의 합과 같은 여행경로가 무조건 있다는 뜻은 아니고 이 보다 더 짧은 경로가 있을 수 없다는 뜻이다.
여행경로의 하한은 이미 뽑힌 값은 제외하고 그 출발지에 따른 bound값이다.
출발지에서 부터 하나씩 방문해서 bound값이 가장 작고 아래까지 탐색을 안한 것ㅂ ㅜ터 탐색함.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#define INF 999
using namespace std;
int G, v;
vector<vector<int>> graph;
vector<int> bound;
typedef vector<int> ordered_set;
typedef struct node* node_pointer;
typedef struct node
{
    int level;
    vector<int> path;
    int bound;
} nodetype;
int length(vector<int>& path);
int Bound(node_pointer V);
node_pointer create_node(int Level, vector<int>& path);
bool hasIncoming(int v, vector<int>& path);
bool hasOutgoing(int v, vector<int>& path);
void travel2(vector<int>& opttour, int& minlength);
bool isIn(int i, vector<int>& path);
bool correct_path(node_pointer a);
vector<int> seq;
int shortpath = INF;
int start = 1;
struct cmp
{
    bool operator()(node_pointer a, node_pointer b) // bound가 작은걸 top으로 두고싶음.
    {
        return a->bound > b->bound;
    }
};
int main()
{
    cin >> G >> v;
    graph.resize(G + 1, vector<int>(G + 1, INF));
    bound.resize(G + 1);
    for (int i = 0; i < v; i++)
    {
        int s, f, w;
        cin >> s >> f >> w;
        graph[s][f] = w;
    }
    for (int i = 1; i <= G; i++)
    {
        graph[i][i] = 0;
    }
    travel2(seq, shortpath);

    cout << shortpath << endl;
    for (int i = 0; i < seq.size(); i++)
    {
        if (i < seq.size() - 1)
            cout << seq[i] << " ";
        else
            cout << seq[i];
    }
}
int length(vector<int>& path)
{
    vector<int>::iterator it;
    int len = 0;
    for (it = path.begin(); it != path.end(); it++)
    {
        if (it != path.end() - 1)
            len += graph[*it][*(it + 1)];
    }
    return len;
}
int Bound(node_pointer V)
{
    int lower = length(V->path);
    for (int i = 1; i <= G; i++)
    {
        if (hasOutgoing(i, V->path)) //i 가 v->apth에 있는지 없는지 체크해서 true면 continue false면 진행
            continue;
        int min = INF;
        for (int j = 1; j <= G; j++)
        {
            if (i == j)
                continue;
            if (j == 1 & i == V->path[V->path.size() - 1])
                continue;
            if (hasIncoming(j, V->path))
                continue;
            if (min > graph[i][j])
                min = graph[i][j];
        }
        lower += min;
    }
    return lower;
}
bool hasOutgoing(int v, vector<int>& path)  //경로가 있다면 ture 경로가 없다면 false가 반환됨.
{
    vector<int>::iterator it;
    for (it = path.begin(); it != path.end() - 1; it++)
        if (*it == v)
            return true;
    return false;
}

bool hasIncoming(int v, vector<int>& path)
{
    vector<int>::iterator it;
    for (it = path.begin() + 1; it != path.end(); it++)
        if (*it == v)
            return true;
    return false;
}

void travel2(vector<int>& opttour, int& minlength)
{
    priority_queue<node_pointer, vector<node_pointer>, cmp> pq; // path,bound값으로 나눠야함.
    node_pointer a, b;
    a = (node_pointer)malloc(sizeof(node));
    b = (node_pointer)malloc(sizeof(node));

    minlength = INF;
    b->level = 0;

    b->path.push_back(1); //왜 오류나지
    b->bound = Bound(b);

    cout << b->level << " " << b->bound << " ";
    for (int i = 0; i < b->path.size(); i++)
    {
        if (i < b->path.size() - 1)
            cout << b->path[i] << " ";
        else
            cout << b->path[i];
    }
    cout << endl;
    pq.push(b);
    while (!pq.empty())
    {
        b = pq.top();
        pq.pop();
        if (b->bound < minlength)
        {
            // a->level = b->level + 1; // a를 b의 자식노드로 놓음.
            for (int i = 2; i <= G; i++)
            {
                if (isIn(i, b->path) == 0) // isIn값이 0이면 i가 경로에 이미 있다는 소리고 1이면 i가 경로에 없다는 소리다.
                {
                    continue; // 만약 i가 b의 경로에 있다ㅕㅁㄴ?
                }
                a = create_node(b->level + 1, b->path); //여가서 5일때 터짐.
                a->level = b->level + 1;
                a->path = b->path;
                a->bound = 0;
                a->path.push_back(i);
                if (a->level == G - 2) //마지막 정점일때 a의 레벨은 0부터 1,2,3,4 G=5 3개를 방문하면 나머지 하나는 정해짐
                {
                    for (int k = 2; k <= G; k++) // 1부터 k까지해서 간경로는 재끼고 안간경로를  당연히 가야하므로 푸쉬해줌.
                    {
                        if (isIn(k, a->path) == 0) // 0이면 경로 x 1이면 경로 o
                        {
                            continue;
                        }
                        else
                        {
                            a->path.push_back(k);
                        }
                    }
                    a->path.push_back(1); //마지막은 1로 돌아가야함.
                    if (length(a->path) < minlength)
                    {
                        minlength = length(a->path);
                        ;
                        opttour.assign(a->path.begin(), a->path.end());
                    }
                    a->bound = Bound(a);
                    if (correct_path(a)) //여기도 경로가 없는거였다면 구분해줘야함. 0이면 없고 1이면 잇음
                    {
                        cout << a->level << " " << a->bound << " ";
                        for (int x = 0; x < a->path.size(); x++)
                        {
                            if (x < a->path.size() - 1)
                                cout << a->path[x] << " ";
                            else
                                cout << a->path[x];
                        }
                        cout << endl;
                    }
                    else
                    {
                        a->bound = Bound(a);
                        cout << a->level << " "
                            << "INF"
                            << " ";
                        for (int x = 0; x < a->path.size(); x++)
                        {
                            if (x < a->path.size() - 1)
                                cout << a->path[x] << " ";
                            else
                                cout << a->path[x];
                        }
                        cout << endl;
                    }
                }
                else
                {
                    bool flag = true;
                    if (correct_path(a)) //이상한 경로가 아니라면 그대로 bound값을 넣어줌.
                    {
                        a->bound = Bound(a);
                        cout << a->level << " " << a->bound << " ";
                        for (int x = 0; x < a->path.size(); x++)
                        {
                            if (x < a->path.size() - 1)
                                cout << a->path[x] << " ";
                            else
                                cout << a->path[x];
                        }
                        cout << endl;
                    }
                    else //이상한 경로라면 bound를 넣어줌.
                    {
                        a->bound = Bound(a);
                        cout << a->level << " "
                            << "INF"
                            << " ";
                        for (int x = 0; x < a->path.size(); x++)
                        {
                            if (x < a->path.size() - 1)
                                cout << a->path[x] << " ";
                            else
                                cout << a->path[x];
                        }
                        cout << endl;
                    }
                    // path가 있는지 없는지 확인 만약 path가 있다면 bound는 bound로 값을 구해주고 아니면 INF를 넣어줌.
                    if (a->bound < minlength) // bound가 초기화 된 minlength보다 작다면 넣어준다.
                        pq.push(a);
                }
            }
        }
    }
}
bool correct_path(node_pointer a) // 1이면 경로가 있고 0이면 경로가 없다.
{
    bool flag;
    flag = true;
    for (int x = 1; x < a->path.size(); x++)
    {
        if (graph[a->path[x - 1]][a->path[x]] == INF) //경로가 없다면
        {
            flag = false;
        }
    }
    return flag;
}
bool isIn(int i, vector<int>& path) // path안에 i가 있냐 없냐를 따짐.
{
    vector<int>::iterator it;
    // cout<<1;
    bool opt = true;
    for (int j = 0; j <= path.size() - 1; j++)
    {
        if (i == path[j]) //같은게 있으면
            return false;
    }
    // cout<<"opt는" << opt<<endl;
    return true;
}
node_pointer create_node(int Level, vector<int>& path)
{
    node_pointer temp = (node_pointer)malloc(sizeof(node) * G);
    return temp;
}