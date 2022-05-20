/*
DP�� ����ؼ� Sales person ���� Ǯ��
D��� 2���� �迭�� ����� D[i][j]�� i->1�� ���µ� j����ġ�� �ִ� ����� ���̶�� �Ѵ�.
D[vi][A]�� ���� A�� �������·� ���� A���տ��� ���� �ִܰ�θ� ����.
W�迭�� ������ �������� �ٸ� �������� ���� ����� ����. ���� �� INF�� ���Ѵ븦 ��Ÿ��.

���� A�� �������̶�� �׳� �� �������� 1���� ���� ��θ� ���ϸ��.
D[vi][A]=W[i][j]+D[vj][A-{vj}]�� j�� ���������ָ��. �̶� j�� A�����ؾ��Ѵ�.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define INF 999 
int n, m,minl=0,Size,Cnt=0;
vector<vector<int>> D, W,P;
vector<int>path;
int Count(int A);
void travel(int n, vector<vector<int>>& P, int& minlength);
bool isIn(int i, int A);
int minimum(int n, int i, int& minJ, int A);
int diff(int A, int j);
void tour(int v, int A, vector<vector<int>>& P);
int main()
{
    int cnt=0;
    cin >> n >> m;
    D.resize(n + 1, vector<int>(pow(2,n-1), 999)); // 0~4����
    W.resize(n + 1, vector<int>(n+1, INF)); // 0~4����
    P.resize(n + 1, vector<int>(pow(2,n-1), -1)); //0~4���� //0~7����
    for (int i = 0; i < m; i++)
    {
        int s, f, l;
        cin >> s >> f >> l;
        W[s][f] = l;
    }
    for (int i = 1; i <= n; i++)
    {
        W[i][i] = 0;
    }
    travel(n, P, minl);
    cout << minl<<endl;
    cout << 1 << " ";
    tour(1, pow(2, n - 1) - 1, P);  //P[1][7[�� ������� //1���������� 1������ �ǵ��ƿ��� ��θ� ����.
    for (int i = 0; i < path.size(); i++)
    {
        if (i < path.size() - 1)
            cout << path[i] << " ";
        else
            cout << path[i];
    }
    cout << endl;
    for (int i = 1; i <= n; i++) //Cnt�� D�迭���� INF���� �ƴ� �͵��� ��
    {
        for (int j = 0; j <pow(2, n - 1);j++)
        {
            if (D[i][j] != 999)
            {
                cnt++;
                if (cnt < Cnt)
                    cout << i << " " << j << " " << D[i][j] << endl;
                else
                    cout << i << " " << j << " " << D[i][j];
            }
        }
    }
}
void travel(int n, vector<vector<int>>& P, int& minlength)
{
    int A, j,i; // A�� ������ ǥ���ҷ��� 2���� ������ ���
    //�κ������� ������ 2^N-1���̴�. N-1�� ������ v1�� ���տ� ���� ���ϱ⶧���̴�.
    int Size = pow(2, n - 1);
    for (i = 2; i <= n; i++)
    {
        D[i][0] = W[i][1]; //�ٷ� ���� ���
        if(D[i][0]!=INF)
            Cnt++;
    }
    for (int k = 1; k <= n - 2; k++) //A���տ��� k�� ������. n�� 4 n-2���� ��? 1,2��.
    {
        for (A = 0; A < Size; A++) //A���� ������ ������ K��������. //A���տ��� 1�� ������ ������ �����̴�.
        {
            if (Count(A) != k) continue;
            for (int i = 2; i <= n; i++)
            {
                if (isIn(i, A)) continue; //i�� �������.
                D[i][A] = minimum(n, i, j, A);
                if (D[i][A] != INF)
                    Cnt++;
                P[i][A] = j;
            }
        }
    }
    A = Size - 1;
    D[1][A] = minimum(n - 1, 1, j, A);
    P[1][A] = j;
    minlength = D[1][A];
    Cnt++;
}
int Count(int A)
{
    int cnt = 0;
    for (; A != 0; A >>= 1) //A>>1�� A�� ��ĭ�� ���������� �Ű���.
    {
        if (A & 1)cnt++;
    }
    return cnt;
}
bool isIn(int i, int A)
{
    return (A & (1 << (i - 2))) != 0; //1�� ��Ʈ�� �������� i-2��ŭ �̵���Ŵ.
}
int minimum(int n, int i, int& minJ, int A)
{
    int minV = INF,value;
    for (int j = 2; j <= n; j++)
    {
        if (!isIn(j, A))continue;
        int value = W[i][j] + D[j][diff(A, j)];
        if (minV > value) {
            minV = value;
            minJ = j;
        }
    }
    return minV;
}
int diff(int A, int j)
{
    return (A & ~(1 << (j - 2))); //0�� 1�� �ٲ�.
}
void tour(int v, int A, vector<vector<int>>& P)
{
    int k = P[v][A];
    if (A == 0) //�Ǹ������� ��δ� 1�̿�����.
        path.push_back(1);
    else
    {
        path.push_back(k);
        tour(k, diff(A, k), P);
    }
}