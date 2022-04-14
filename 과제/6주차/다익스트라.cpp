/*
directed graph
v1�� ù�������� ����.v1���� ���� ����� vertex�� �����ؼ� Y���տ� ����.
Y����(v1, v2) V- Y(v3, v4, v5) �� ���� Y���տ��� ����� �Ͱ� V - Y������ ��� Y���� ��带�����ϴ� ��������� �ؾ���.
prim�˰���� dijkstra�˰����� ����ϴ�.���̴� nearest, distance �迭�� ���� prim������
dijkstra�� touch�迭�� length�迭�� ����Ѵ�.
touch�迭�� v[i]->v1�� ���µ� ����� ���
length�迭�� y���տ��� vi ���� �ּҺ�� ���
*/
#define INF 999999
#include <iostream>
#include <vector>

using namespace std;
typedef vector<vector<int>> matrix;
void dijkstra(int n, matrix& t, vector<pair<int, int>>& F);
int find(vector<int>& v, int n);
int n, m;
vector<int> touch(n + 1), length(n + 1);
int main()
{
    cin >> n >> m;
    touch.resize(n + 1, 0);
    length.resize(n + 1, 0);
    matrix a(n + 1, vector<int>(n + 1, INF));
    vector<pair<int, int>> b;
    vector<int> weight;
    for (int i = 0; i < m; i++)
    {
        int s, f, w;
        cin >> s >> f >> w;
        a[s][f] = w;
    }
    dijkstra(n, a, b);
    for (int i = 0; i < b.size(); i++)
    {
        int u = b[i].first, v = b[i].second;

        cout << u << " " << v << " " << a[u][v] << endl;
    }

    int number, aa;
    cin >> number;
    for (int i = 0; i < number; i++)
    {
        // touch���� 1�� �ɶ����� �ѱ�
        cin >> aa;
        vector<int> bb;
        while (aa != 1)
        {
            bb.push_back(aa);
            aa = touch[aa];
        }
        bb.push_back(1);
        for (int i = bb.size() - 1; i >= 0; i--)
        {
            if (i > 0)
                cout << bb[i] << " ";
            else
                cout << bb[i];
        }
        cout << endl;
    }
}
void dijkstra(int n, matrix& t, vector<pair<int, int>>& F)
{
    int vnear, min;
    F.clear();
    for (int i = 2; i <= n; i++) // v1�� �������������� �ϱ� �����̴�.
    {
        touch[i] = 1;
        length[i] = t[1][i];
    }
    for (int i = 2; i <= n; i++)
    {
        if (i < n)
            cout << touch[i] << " ";
        else
            cout << touch[i];
    }
    cout << endl;

    for (int i = 0; i < n - 1; i++)
    {
        min = INF;
        for (int i = 2; i <= n; i++)
        {
            if (0 <= length[i] && length[i] < min)
            {
                min = length[i];
                vnear = i;
            }
        }
        F.push_back(make_pair(touch[vnear], vnear)); //������ f�� �־��ֱ�
        // find(touch, vnear);
        for (int i = 2; i <= n; i++)
        {
            if (length[i] > length[vnear] + t[vnear][i]) //���� y���տ����� dintance�� �߰��� v���� �Ÿ� ���
            {
                length[i] = length[vnear] + t[vnear][i];
                touch[i] = vnear;
            }
        }
        for (int i = 2; i <= n; i++)
        {
            if (i < n)
                cout << touch[i] << " ";
            else
                cout << touch[i];
        }
        cout << endl;
        length[vnear] = -1;
        // num++;
    }
}
