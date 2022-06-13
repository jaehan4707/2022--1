/*
각 정점에 대한 bound값이 있음. 그 값은 바로 그 정점에서 최소비용으로 갈 수있는 경로의 가중치
그렇게 정점마다 bound값을 뽑아서 다 더 하면 그 값이 여행경로 길이의 하한일것이다.
이 길이의 합과 같은 여행경로가 무조건 있다는 뜻은 아니고 이 보다 더 짧은 경로가 있을 수 없다는 뜻이다.
여행경로의 하한은 이미 뽑힌 값은 제외하고 그 출발지에 따른 bound값이다.
출발지에서 부터 하나씩 방문해서 bound값이 가장 작고 아래까지 탐색을 안한 것ㅂ ㅜ터 탐색함.
*/

/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#define INF 999
using namespace std;
int G, v, StartV = 2;
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
void print(node_pointer a);
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
    for (int i = 1; i <= G; i++) //인접행렬이기때문에 자기자신은 0으로 초기화함.
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
int length(vector<int>& path) //경로의 길이를 구하는 함수.
{
    vector<int>::iterator it;
    int len = 0;
    for (it = path.begin(); it != path.end(); it++) // path의 경로를 넣고 경로 -> 다음 경로의 길이를 len에 계속 더해줌.
    {
        if (it != path.end() - 1) //만약 it이 path end-1일 경우 마지막 경로이기 때문에 it+1은 존재하지않는 경로이다.
            len += graph[*it][*(it + 1)];
    }
    return len;
}
int Bound(node_pointer V) //여행길이의 하한을 구하는 함수. 그 하한으로 pq를 구성하고 bound값이 낮은 것을 우선적으로 탐색함.
//만약 모든 도시를 도착한 상황에서 bound는 그 경로의 lenth이다.
{
    int lower = length(V->path); //간 경로까지의 길이를 더해줌.
    for (int i = 1; i <= G; i++)
    {
        // i는 내가 출발하는 도시다.
        // i에서 다른 도시로 진출한지 안한지를 체크함. 만약 {1,2}라면 1은 제외시키지만 2는 제외를 안시킴.
        //왜냐하면 2는 아무 도시로든 edge를 뻗지 않았기때문이다.
        if (hasOutgoing(i, V->path)) // true면 내가 이미 경로가 정해졌다. 제외시켜줌.
            continue;
        int min = INF;
        for (int j = 1; j <= G; j++)
        {
            if (i == j) //자기 자신으로 가는 경우는 제외함.
                continue;
            if (j == StartV & i == V->path[V->path.size() - 1])
                //내가 모든 도시를 방문하지 않은 상황이라고 가정할때 j는 내가 방문할 도시고 i는 내가 출발할 도시이다.
                //만약 모든 도시를 방문하지 않은 상황에서 마지막경로에서 1로 가면 안된다. 1(출발점)으로 간다는 것은
                //맨 마지막 경우이기때문이다. 그래도 모든 도시를 방문한 상황에서는 출발점으로 돌아가야하는것아니냐?
                //라는 의문이 들 수 있는데 모든 도시를 방문한 상황에서는 위의 for문을 돌지않고 바로 bound값은 path의 길이가 된다.
                continue;
            if (hasIncoming(j, V->path)) // hasIncoming은 내가 밟을 도시를 체크한다. 만약 내가 밟을 도시가 path안에 있다면 그 도시는 제외시켜야함.
                continue;
            if (min > graph[i][j]) //만약 min값보다 작다면 min값을 넣어줌.
                min = graph[i][j];
        }
        lower += min; // path + min값을 계속 넣어줌. 모든 방문이 끝날떄까지.
    }
    return lower;
}
bool hasOutgoing(int v, vector<int>& path) // v가 다른 도시를 방문햇느냐?를 찾는것 경로가 2개가 될 수는 없기 떄문에 이미
//경로를 뻗엇다면 그 도시는 제외시켜줘야함. true면 뻗었다는 뜻, false는 뻗지않았다는 뜻.
{
    vector<int>::iterator it;
    for (it = path.begin(); it != path.end() - 1; it++) //마지막 지점은 1번으로 뻗어야하기때문에 제외시켜줌.
        if (*it == v)
            return true;
    return false;
}

bool hasIncoming(int v, vector<int>& path) // v가 방문된 도시인지 체크함. 두번 방문할 수 없기 떄문에 만약 있다면 true 없다면 false를 return
{
    vector<int>::iterator it;
    for (it = path.begin() + 1; it != path.end(); it++) //시작지점은 방문은 했지만 한번더 방문해야되기때문에  제외시켜줌.
        if (*it == v)
            return true;
    return false;
}

void travel2(vector<int>& opttour, int& minlength)
{
    priority_queue<node_pointer, vector<node_pointer>, cmp> pq; // path,bound값으로 나눠야함.
    node_pointer a, b;
    a = (node_pointer)malloc(sizeof(nodetype));
    b = (node_pointer)malloc(sizeof(nodetype));

    minlength = INF;
    b->level = 0;

    b->path.push_back(StartV); // StartV는 출발점을 의미함.
    b->bound = Bound(b);       //

    cout << b->level << " " << b->bound << " ";
    print(b);
    pq.push(b);
    while (!pq.empty())
    {
        b = pq.top();
        pq.pop();
        if (b->bound < minlength) // bound값이 minlength보다 작아야 유망하다.
        {
            // a->level = b->level + 1; // a를 b의 자식노드로 놓음.
            for (int i = 1; i <= G; i++)
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
                if (a->level == G - 2) // a->level이 도시개수-2개라는 뜻은 마지막경로빼고 다 결정된 상황
                //마지막 경로는 굳이 구할필요없이 방문안한 도시를 자동으로 넣어주면 되는것. G-2인 이유는 출발점의 방문은 level이 0이므로
                {
                    for (int k = 1; k <= G; k++) // 1부터 k까지해서 간경로는 재끼고 안간경로를  당연히 가야하므로 푸쉬해줌.
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
                    a->path.push_back(StartV); //마지막은 1로 돌아가야함. //1은 start로 바꾸자.
                    if (length(a->path) < minlength)
                    {
                        minlength = length(a->path);
                        ;
                        opttour.assign(a->path.begin(), a->path.end());
                    }
                    a->bound = Bound(a);
                    if (correct_path(a)) //만약 path에서 적절한 경로인지 따져줌.
                    {
                        cout << a->level << " " << a->bound << " ";
                        print(a);
                    }
                    else  //적절한 경로가 아닐때는 INF를 출력
                    {
                        a->bound = Bound(a);
                        cout << a->level << " "
                            << "INF"
                            << " ";
                        print(a);
                    }
                }
                else //a->level이 G-2보다 작을때는 직접 찾아줘야함.
                {
                    bool flag = true;
                    if (correct_path(a)) //이상한 경로가 아니라면 그대로 bound값을 넣어줌.
                    {
                        a->bound = Bound(a);
                        cout << a->level << " " << a->bound << " ";
                        print(a);
                    }
                    else //이상한 경로라면 INF를 넣어줌.
                    {
                        a->bound = Bound(a);
                        cout << a->level << " "
                            << "INF"
                            << " ";
                        print(a);
                    }
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
void print(node_pointer a)
{

    for (int x = 0; x < a->path.size(); x++)
    {
        if (x < a->path.size() - 1)
            cout << a->path[x] << " ";
        else
            cout << a->path[x];
    }
    cout << endl;
}
*/