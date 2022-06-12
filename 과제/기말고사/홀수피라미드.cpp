/*
홀수 피라미드 문제
1층에는 1개 , 2층에는 3개 3층에는 5개 4층에는 7개 등등 등차수열로 증가함.
n층은 1+2*(n-1)개의 사다리가 나올것이다.

왼쪽은 층의 원소수 * 2만큼 차이난다.
4층일때 원소의 갯수는 1+3+5+7 = 16
3층일때 원소의 갯수는 9  층의제곱수만큼 원소가 있다.
만약의 5층이면 1+2*n()

왼쪽 오른쪽 숫자 출력.
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
        cin >> high; // high층일때를 구해야함.
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