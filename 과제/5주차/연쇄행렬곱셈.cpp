/*
연쇄행렬곱셈문제
행렬은 교환법칙은 성립하지않지만 결합법칙은 성립한다. 교환법칙은 성립할수없는게 곱하려는 행렬의 맞닿은 숫자들이 같아야하기때문이다.
A(i*j)X B(j*k) 여기서 A의 열과 B의 행이 같아야한다. 이럴 때 두 행렬을 만들 떄 총 하게 되는 곱셈의 수는 i*j*k이다.
1.n을 입력받는다. 여기서 n은 행렬의 개수를 의미한다. A1 ,A2, A3,,,,,An
2.행렬의 row col값을 입력받는다. 여기서 그 값을 나는 d배열의 저장했다.
3.곱셉의 최적값을 저장할 D배열을 만들고  D[i][j]는 Ai~ Aj까지의 최소 곱셈을 저장함.
4.곱셉의 최적값을 구하는 방법은 D[i][j]를 k기준으로 쪼개고 그 k를 i부터 j까지 반복문으로 돌림.
5.그러면 D[i][k]+D[k+1][j]값과 그 행렬을 곱하는데 또 계산되는 곱셈의 수 D[i]의 d값 d[i-1], d[k],d[j]를 곱해준다.
6.따라서 D[i][j]는 D[i][k]+D[k+1][j]값과 d[i-1]*d[k]*d[j]의 더한것중에 가장 작은 값을 가진다. 그 때의 k가 이제 P[i][j]의 저장됨
7.P[i][j]는 i~j까지를 계산하는데 최적인 k, k를 기준으로 괄호를 묶음.
*/
#include <iostream>
#include <vector>
#include <string>
#define INF 999999
using namespace std;
int mini(int i, int j, int& a, vector<vector<int>>& D, vector<int>& d);
void printary(int n, vector<vector<int>>& a);
void order(int i, int j, vector<vector<int>>& P, string& s);
vector<int> d(0);
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> D(n + 1, vector<int>(n + 1, -1)); //최적값 배열
    vector<vector<int>> P(n + 1, vector<int>(n + 1, 0));  //최적해 배열
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
    for (int i = 1; i <= n - 1; i++) //모든 계산의 기본이 되는 12 23 34 45 56을 먼저 구해줌.
    {
        for (int j = 1; j <= n - i; j++) // n==6 i==1 i==2
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
    cout << endl; // D배열 출력
    printary(n, P);
    cout << endl
        << D[1][n] << endl;
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
int mini(int i, int j, int& a, vector<vector<int>>& D, vector<int>& d)
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
        s += string("(") + string("A") + to_string(i) + string(")");
    else
    {
        int k = P[i][j];
        s += string("(");
        order(i, k, P, s);
        order(k + 1, j, P, s);
        s += string(")");
    }
}