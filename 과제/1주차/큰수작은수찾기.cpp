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
    if (n == 1) //n이 하나일때는 자기자신이 최소값이자 최대값
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