/*
��������Ʈ�� ������ �ּ��� Ž��������� Ʈ���� �����Ϸ��� ���� ��ǥ��.
����Ʈ���� �θ��� ������ �θ𺸴� �۰ų����ƾ� �θ��� �������� �θ𺸴� ũ�ų����ƾ��Ѵ�.
Ž������� �� Ʈ���� ���� * Ž�����(Ȯ��)�̴�. ������ Ž�� ����� ���̰� �������� �����ϴ�.
k1,k2,k3, *** kn�� key��� �ϰ� �� key�� Ȯ���� p1,p2,p3,***pn�̶�� ����.
�׷��� average search time�� ci*pi i�� 1���� n���� �ϰ��̴�.
D[i][j]�� �������� �������� root�� ã�� ������ root�� �߽����� left,right�� ������ ���.
���⼭ k��? ������ root ���� ���Ѵ�. k�� i���� j������ ���� �ݺ������� ������ �� k�� �������� left,right �ɰ��� leftƮ���� Ž������ rightƮ���� Ž������� ����Ѵ�.
�� Ž�� ����� �ּҰ� �Ǵ� k���� ������ root�̴�.
k�� �������� �ɰ��� left,rightƮ���� �θ��尡 k�� �Ǳ⶧���� ������ pi���� �ѹ��� �� �����ش�. ���̰� ��ĭ�� �����߱⋚���̴�.
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
                D[j][k] = mini(j, k, root, D, pro); // j���� k������ ã�� ������ k�� root�� �����ϰڴ�.
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
    //N.key = key[root]; // ������ key���� root��° key�̴�.
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
            a = k; //������ ��Ʈ k���� ����.
        }
        sum = sum + p[k]; //p[i]~[j]���� ����
    }
    return minvalue + sum;
}