/*2주차 과제 첫번째 피보나치배열, 공간복잡도가 1이고 시간복잡도가 n인*/
#include <iostream>
#include <vector>
using namespace std;

int fibo(int n, int max)
{
    int a = 0, b = 1, c;
    if (n < 2)
    {
        return n;
    }
    else
    {
        for (int i = 2; i <= n; i++)
        {
            c = (a + b) % max; // a=F[i-2] b=F[i-1];
            a = b;
            b = c;
        }
        return c; //첫코드 c=(a+b) return c%max
    }
}
int main()
{
    int n, max;
    cin >> n;
    cin >> max;
    cout << fibo(n, max);
}