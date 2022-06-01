/*
주어진 N개 중에서 소수가 몇개인지 찾아서 출력하는 프로그램을 작성하시오
입력 첫줄에 수의 개수 N이 주어진다. N은 100이하이다. 다음으로 N개의 수가 주어지는데 수는 1,000이하의 자연수
소스의 개수를 출력

소수는 자기자신과 1만을 약수로 가지는 수.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool num(int n);
int main()
{
    int n, N, Cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int N;
        cin >> N;
        if (num(N) == 1) //소수인지 판단해보자.
        {
            //cout<<N<<endl;
            Cnt++;
        }
    }
    cout << Cnt;
}
bool num(int n) //소수인지 판단하는것.
{
    bool flag = true;
    if (n == 1)
    {
        return false;
    }
    for (int i = 2; i < n; i++) // 1과 자기자신을 제외한 수로는 나눠지면 안됨.
    {
        if (n % i == 0) //약수가 하나라도 있으면 안됨.
        {
            flag = false;
            break;
        }
    }
    return flag;
}