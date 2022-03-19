#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k, m; //차원
    cin >> n >> k >> m;
    // vector<vector<int>> A(n, vector<int>(k, 0)); // n*k
    // vector<vector<int>> B(k, vector<int>(m, 0)); // k*m
    // vector<vector<int>> C(n, vector<int>(m, 0)); // n*m;
    int A[n][k];
    int B[k][m];
    int C[n][m];

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < k; j++)
        {
            A[i][j] = 0;
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < k; i++)
    {

        for (int j = 0; j < m; j++)
        {
            B[i][j] = 0;
            cin >> B[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {
            C[i][j] = 0;
            for (int x = 0; x < k; x++)
            {
                C[i][j] += A[i][x] * B[x][j];
            }
            if (j < m - 1) //끝에수 아닐 때는 한칸 space바
            {
                cout << C[i][j] << " ";
            }
            else
            {
                cout << C[i][j]; //끝에 있는 수일떈 공백표시 x
            }
        }
        cout << "\n"; //행 바뀔때 줄바꿈
    }
    return 0;
}