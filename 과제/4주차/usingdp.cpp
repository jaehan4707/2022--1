/*
#include <iostream>
#include <vector>

using namespace std;
vector<int>F;
int fibo(int n)
{
    if (n < 2)
    {
        F[n] = n;
    }
    else
    {
        if (F[n] == -1)
            F[n] = fibo(n - 2) + fibo(n - 1);
        else
            return F[n];
    }
    return F[n];
}
int main()
{
    int n;
    cin >> n;
    F.resize(n + 1, -1);
    cout << fibo(n);
}
*/