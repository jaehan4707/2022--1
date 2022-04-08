/*
����κа��뼭�� ����(LCS) ����κа��뼭���̶�? �κм����߿��� ���� ����� ã�� ����
DP�� ���� ����  ������ ���Ȱ��� �����ϰ� ����� ���� �״�� ����� �����̴�.
�켱
1.���ڿ� x�� ���ڿ� y�� �Է¹���.
2.�κм����� ���̸� ������ 2���� �迭�� ����. �� �ڵ忡���� �� �迭 �̸��� D�̴�.
3.���ڿ��� ���ؾ���. 1���� ���ڿ� ������ for���� ����.
4.���� �񱳹��ڿ���  ���ٸ� i-1,j-1�� �κм������� i,j�ε����� ���ڰ� �߰��Ȱ��̹Ƿ�. D[i][j]=[D[i-1][j-1]+1�̵ȴ�.
5.���� �񱳹��ڿ��� �ٸ��ٸ� �� i,j������ �ִ� ���ڿ������� ���� ���� ���ڿ������� �״�� �޾� ������ �ȴ�.  \
i,j�� ���� �迭�� D[i-1][j] �� D[i][j-1]�̴�.  �� �߿��� ū ���� �־��ָ� �ȴ�.
6.�̷��� �־��ָ� ���⼭ n�� x���ڿ��� ũ��, M�� y���ڿ��� ũ���̴�. D[N][M]�� ���� ū �κм����� ������ �����ϰԵȴ�.
7.�κм����� ���̸� �������� �� ���ڿ��� ����� �ؾ��Ѵ�. �� �� ���̴� ����� ����������̴�.
8.�����������  ����ϱ� ���ؼ� ���� ���⼺?�� �ο��ߴ�.  ���⼺�迭�� D�迭 ó�� 2���� �迭�� �����Ѵ�. D[i]][j]�� ���� �����ϴ� ������ 3���̴�.
�� ���ڿ��� ���� ��(���� �� �밢��), �� ���ڿ��� �ٸ� ��(��,�Ʒ�)�� ū �� ���� ������ ���� �ο��Ѵ�. ���� �� �밢�� 1 �Ʒ��� 2 ������ 3
9.�׷��� D[N][M]���� ����Ѵ�.  ���⼺�迭�� opt��� ����. opt[N][M]�� ���� ���ؼ� �� ������ ��� ���󰣴�.
10.���� �� �밢������ �̵��� ��찡 ���ڿ��� ���������� �������̱� ������ opt���� 1�̸� �迭�� �����̰�, i,j���� �ش��ϴ� ���ڿ��� ����Ѵ�.
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
                Y[i][j] = 1; //�밢������ �̵��Ҷ� 1
                // z.push_back(x[i-1]);
            }
            else
            {
                D[i][j] = max(D[i - 1][j], D[i][j - 1]);
                if (D[i][j] == D[i - 1][j]) //�Ʒ�
                {
                    Y[i][j] = 2;
                }
                else //������ ���� �־�����
                {
                    Y[i][j] = 3;
                }
            }
        }
    }
}
void move(int row, int col, vector<vector<int>>& D, vector<vector<int>>& opt)
{
    // 1�� ������ �밢������ �̵� 2�� ���� �̵� 3�� �������� �̵�
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