/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#define MAX 200000
typedef unsigned long long Longint;
Longint binomial(int n, int k, int B[]);
int n, k, Max;
int B[MAX];
int main()
{
    scanf("%d %d %d", &n, &k, &Max);
    binomial(n, k, B);
    if (k > n / 2)
    {
        k = n - k;
    }
    cout << B[k]; // B[n][k] ���
}
Longint binomial(int n, int k, int B[]) // n=4 k=2
{
    int a, b;
    if (n == k || k == 0 || n == 0)
    {
        B[k] = 1;
        return B[k];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= min(i, k); j++)
        {
            if (j == 0 || j == i) // nco or NcK�� ���� 1��.
            {
                B[j] = 1;
                b = 1; //ù�� ����.
                //cout << B[j] << " ";
            }
            else
            {
                //������ ����� B�迭�� ���� �������ʿ䰡 ����. B�迭�� ���µǱ⶧����
                a = b;                //����B[j]�� ���� ����
                b = B[j];             //����B[j]�� ���� a�� �Ѱ��ֱ� ���� ���� ����.
                B[j] = (a + b) % Max; // a�� ����B[j]�� ��
                //cout << B[j] << " ";
            }
        }
       // cout << "\n";
    }
    return B[k];
}
*/