/*
약수 구하기
양수 A가 N의 진짜 약수가 되려면 N이 A의 배수이고, A가 1과 N이 아니어야한다. 어떤 수 N의 진짜 약수가 모두 주어질 때, N을 구하는 프로그램을 작성하시오.

첫째줄에 N의 진짜 약수의 개수가 주어진다. 이 개수는 50보다 작거나 같은 자연수이다. 둘째 줄에는 N의 진짜 약수가 주어진다. 중복되지 않는다.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int com(int i, int j)
{
    return i < j;
}
int main()
{
    int n, result;
    cin >> n;
    vector<int> num;
    for (int i = 0; i < n; i++)
    {
        int N;
        cin >> N;
        num.push_back(N);
    }
    //입력 받은 num을 오름차순으로 정렬
    sort(num.begin(), num.end(), com);
    if (num.size() != 1) //
    {
        result = num[0] * num[num.size() - 1];
    }
    else
    { //약수의 개수가 홀 수라면
        result = num[0] * num[0];
    }
    cout << result;
}