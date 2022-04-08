/*
행렬의 개수 n과 행렬의 크기 값의 배열d를 입력 받고 M,P행렬의 값을 출력
단위곱셈의 최적 횟수 및 행렬곱셈의 순서(괄호로 묶어서)
d값은 row,col  M최적값, D최적해
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
    vector<vector<int>> D(n + 1, vector<int>(n + 1, -1)); //최적값 배열
    vector<vector<int>> P(n + 1, vector<int>(n + 1, 0)); //최적해 배열
    string s;
    int key = 0;
    for (int i = 0; i <= n; i++)
    {
        int num = 0;
        cin >> num;
        d.push_back(num);
    }
 
    for (int i = 1; i <= n; i++) //대각행렬 대각선을 0으로 만들어줌.
    {
        D[i][i] = 0;
    }
    for (int i = 1; i <= n-1; i++) //모든 계산의 기본이 되는 12 23 34 45 56을 먼저 구해줌.
    {
        for (int j = 1; j <= n-i; j++) //n==6 i==1 i==2
        {
            int k = i + j;
            if (D[j][k] == -1) //중복제거 값이 들어있으면 그냥 return 해줌
            {
                D[j][k] = mini(j, k, key, D, d);
                P[j][k] = key;
            }
            else
                continue;
        }
    }
    printary(n, D);
    cout << endl;//D배열 출력
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
// i는 시작 j는 끝 a는 최소값을 저장하는 공간, D는 최적값배열, D는 row,col값
//행렬의 곱을 묶고 그다음 행렬 곱셈 계산 값이 d[i-1]+d[k]+d[j]이다
{
    int minvalue = INF, value; 
    for (int k = i; k <= j - 1; k++)
    {
        value = D[i][k] + D[k + 1][j] + (d[i - 1] * d[k] * d[j]);
        if (minvalue > value)
        {
            minvalue = value;
            a = k; //최적의 k를 저장
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