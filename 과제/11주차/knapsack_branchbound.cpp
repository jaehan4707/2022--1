/*
branch&Bound를 이용한 0-1 Knapsack problem
무게대비 이득을 내림차순으로 정렬
유망한것부터 탐색함.
유망한것은? Bound값이 높은것.
Prority queue를 이용함. Bound값을 기준으로 내림차순 정렬
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
    // profit/weight 큰 것으로 정렬
    for (int i = 1; i <= N; i++)
    {
        for (int j = i + 1; j <= N; j++)
        {
            if (profit[i] / Weight[i] < profit[j] / Weight[j]) // 앞에게 더 크다면 나둠
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
    priority_queue<node_p, vector<node_p>, compare> pq; // bound값으로 내림차순 정렬해서 넣어줫음.
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
            //가방에 보석을 담은경우
            u = create_node();
            u->level = v->level + 1;
            // cout << u->level << endl;

            u->weight = v->weight + Weight[v->level + 1];

            u->profit = v->profit + profit[v->level + 1];
            u->bound = bound(u);
            print_node(u);
            //cout << "담았을 경우 " << u->bound << endl;
            // cout << u->level << " " << u->weight << " " << u->profit << " " << u->bound << endl;
            if (u->weight <= W && u->profit > maxprofit) //내가 다음 노드로 진행햇는데 그때의 무게가 W보다 작거나 같아야함.
            {
                maxprofit = u->profit; //그때의 이익이 만약 maxprofit보다 크다면 최신화시켜줌.
            }
            if (u->bound > maxprofit)
            {
                pq.push(u); //내가 설정한 바운드값보다 maxprofit이 크다면 pq에 푸쉬해줌.
                // cout << u->level << " " << u->weight << " " << u->profit << " " << u->bound << endl;
                // print_node(u);
            }
            //가방에 보석을 담지 않는 경우.
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
    if (u->weight >= W) //그때 방문했던 노드의 무게 합이 W보다 크다면 잘못된 방문임을 뜻함.
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