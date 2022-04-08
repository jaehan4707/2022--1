/*
최장부분공통서열 문제(LCS) 최장부분공통서열이란? 부분서열중에서 가장 긴것을 찾는 문제
DP를 쓰는 문제  이전에 계산된것을 계산안하고 저장된 값을 그대로 끌어쓰기 때문이다.
우선
1.문자열 x와 문자열 y를 입력받음.
2.부분서열의 길이를 저장할 2차원 배열을 만듬. 내 코드에서는 그 배열 이름이 D이다.
3.문자열을 비교해야함. 1부터 문자열 끝까지 for문을 돌림.
4.만약 비교문자열이  같다면 i-1,j-1의 부분서열에서 i,j인덱스의 문자가 추가된것이므로. D[i][j]=[D[i-1][j-1]+1이된다.
5.만약 비교문자열이 다르다면 그 i,j까지의 최대 문자열개수가 많은 곳의 문자열개수를 그대로 받아 넣으면 된다.  \
i,j의 직전 배열은 D[i-1][j] 와 D[i][j-1]이다.  그 중에서 큰 값을 넣어주면 된다.
6.이렇게 넣어주면 여기서 n은 x문자열의 크기, M은 y문자열의 크기이다. D[N][M]은 가장 큰 부분서열의 개수를 저장하게된다.
7.부분서열의 길이를 구했으면 그 문자열을 출력을 해야한다. 이 때 쓰이는 방법이 역추적방법이다.
8.역추적방법을  사용하기 위해서 나는 방향성?을 부여했다.  방향성배열도 D배열 처럼 2차원 배열로 생성한다. D[i]][j]의 값을 결정하는 방향은 3개이다.
두 문자열이 같을 때(왼쪽 위 대각선), 두 문자열이 다를 때(위,아래)중 큰 값 각각 방향의 값을 부여한다. 왼쪽 위 대각선 1 아래가 2 왼쪽이 3
9.그래서 D[N][M]에서 출발한다.  방향성배열을 opt라고 하자. opt[N][M]의 값을 비교해서 그 방향을 계속 따라간다.
10.왼쪽 위 대각선으로 이동한 경우가 문자열이 같았을때의 움직임이기 때문에 opt값이 1이면 배열을 움직이고, i,j값에 해당하는 문자열을 출력한다.
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
void lcs(string& x, string& y, string& z, vector<vector<int>>& D, vector<vector<int>>& P);
void move(int row, int col, vector<vector<int>>& D, vector<vector<int>>& opt);
string x;
string y;
string z;
int main()
{

    cin >> x;
    cin >> y;
    vector<vector<int>> D(x.size() + 1, vector<int>(y.size() + 1, 0));
    vector<vector<int>> opt(x.size() + 1, vector<int>(y.size() + 1, 0));
    lcs(x, y, z, D, opt);
    cout << D[x.size()][y.size()] << "\n";
    move(x.size(), y.size(), D, opt);
    for (int i = 0; i < x.size(); i++)
    {
        for (int j = 0; j < y.size(); j++)
        {
            cout << D[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < x.size(); i++)
    {
        for (int j = 0; j < y.size(); j++)
        {
            cout << opt[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = z.size() - 1; i >= 0; i--)
    {
        cout << z[i];
    }
}
void lcs(string& x, string& y, string& z, vector<vector<int>>& D, vector<vector<int>>& Y)
{
    int cnt = 0;
    for (int i = 1; i <= x.size(); i++)
    {
        for (int j = 1; j <= y.size(); j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                D[i][j] = D[i - 1][j - 1] + 1;
                Y[i][j] = 1; //대각선으로 이동할때 1
                // z.push_back(x[i-1]);
            }
            else
            {
                D[i][j] = max(D[i - 1][j], D[i][j - 1]);
                if (D[i][j] == D[i - 1][j]) //아래
                {
                    Y[i][j] = 2;
                }
                else //오른쪽 값을 넣었을때
                {
                    Y[i][j] = 3;
                }
            }
        }
    }
}
void move(int row, int col, vector<vector<int>>& D, vector<vector<int>>& opt)
{
    // 1은 왼쪽위 대각선으로 이동 2는 위로 이동 3은 왼쪽으로 이동
    if (opt[row][col] == 1)
    {
        z.push_back(x[row - 1]);
        move(row - 1, col - 1, D, opt);
    }
    else if (opt[row][col] == 2)
    {
        move(row - 1, col, D, opt);
    }
    else if (opt[row][col] == 3)
    {
        move(row, col - 1, D, opt);
    }
}