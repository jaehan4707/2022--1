/*
#include <iostream>
#include <vector>

using namespace std;
void makeary(int row, int col, vector<vector<int>>& ary);
void printary(int row, int col, vector<vector<int>>& ary);
void combine(int n, vector<vector<int>>& M, vector<vector<int>>& m11, vector<vector<int>>& m12, vector<vector<int>>& m21, vector<vector<int>>& m22);
void partition(int n, vector<vector<int>>& M, vector<vector<int>>& m11, vector<vector<int>>& m12, vector<vector<int>>& m21, vector<vector<int>>& m22);
void strassen(int n, vector<vector<int>>& a, vector<vector<int>>& b, vector<vector<int>>& c);
void madd(int n, vector<vector<int>>& a, vector<vector<int>>& b, vector<vector<int>>& c);
void msub(int n, vector<vector<int>>& a, vector<vector<int>>& b, vector<vector<int>>& c);
void mmult(int n, vector<vector<int>>& a, vector<vector<int>>& b, vector < vector<int>>& c);
bool twon(int num) {
    return (num & (num - 1)) == 0;
}
int threshold, cnt = 0, k = 1;
int main()
{
    // a,b�� �Է¹ް� ��Ʈ�� �˰��� ����
    int n;
    cin >> n >> threshold;
    if (!twon(n)) {
        while (k < n)
            k *= 2;

        vector<vector<int>> a(k, vector<int>(k, 0));
        vector<vector<int>> b(k, vector<int>(k, 0));
        vector<vector<int>> c(k, vector<int>(k, 0));
        makeary(n, n, a);
        makeary(n, n, b);
        strassen(k, a, b, c);
        cout << cnt << "\n";
        printary(n, n, c);
    }
    else
    {
        vector<vector<int>> a(n, vector<int>(n, 0));
        vector<vector<int>> b(n, vector<int>(n, 0));
        vector<vector<int>> c(n, vector<int>(n, 0));
        makeary(n, n, a);
        makeary(n, n, b);
        strassen(n, a, b, c);
        cout << cnt << "\n";
        printary(n, n, c);
    }
    //ut << "\n";


}
void partition(int n, vector<vector<int>>& M, vector<vector<int>>& m11, vector<vector<int>>& m12, vector<vector<int>>& m21, vector<vector<int>>& m22) // 4����ϱ�
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            m11[i][j] = M[i][j];
            m12[i][j] = M[i][j + n];
            m21[i][j] = M[i + n][j];
            m22[i][j] = M[i + n][j + n];
        }
    }
}
void strassen(int n, vector<vector<int>>& a, vector<vector<int>>& b, vector<vector<int>>& c)
{
    cnt++;
    int m;
    m = n / 2;
    vector<vector<int>> a11(m, vector<int>(m, 0));
    vector<vector<int>> a12(m, vector<int>(m, 0));
    vector<vector<int>> a21(m, vector<int>(m, 0));
    vector<vector<int>> a22(m, vector<int>(m, 0));

    vector<vector<int>> b11(m, vector<int>(m, 0));
    vector<vector<int>> b12(m, vector<int>(m, 0));
    vector<vector<int>> b21(m, vector<int>(m, 0));
    vector<vector<int>> b22(m, vector<int>(m, 0));

    vector<vector<int>> c11(m, vector<int>(m, 0));
    vector<vector<int>> c12(m, vector<int>(m, 0));
    vector<vector<int>> c21(m, vector<int>(m, 0));
    vector<vector<int>> c22(m, vector<int>(m, 0));

    vector<vector<int>> M1(m, vector<int>(m, 0));
    vector<vector<int>> M2(m, vector<int>(m, 0));
    vector<vector<int>> M3(m, vector<int>(m, 0));
    vector<vector<int>> M4(m, vector<int>(m, 0));

    vector<vector<int>> M5(m, vector<int>(m, 0));
    vector<vector<int>> M6(m, vector<int>(m, 0));
    vector<vector<int>> M7(m, vector<int>(m, 0));
    vector<vector<int>> L(m, vector<int>(m, 0));
    vector<vector<int>> R(m, vector<int>(m, 0));
    if (n <= threshold) //�Ӱ����� ���� ��
    {
        mmult(n, a, b, c);
    }
    else //�������� �ɰ��� a 4��� b 4��� c 4���
    {
        partition(m, a, a11, a12, a21, a22);
        partition(m, b, b11, b12, b21, b22);

        madd(m, a11, a22, L);
        madd(m, b11, b22, R);
        strassen(m, L, R, M1); //m1

        madd(m, a21, a22, L); // m2
        strassen(m, L, b11, M2);

        msub(m, b12, b22, L); //m3
        strassen(m, a11, L, M3);

        msub(m, b21, b11, R); //m4
        strassen(m, a22, R, M4);

        madd(m, a11, a12, L);//m5
        strassen(m, L, b22, M5);

        msub(m, a21, a11, L);
        madd(m, b11, b12, R);
        strassen(m, L, R, M6);

        msub(m, a12, a22, L);
        madd(m, b21, b22, R);
        strassen(m, L, R, M7);

        madd(m, M1, M4, L);  //c11
        msub(m, L, M5, R);
        madd(m, R, M7, c11);

        madd(m, M3, M5, c12); //c12

        madd(m, M2, M4, c21); //c21

        madd(m, M1, M3, L); //c22
        msub(m, L, M2, R);
        madd(m, R, M6, c22);

        combine(m, c, c11, c12, c21, c22);
    }
}
void combine(int m, vector<vector<int>>& M, vector<vector<int>>& m11, vector<vector<int>>& m12, vector<vector<int>>& m21, vector<vector<int>>& m22)
{
    // 4������� �ɰ��� ���� �� �ٽ���ħ
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            M[i][j] = m11[i][j];
            M[i][j + m] = m12[i][j];
            M[i + m][j] = m21[i][j];
            M[i + m][j + m] = m22[i][j];
        }
    }
}
void makeary(int row, int col, vector<vector<int>>& ary) //�迭 ����
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> ary[i][j];
        }
    }
}
void printary(int row, int col, vector<vector<int>>& ary) //�迭 ���
{
    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < col; j++)
        {
            if (j < col - 1)
            {
                cout << ary[i][j] << " ";
            }
            else
                cout << ary[i][j];
        }
        if (i < row - 1)
        {
            cout << "\n";
        }
    }
}
void madd(int n, vector<vector<int>>& a, vector<vector<int>>& b, vector<vector<int>>& c) //����� ���ϱ�
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}
void msub(int n, vector<vector<int>>& a, vector<vector<int>>& b, vector<vector<int>>& c) //����� ����
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
}
void mmult(int n, vector<vector<int>>& a, vector<vector<int>>& b, vector < vector<int>>& c) //��� ���ϱ�
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                c[i][j] = c[i][j] + a[i][k] * b[k][j];
            }
        }
    }
}
*/