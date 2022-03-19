#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, x = 0, count = 0, location = -1;
    cin >> n;
    vector<int> ary(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ary[i];
        if (ary[i] == i)
            x = i;
    }
    int mid = 0, low = 0, high = n - 1;
    while (location == -1 && low <= high) //�� ���� ��ã�������� �ذ��ؾ���.
    {
        mid = (low + high) / 2;
        if (x == ary[mid])
        {
            location = mid;
        }
        else if (x < ary[mid])
        {
            high = mid - 1;
        }
        else if (x > ary[mid])
        {
            low = mid + 1;
        }
        count++;
    }
    cout << location << "\n"
        << count;
    return 0;
}
