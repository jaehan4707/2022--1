/*2���� ���� ù��° �Ǻ���ġ�迭, �������⵵�� 1�̰� �ð����⵵�� n��*/
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
        return c; //ù�ڵ� c=(a+b) return c%max
    }
}
int main()
{
    int n, max;
    cin >> n;
    cin >> max;
    cout << fibo(n, max);
}