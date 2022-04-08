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

#include <iostream>
#include <vector>
#define INF 9999
using namespace std;
void printary(int n, vector<int>& a);
typedef struct node* node_ptr;
struct node
{
    int key;
    node_ptr left;
    node_ptr right;
};
int main()
{
    int n, root;
    cin >> n;
    vector<int> key(n + 1);
    vector<int> pro(n + 1);
    vector<vector<int>> D(n + 1, vector<int>(n + 1, -1));
    vector<vector<int>> P(n + 1, vector<int>(n + 1, -1));
    node N;
    for (int i = 1; i <= n; i++)
    {
        cin >> key[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> pro[i];
    }
    for (int i = 1; i <= n; i++)
    {
        D[i][i] = pro[i];
    }
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            int k = j + i;
            if (D[j][k] != -1)
            {
                D[j][k] = mini(j, k, root, D, pro);
                P[j][k] = root;
            }
            else
            {
                continue;
            }
        }
    }
    return 0;
}
void printary(int n, vector<int>& a)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (j < n)
                cout << a[i][j] << " ";
            else
                cout << a[i][j];
        }
        if (i < n)
            cout << endl;
    }
}
int mini(int i, int j, int& a, vector<vector<int>>& D, vector<int>& p)
{
    int minvalue = INF, value, sum = 0; // i<=k<=j
    for (int k = i; k <= j; k++)
    {
        value = D[i][k - 1] + D[k + 1][j];
        if (minvalue > value)
        {
            minvalue = value;
            a = k; //������ ��Ʈ k���� ����.
        }
        sum = sum + p[k];
    }
    return minvalue + p[j];
}