#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int start, finish, num;
map<int, int> m;
int cc;
//순환하는수를 찾는것. 규칙바꿔도 성립.
int main()
{
    cin >> start >> finish;

    for (int i = start; i <= finish; i++)
    {
        int num = i;
        while (num != 1)
        {
            if (m.find(num) != m.end()) //만약 이미 있는거라면 ++하고 종료함.
            {
                cc++;
                break;
            }
            m.insert(make_pair(num, 0));
            if (num % 2 == 0) //짝수
            {
                num = num / 2;
            }
            else
            { //홀수
                num = num * 3 - 1;
            }
        }
        m.clear();
    }
    cout << cc;
}