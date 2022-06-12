/*
Ȧ�� �Ƕ�̵� ����
1������ 1�� , 2������ 3�� 3������ 5�� 4������ 7�� ��� ���������� ������.
n���� 1+2*(n-1)���� ��ٸ��� ���ð��̴�.

������ ���� ���Ҽ� * 2��ŭ ���̳���.
4���϶� ������ ������ 1+3+5+7 = 16
3���϶� ������ ������ 9  ������������ŭ ���Ұ� �ִ�.
������ 5���̸� 1+2*n()

���� ������ ���� ���.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
vector<unsigned long long int> l;
vector<unsigned long long int> r;
void solve(int high);
int main()
{
    int T;
    cin >> T;
    unsigned long long int high;
    vector<int> H;
    unsigned long long int m = 0;
    H.resize(T);
    long long int left, right;
    for (int i = 1; i <= T; i++)
    {
        cin >> high; // high���϶��� ���ؾ���.
        if (high == 1)
        {
            left = 1, right = 1;
        }
        else
        {
            left = (high - 1) * (high - 1) * 2 + 1;
            right = 2 * (high) * (high)-1;
        }
        cout << "#" << i << " " << left << " " << right << endl;
    }
}