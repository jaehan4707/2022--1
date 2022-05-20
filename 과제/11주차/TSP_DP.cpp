/*
DP를 사용해서 Sales person 문제 풀기
D라는 2차원 배열을 만들고 D[i][j]는 i->1을 가는데 j를거치는 최단 경로의 길이라고 한다.
D[vi][A]를 에서 A를 집합형태로 만들어서 A집합에서 가장 최단경로를 구함.
W배열은 각각의 정점에서 다른 정점으로 가는 경로의 길이. 없을 시 INF로 무한대를 나타냄.

만약 A가 공집합이라면 그냥 그 정점에서 1까지 가는 경로를 구하면됨.
D[vi][A]=W[i][j]+D[vj][A-{vj}]를 j가 증가시켜주면됨. 이때 j는 A에속해야한다.
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
    D.resize(n + 1, vector<int>(pow(2,n-1), 999)); // 0~4까지
    W.resize(n + 1, vector<int>(n+1, INF)); // 0~4까지
    P.resize(n + 1, vector<int>(pow(2,n-1), -1)); //0~4까지 //0~7까지
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
    tour(1, pow(2, n - 1) - 1, P);  //P[1][7[이 최적경로 //1번정점에서 1번으로 되돌아오는 경로를 만듬.
    for (int i = 0; i < path.size(); i++)
    {
        if (i < path.size() - 1)
            cout << path[i] << " ";
        else
            cout << path[i];
    }
    cout << endl;
    for (int i = 1; i <= n; i++) //Cnt는 D배열에서 INF값이 아닌 것들의 수
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
    int A, j,i; // A의 집합을 표현할려면 2진수 개념을 사용
    //부분집합의 개수는 2^N-1개이다. N-1인 이유는 v1은 집합에 포함 안하기때문이다.
    int Size = pow(2, n - 1);
    for (i = 2; i <= n; i++)
    {
        D[i][0] = W[i][1]; //바로 가는 경로
        if(D[i][0]!=INF)
            Cnt++;
    }
    for (int k = 1; k <= n - 2; k++) //A집합에서 k를 뺄거임. n은 4 n-2까지 왜? 1,2음.
    {
        for (A = 0; A < Size; A++) //A집합 원소의 개수가 K개여야함. //A집합에서 1의 개수가 원소의 개수이다.
        {
            if (Count(A) != k) continue;
            for (int i = 2; i <= n; i++)
            {
                if (isIn(i, A)) continue; //i가 출발점임.
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
    for (; A != 0; A >>= 1) //A>>1은 A를 한칸씩 오른쪽으로 옮겨줌.
    {
        if (A & 1)cnt++;
    }
    return cnt;
}
bool isIn(int i, int A)
{
    return (A & (1 << (i - 2))) != 0; //1의 비트를 왼쪽으로 i-2만큼 이동시킴.
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
    return (A & ~(1 << (j - 2))); //0과 1을 바꿈.
}
void tour(int v, int A, vector<vector<int>>& P)
{
    int k = P[v][A];
    if (A == 0) //맨마지막에 경로는 1이여야함.
        path.push_back(1);
    else
    {
        path.push_back(k);
        tour(k, diff(A, k), P);
    }
}