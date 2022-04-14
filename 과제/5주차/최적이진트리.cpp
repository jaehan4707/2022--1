/*
최적이진트리 문제는 최소의 탐색비용으로 트리를 구성하려는 것이 목표다.
이진트리는 부모의 왼쪽이 부모보다 작거나같아야 부모의 오른쪽이 부모보다 크거나같아야한다.
탐색비용은 각 트리의 높이 * 탐색비용(확률)이다. 보통의 탐색 비용은 높이가 낮을때가 유리하다.
k1,k2,k3, *** kn이 key라고 하고 각 key에 확률을 p1,p2,p3,***pn이라고 하자.
그러면 average search time은 ci*pi i가 1에서 n까지 일것이다.
D[i][j]의 최적값은 최적값인 root를 찾고 최적인 root를 중심으로 left,right를 나눠서 계산.
여기서 k란? 최적인 root 값을 말한다. k를 i부터 j까지의 값을 반복문으로 돌려서 그 k를 기준으로 left,right 쪼개서 left트리의 탐색비용과 right트리의 탐색비용을 계산한다.
그 탐색 비용이 최소가 되는 k값이 최적의 root이다.
k를 기준으로 쪼개진 left,right트리의 부모노드가 k가 되기때문에 각각의 pi값을 한번씩 더 더해준다. 높이가 한칸씩 증가했기떄문이다.
*/

#include <iostream>#include <iostream>
#include <vector>
#define INF 9999

using namespace std;
typedef struct node* node_ptr;
struct node {
    int key;
    node_ptr left;
    node_ptr right;
};
vector<int>in(0);
vector<int>pre(0);
void printary(int n, vector<vector<int>>& a);
int mini(int i, int j, int& a, vector<vector<int>>& D, vector<int>& p);
node_ptr create_node(int n, node N);
node_ptr tree(int i, int j, vector<vector<int>>P, vector<int>& key);
node_ptr preorder(node_ptr node);
node_ptr inorder(node_ptr node);
int main()
{
    int n, root;
    node* Node;
    cin >> n;
    vector<int>key(n + 1);
    vector<int>pro(n + 1);
    vector<vector<int>>D(n + 2, vector<int>(n + 2, -1));
    vector<vector<int>>P(n + 2, vector<int>(n + 2, -1));

    for (int i = 1; i <= n; i++)
    {
        cin >> key[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> pro[i];
    }
    for (int i = 1; i <= n; i++) //10 21 32 43 
    {
        D[i][i] = pro[i];
        D[i][i - 1] = 0;
        D[n + 1][n] = 0;
        //D[i + 1][i] = 0;
        P[i][i] = i;
        P[i][i - 1] = 0;
        P[n + 1][n] = 0;

    }
    for (int i = 1; i <= n; i++) //n==4
    {
        for (int j = 1; j <= n - i; j++) //i=1,j=1~3 -> 1,2,2,3,3,4, // i=2 j=1~2 13 24 // i=3 j=1  1 4
        {
            int k = j + i;
            if (D[j][k] == -1)
            {
                D[j][k] = mini(j, k, root, D, pro); // j부터 k까지를 찾고 최적의 k를 root에 저장하겠다.
                P[j][k] = root;
            }
            else
            {
                continue;
            }
        }
    }
    printary(n, D);
    cout << endl;
    printary(n, P);
    cout << endl;
    cout << D[1][n];
    //N.key = key[root]; // 최적의 key값은 root번째 key이다.
    //20103040
    //10203040
    Node = tree(1, n, P, key);
    cout << endl;
    preorder(Node);
    for (int i = 0; i < pre.size(); i++)
    {
        if (i < pre.size() - 1)
            cout << pre[i] << " ";
        else
            cout << pre[i];
    }
    cout << endl;
    inorder(Node);
    for (int i = 0; i < in.size(); i++)
    {
        if (i < in.size() - 1)
            cout << in[i] << " ";
        else
            cout << in[i];
    }
    return 0;
}
node_ptr create_node(int a)
{
    node_ptr temp = (node_ptr)malloc(sizeof(node));
    temp->key = a;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
node_ptr tree(int i, int j, vector<vector<int>>P, vector<int>& key)
{
    int k = P[i][j];
    if (k == 0)
    {
        return NULL;
    }
    else
    {
        node_ptr NODE = create_node(key[k]);
        NODE->left = tree(i, k - 1, P, key);
        NODE->right = tree(k + 1, j, P, key);
        return NODE;
    }
}
node_ptr preorder(node_ptr node)
{
    if (node != NULL)
    {
        pre.push_back(node->key);
        preorder(node->left);
        preorder(node->right);
    }
    return node;
}

node_ptr inorder(node_ptr node)
{
    if (node != NULL)
    {
        inorder(node->left);
        in.push_back(node->key);
        inorder(node->right);
    }
    return node;
}

void printary(int n, vector<vector<int>>& a)
{
    for (int i = 1; i <= n + 1; i++)
    {
        for (int j = i - 1; j <= n; j++)
        {
            if (j < n)
                cout << a[i][j] << " ";
            else
                cout << a[i][j];
        }
        if (i < n + 1)
            cout << endl;
    }
}
int mini(int i, int j, int& a, vector<vector<int>>& D, vector<int>& p)
//D[i][j]=A[i][k-1]+A[k+1][j] + p i~j
{
    int minvalue = INF, value, sum = 0;   //i<=k<=j
    for (int k = i; k <= j; k++)
    {
        value = D[i][k - 1] + D[k + 1][j];
        if (minvalue > value)
        {
            minvalue = value;
            a = k; //최적인 루트 k값을 저장.
        }
        sum = sum + p[k]; //p[i]~[j]까지 저장
    }
    return minvalue + sum;
}