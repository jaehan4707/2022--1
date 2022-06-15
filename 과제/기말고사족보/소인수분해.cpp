#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <map>
using namespace std;
#define Max 5000000
vector<int> include(Max + 1);
int Cnt;
//숫자 범위 내의 소인수 개수가 2개인거 찾기.
int main()
{
    // scanf("%d", &N);
    int start, finish;
    cin >> start >> finish;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // int num = 0;
    int max = 0;
    vector<int> num;
    int size = finish - start + 1;
    num.resize(size, 0);
    map<int, int> m;
    //범위 내의
    for (int i = 0; i < size; i++) // start~finish까지 최대는 그럼 finish가 될거다.
    {
        num[i] = start;
        start++;
    }
    for (int i = 0; i <= finish; i++)
    {
        include[i] = i;
    }
    for (int j = 2; j <= sqrt(finish); j++) //배수찾기
    {
        if (include[j] == j)
        {
            for (int k = j * j; k <= finish; k += j)
            {
                if (include[k] == k)
                    include[k] = j;
            }
        }
    }
    for (int i = 0; i < size; i++)
    {
        // scanf("%d",&num);
        // cout << "원소 : " << num[i] << endl;
        while (1)
        {
            if (num[i] == 1)
            {
                break;
            }

            // printf("%d ", include[num[i]]);
            if (m.find(include[num[i]]) == m.end()) // map에 없다면
            {
                m.insert(make_pair(include[num[i]], i));
            }
            num[i] = num[i] / include[num[i]];
        }
        if (m.size() == 2) //소인수개수가 2인경우
        {
            Cnt++;
        }
        m.clear();
    }
    cout << Cnt << endl;
}