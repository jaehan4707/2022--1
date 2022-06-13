/*
�� ������ ���� bound���� ����. �� ���� �ٷ� �� �������� �ּҺ������ �� ���ִ� ����� ����ġ
�׷��� �������� bound���� �̾Ƽ� �� �� �ϸ� �� ���� ������ ������ �����ϰ��̴�.
�� ������ �հ� ���� �����ΰ� ������ �ִٴ� ���� �ƴϰ� �� ���� �� ª�� ��ΰ� ���� �� ���ٴ� ���̴�.
�������� ������ �̹� ���� ���� �����ϰ� �� ������� ���� bound���̴�.
��������� ���� �ϳ��� �湮�ؼ� bound���� ���� �۰� �Ʒ����� Ž���� ���� �ͤ� ���� Ž����.
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
    bool operator()(node_pointer a, node_pointer b) // bound�� ������ top���� �ΰ����.
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
    for (int i = 1; i <= G; i++) //��������̱⶧���� �ڱ��ڽ��� 0���� �ʱ�ȭ��.
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
int length(vector<int>& path) //����� ���̸� ���ϴ� �Լ�.
{
    vector<int>::iterator it;
    int len = 0;
    for (it = path.begin(); it != path.end(); it++) // path�� ��θ� �ְ� ��� -> ���� ����� ���̸� len�� ��� ������.
    {
        if (it != path.end() - 1) //���� it�� path end-1�� ��� ������ ����̱� ������ it+1�� ���������ʴ� ����̴�.
            len += graph[*it][*(it + 1)];
    }
    return len;
}
int Bound(node_pointer V) //��������� ������ ���ϴ� �Լ�. �� �������� pq�� �����ϰ� bound���� ���� ���� �켱������ Ž����.
//���� ��� ���ø� ������ ��Ȳ���� bound�� �� ����� lenth�̴�.
{
    int lower = length(V->path); //�� ��α����� ���̸� ������.
    for (int i = 1; i <= G; i++)
    {
        // i�� ���� ����ϴ� ���ô�.
        // i���� �ٸ� ���÷� �������� �������� üũ��. ���� {1,2}��� 1�� ���ܽ�Ű���� 2�� ���ܸ� �Ƚ�Ŵ.
        //�ֳ��ϸ� 2�� �ƹ� ���÷ε� edge�� ���� �ʾұ⶧���̴�.
        if (hasOutgoing(i, V->path)) // true�� ���� �̹� ��ΰ� ��������. ���ܽ�����.
            continue;
        int min = INF;
        for (int j = 1; j <= G; j++)
        {
            if (i == j) //�ڱ� �ڽ����� ���� ���� ������.
                continue;
            if (j == StartV & i == V->path[V->path.size() - 1])
                //���� ��� ���ø� �湮���� ���� ��Ȳ�̶�� �����Ҷ� j�� ���� �湮�� ���ð� i�� ���� ����� �����̴�.
                //���� ��� ���ø� �湮���� ���� ��Ȳ���� ��������ο��� 1�� ���� �ȵȴ�. 1(�����)���� ���ٴ� ����
                //�� ������ ����̱⶧���̴�. �׷��� ��� ���ø� �湮�� ��Ȳ������ ��������� ���ư����ϴ°;ƴϳ�?
                //��� �ǹ��� �� �� �ִµ� ��� ���ø� �湮�� ��Ȳ������ ���� for���� �����ʰ� �ٷ� bound���� path�� ���̰� �ȴ�.
                continue;
            if (hasIncoming(j, V->path)) // hasIncoming�� ���� ���� ���ø� üũ�Ѵ�. ���� ���� ���� ���ð� path�ȿ� �ִٸ� �� ���ô� ���ܽ��Ѿ���.
                continue;
            if (min > graph[i][j]) //���� min������ �۴ٸ� min���� �־���.
                min = graph[i][j];
        }
        lower += min; // path + min���� ��� �־���. ��� �湮�� ����������.
    }
    return lower;
}
bool hasOutgoing(int v, vector<int>& path) // v�� �ٸ� ���ø� �湮�޴���?�� ã�°� ��ΰ� 2���� �� ���� ���� ������ �̹�
//��θ� �����ٸ� �� ���ô� ���ܽ��������. true�� �����ٴ� ��, false�� �����ʾҴٴ� ��.
{
    vector<int>::iterator it;
    for (it = path.begin(); it != path.end() - 1; it++) //������ ������ 1������ ������ϱ⶧���� ���ܽ�����.
        if (*it == v)
            return true;
    return false;
}

bool hasIncoming(int v, vector<int>& path) // v�� �湮�� �������� üũ��. �ι� �湮�� �� ���� ������ ���� �ִٸ� true ���ٸ� false�� return
{
    vector<int>::iterator it;
    for (it = path.begin() + 1; it != path.end(); it++) //���������� �湮�� ������ �ѹ��� �湮�ؾߵǱ⶧����  ���ܽ�����.
        if (*it == v)
            return true;
    return false;
}

void travel2(vector<int>& opttour, int& minlength)
{
    priority_queue<node_pointer, vector<node_pointer>, cmp> pq; // path,bound������ ��������.
    node_pointer a, b;
    a = (node_pointer)malloc(sizeof(nodetype));
    b = (node_pointer)malloc(sizeof(nodetype));

    minlength = INF;
    b->level = 0;

    b->path.push_back(StartV); // StartV�� ������� �ǹ���.
    b->bound = Bound(b);       //

    cout << b->level << " " << b->bound << " ";
    print(b);
    pq.push(b);
    while (!pq.empty())
    {
        b = pq.top();
        pq.pop();
        if (b->bound < minlength) // bound���� minlength���� �۾ƾ� �����ϴ�.
        {
            // a->level = b->level + 1; // a�� b�� �ڽĳ��� ����.
            for (int i = 1; i <= G; i++)
            {

                if (isIn(i, b->path) == 0) // isIn���� 0�̸� i�� ��ο� �̹� �ִٴ� �Ҹ��� 1�̸� i�� ��ο� ���ٴ� �Ҹ���.
                {
                    continue; // ���� i�� b�� ��ο� �ִ٤Ť���?
                }
                a = create_node(b->level + 1, b->path); //������ 5�϶� ����.
                a->level = b->level + 1;
                a->path = b->path;
                a->bound = 0;
                a->path.push_back(i);
                if (a->level == G - 2) // a->level�� ���ð���-2����� ���� ��������λ��� �� ������ ��Ȳ
                //������ ��δ� ���� �����ʿ���� �湮���� ���ø� �ڵ����� �־��ָ� �Ǵ°�. G-2�� ������ ������� �湮�� level�� 0�̹Ƿ�
                {
                    for (int k = 1; k <= G; k++) // 1���� k�����ؼ� ����δ� �糢�� �Ȱ���θ�  �翬�� �����ϹǷ� Ǫ������.
                    {
                        if (isIn(k, a->path) == 0) // 0�̸� ��� x 1�̸� ��� o
                        {
                            continue;
                        }
                        else
                        {
                            a->path.push_back(k);
                        }
                    }
                    a->path.push_back(StartV); //�������� 1�� ���ư�����. //1�� start�� �ٲ���.
                    if (length(a->path) < minlength)
                    {
                        minlength = length(a->path);
                        ;
                        opttour.assign(a->path.begin(), a->path.end());
                    }
                    a->bound = Bound(a);
                    if (correct_path(a)) //���� path���� ������ ������� ������.
                    {
                        cout << a->level << " " << a->bound << " ";
                        print(a);
                    }
                    else  //������ ��ΰ� �ƴҶ��� INF�� ���
                    {
                        a->bound = Bound(a);
                        cout << a->level << " "
                            << "INF"
                            << " ";
                        print(a);
                    }
                }
                else //a->level�� G-2���� �������� ���� ã�������.
                {
                    bool flag = true;
                    if (correct_path(a)) //�̻��� ��ΰ� �ƴ϶�� �״�� bound���� �־���.
                    {
                        a->bound = Bound(a);
                        cout << a->level << " " << a->bound << " ";
                        print(a);
                    }
                    else //�̻��� ��ζ�� INF�� �־���.
                    {
                        a->bound = Bound(a);
                        cout << a->level << " "
                            << "INF"
                            << " ";
                        print(a);
                    }
                    if (a->bound < minlength) // bound�� �ʱ�ȭ �� minlength���� �۴ٸ� �־��ش�.
                        pq.push(a);
                }
            }
        }
    }
}
bool correct_path(node_pointer a) // 1�̸� ��ΰ� �ְ� 0�̸� ��ΰ� ����.
{
    bool flag;
    flag = true;
    for (int x = 1; x < a->path.size(); x++)
    {
        if (graph[a->path[x - 1]][a->path[x]] == INF) //��ΰ� ���ٸ�
        {
            flag = false;
        }
    }
    return flag;
}
bool isIn(int i, vector<int>& path) // path�ȿ� i�� �ֳ� ���ĸ� ����.
{
    vector<int>::iterator it;
    // cout<<1;
    bool opt = true;
    for (int j = 0; j <= path.size() - 1; j++)
    {
        if (i == path[j]) //������ ������
            return false;
    }
    // cout<<"opt��" << opt<<endl;
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