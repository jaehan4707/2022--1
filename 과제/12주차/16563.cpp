#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
using namespace std;
#define Max 5000000
vector<int> include(Max + 1);
int main()
{
    int N;
    scanf("%d", &N);
    //int num = 0;
    int max = 0;
    vector<int>num(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
        if (max < num[i])
            max = num[i];
    }
    for (int i = 0; i <= max; i++)
    {
        include[i] = i;
    }
    for (int j = 2; j <= sqrt(max); j++)
    {
        if (include[j] == j)
        {
            for (int k = j * j; k <= max; k += j)
            {
                if (include[k] == k)
                    include[k] = j;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        // scanf("%d",&num);
        while (1)
        {
            if (num[i] == 1)
            {
                break;
            }
            // cout << include[num] << " "; //
            printf("%d ", include[num[i]]);
            num[i] = num[i] / include[num[i]];
        }
        printf("\n");
    }
}