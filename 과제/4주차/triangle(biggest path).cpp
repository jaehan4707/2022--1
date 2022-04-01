#include <iostream>
#include <vector>

using namespace std;
int sum, h, x, y;
vector<int>p(1);
void big(vector<vector<int>>& a, vector<vector<int>>& b);
void MAX(vector<vector<int>>& a, int i, int j, int& x, int& y);
void path(vector<vector<int>>& b,vector<vector<int>>&a,int i, int j);
int main()
{
    cin >> h;
    vector<vector<int>> a(h+1, vector<int>(h+1, 0)); //
    vector<vector<int>> b(h+1, vector<int>(h+1, 0)); //
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> a[i][j];
            b[i][j] = a[i][j];
        }
    }
    big(a, b);
    p[0] = a[0][0];
    path(b, a, 0, 0);
    sum = b[0][0];
    cout << sum << endl;
    for (int i = 0; i < h; i++) //0,1,2,3 
    {
        if (i < h - 1) //h-1==3 0,1,2
            cout << p[i] << " ";
        else
            cout << p[i];
    }
}
void big(vector<vector<int>>& a, vector<vector<int>>& b)
{
    for (int i = h - 1; i >= 0; i--) //i=99 배열의 마지막부터 검사들어감
    {
        //if(i==0)
            //b[i][j]=
        for (int j = 0; j < i; j++)
        {
            if (i >= 1) //맨위에 전까지
            {
                MAX(b, i, j, x, y);
                b[i - 1][j] = b[i - 1][j] + b[x][y]; //
            }
        }
    }
}
void MAX(vector<vector<int>>& a, int i, int j, int& x, int& y)
{
    if (a[i][j] + a[i - 1][j] > a[i][j + 1] + a[i - 1][j]) //그냥 아래로 가는 경우가 더 클때
        x = i, y = j;
    else if (a[i][j] + a[i - 1][j] < a[i][j + 1] + a[i - 1][j]) //아래왼쪽으로 가는경우가 더 클때
        x = i, y = j + 1;
    else
        x = i, y = j + 1;
}
void path(vector<vector<int>>& b,vector<vector<int>>&a,int i, int j)
{
    int row = i;
    int col = j;
    if (i < h - 1)
    {
        if (b[i + 1][j] > b[i + 1][j + 1]) //아래로 가는경우가 클 때
        {
            p.push_back(a[i + 1][j]);
            path(b, a, i + 1, j);
        }
        else if (b[i + 1][j] <= b[i + 1][j + 1]) // 두개 비교해서 같으면 무조건 오른쪽으로 치우쳐야 하고 오른쪽이 크면 오른쪽으로 간다.
        {
            p.push_back(a[i + 1][j + 1]);
            path(b, a, i + 1, j + 1);
        }
    }
}