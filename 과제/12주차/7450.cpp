#include <iostream>
#include <vector>
#include <algorithm>
/*
가방 무게를 큰 순서대로 정렬한다.
그리고 가방에 큰 순서대로 담고 담지못한다면 다음걸 담고 그렇게 하는식으로 풀면 될거같은데?
*/
using namespace std;
int big(int i, int j)
{
    return i > j;
}
int N, W, totweight = 0;
vector<int> profit;
vector<int>include;
int Count = 0;
int bag = 0;
int main()
{
    cin >> N;
    cin >> W;
    profit.resize(N, 0);
    include.resize(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> profit[i];
    }
    sort(profit.begin(), profit.end(), big); //물건의 무게가 큰 순서대로 정렬함.
    int begin = 0;
    int end = N - 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = N - 1; j >= 0; j--)
        {
            if (profit[i] + profit[j] <= W) //가장 큰 무게와 가장 작은 무게를 담을 수 있다면 넣어줌.
            {
                bag++;
                N = N - 1; //담았다면 가장 끝에 꺼를 제외시켜야하기때문에 값을 하나 빼줌.
                break;
            }
            else if (profit[i] <= W) //만약 가장 큰 무게와 가장 작은 무게를 담을 수 없지만, 가장 큰 것만 담을수 있다면? 담아줌.
            {
                bag++;
                break;
            }
        }
    }
    cout << bag;
}