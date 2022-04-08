/*
����� ���� n�� ����� ũ�� ���� �迭d�� �Է� �ް� M,P����� ���� ���
���������� ���� Ƚ�� �� ��İ����� ����(��ȣ�� ���)
d���� row,col  M������, D������
*/
#include <iostream>
#include <vector>
#include <string>
#define INF 999999
using namespace std;
int mini(int i, int j, int &a, vector<vector<int>>& D, vector<int>& d);
void printary(int n, vector<vector<int>>& a);
void order(int i, int j, vector<vector<int>>& P, string& s);
vector<int> d(0);
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> D(n + 1, vector<int>(n + 1, -1)); //������ �迭
    vector<vector<int>> P(n + 1, vector<int>(n + 1, 0)); //������ �迭
    string s;
    int key = 0;
    for (int i = 0; i <= n; i++)
    {
        int num = 0;
        cin >> num;
        d.push_back(num);
    }
 
    for (int i = 1; i <= n; i++) //�밢��� �밢���� 0���� �������.
    {
        D[i][i] = 0;
    }
    for (int i = 1; i <= n-1; i++) //��� ����� �⺻�� �Ǵ� 12 23 34 45 56�� ���� ������.
    {
        for (int j = 1; j <= n-i; j++) //n==6 i==1 i==2
        {
            int k = i + j;
            if (D[j][k] == -1) //�ߺ����� ���� ��������� �׳� return ����
            {
                D[j][k] = mini(j, k, key, D, d);
                P[j][k] = key;
            }
            else
                continue;
        }
    }
    printary(n, D);
    cout << endl;//D�迭 ���
    printary(n, P);
    cout << endl << D[1][n]<<endl;
    order(1, n, P, s);
    cout << s;
    return 0;
}
void printary(int n, vector<vector<int>>& a)
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
int mini(int i, int j, int &a, vector<vector<int>>& D, vector<int>& d)
// i�� ���� j�� �� a�� �ּҰ��� �����ϴ� ����, D�� �������迭, D�� row,col��
//����� ���� ���� �״��� ��� ���� ��� ���� d[i-1]+d[k]+d[j]�̴�
{
    int minvalue = INF, value; 
    for (int k = i; k <= j - 1; k++)
    {
        value = D[i][k] + D[k + 1][j] + (d[i - 1] * d[k] * d[j]);
        if (minvalue > value)
        {
            minvalue = value;
            a = k; //������ k�� ����
        }
    }
    return minvalue;
}
void order(int i, int j, vector<vector<int>>& P, string& s)
{
    if (i == j)
        s += string("(")+string("A") + to_string(i)+string(")");
    else
    {
        int k = P[i][j];
        s += string("(");
        order(i, k, P, s);
        order(k + 1, j, P, s);
        s += string(")");
    }
}