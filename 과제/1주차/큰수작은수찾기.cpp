#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> ary(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ary[i];
    }
    sort(ary.begin(), ary.end());
    if (n == 1) //n�� �ϳ��϶��� �ڱ��ڽ��� �ּҰ����� �ִ밪
    {
        cout << ary[0] << "\n"
            << ary[0] << "\n";
    }
    else
    {
        cout << ary[0] << "\n"
            << ary[n - 1] << "\n";
    }
}