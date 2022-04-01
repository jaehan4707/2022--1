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
    cout << B[k]; // B[n][k] 출력
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
            if (j == 0 || j == i) // nco or NcK일 경우는 1임.
            {
                B[j] = 1;
                b = 1; //첫값 저장.
                //cout << B[j] << " ";
            }
            else
            {
                //이전에 저장된 B배열의 값을 저장할필요가 있음. B배열이 리셋되기때문에
                a = b;                //예전B[j]의 값을 저장
                b = B[j];             //예전B[j]의 값을 a에 넘겨주기 위해 따로 저장.
                B[j] = (a + b) % Max; // a는 예전B[j]의 값
                //cout << B[j] << " ";
            }
        }
       // cout << "\n";
    }
    return B[k];
}
*/