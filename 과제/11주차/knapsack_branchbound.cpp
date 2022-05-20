/*
branch&Bound�� �̿��� 0-1 Knapsack problem
���Դ�� �̵��� ������������ ����
�����Ѱͺ��� Ž����.
�����Ѱ���? Bound���� ������.
Prority queue�� �̿���. Bound���� �������� �������� ����
*/

/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
typedef struct node* node_p;
typedef struct node
{
    int level;
    int weight;
    int profit;
    float bound;
} nodetype;
struct compare
{
    bool operator()(node_p a, node_p b)
    {
        return a->bound < b->bound;
    }
};
int N, W;
vector<int> profit;
vector<int> Weight;
int maxprofit;
void knapsack6();
float bound(node_p u);
node_p create_node();
void print_node(node_p u);
int main()
{
    cin >> N >> W;
    Weight.resize(N + 1);
    profit.resize(N + 1);
    for (int i = 1; i <= N; i++)
    {
        int w;
        cin >> w;
        Weight[i] = w;
    }
    for (int j = 1; j <= N; j++)
    {
        int a;
        cin >> a;
        profit[j] = a;
    }
    // profit/weight ū ������ ����
    for (int i = 1; i <= N; i++)
    {
        for (int j = i + 1; j <= N; j++)
        {
            if (profit[i] / Weight[i] < profit[j] / Weight[j]) // �տ��� �� ũ�ٸ� ����
            {
                swap(profit[i], profit[j]);
                swap(Weight[i], Weight[j]);
            }
        }
    }
    knapsack6();
    cout << maxprofit;
}
void knapsack6()
{
    priority_queue<node_p, vector<node_p>, compare> pq; // bound������ �������� �����ؼ� �־�Z��.
    node_p u, v;
    u = (node_p)malloc(sizeof(nodetype) * N);
    v = (node_p)malloc(sizeof(nodetype) * N);
    maxprofit = 0;
    v = create_node();
    v->level = 0;
    v->profit = 0;
    v->weight = 0;
    v->bound = bound(v);
    print_node(v);
    pq.push(v);
    while (!pq.empty())
    {
        v = pq.top();
        pq.pop();
        //print_node(v);
        if (v->bound > maxprofit)
        {
            //���濡 ������ �������
            u = create_node();
            u->level = v->level + 1;
            // cout << u->level << endl;

            u->weight = v->weight + Weight[v->level + 1];

            u->profit = v->profit + profit[v->level + 1];
            u->bound = bound(u);
            print_node(u);
            //cout << "����� ��� " << u->bound << endl;
            // cout << u->level << " " << u->weight << " " << u->profit << " " << u->bound << endl;
            if (u->weight <= W && u->profit > maxprofit) //���� ���� ���� �����޴µ� �׶��� ���԰� W���� �۰ų� ���ƾ���.
            {
                maxprofit = u->profit; //�׶��� ������ ���� maxprofit���� ũ�ٸ� �ֽ�ȭ������.
            }
            if (u->bound > maxprofit)
            {
                pq.push(u); //���� ������ �ٿ�尪���� maxprofit�� ũ�ٸ� pq�� Ǫ������.
                // cout << u->level << " " << u->weight << " " << u->profit << " " << u->bound << endl;
                // print_node(u);
            }
            //���濡 ������ ���� �ʴ� ���.
            u = create_node();
            u->level = v->level + 1;
            u->weight = v->weight;
            u->profit = v->profit;
            u->bound = bound(u);
            print_node(u);
            if (u->bound > maxprofit)
            {
                pq.push(u);
                // print_node(u);
                //  cout << u->level << " " << u->weight << " " << u->profit << " " << u->bound << endl;
                //  print_node(u);
            }
            // print_node(u);
            // cout<<endl;
        }
    }
}
node_p create_node()
{
    node_p temp;
    temp = (node_p)malloc(sizeof(nodetype) * N);
    return temp;
}
float bound(node_p u)
{
    int j, k, totweight;
    float result;
    if (u->weight >= W) //�׶� �湮�ߴ� ����� ���� ���� W���� ũ�ٸ� �߸��� �湮���� ����.
        return 0;
    else
    {
        result = u->profit;
        j = u->level + 1;
        totweight = u->weight;
        while (j <= N && totweight + Weight[j] <= W)
        {
            totweight += Weight[j];
            result += profit[j];
            j++;
        }
        k = j;
        if (k <= N)
            result += (W - totweight) * ((float)profit[k] / Weight[k]);
        return result;
    }
}
void print_node(node_p u)
{
    cout << u->level << " " << u->weight << " " << u->profit << " " << u->bound << endl;
}
*/