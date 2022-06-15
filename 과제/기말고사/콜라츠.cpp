//길이구하는거
/*
#include <iostream>
#include <vector>

using namespace std;
int Cnt;
void collaz(unsigned long long int n);
vector<unsigned long long int> a(0);
int main()
{
    int n;
    unsigned long long int max = 0; //최대값 찾을땐 0 넣 고 최솟값 찾을땐 큰거넣으면됨
    unsigned long long int maxnum = 0;
    for (unsigned long long int i = 2; i <= 5; i++)
    {
        collaz(i);
        a.push_back(1);
        if (max < a.size() && maxnum < i) // max값보다 커야하고 원래 i값보다 현재i가 더 커야함
        {
            max = a.size();
            maxnum = i;
        }
        for (int j = 0; j < a.size(); j++)
        {
            cout << a[j] << " ";
        }
        cout << endl;
        a.resize(0, 0);
    }
    cout << maxnum << " " << max<<" ";
    cout << Cnt;
}
void collaz(unsigned long long int n)
{
    if (n != 1)
    {
        if (n % 2 == 0) //짝수
        {
            a.push_back(n);            
            collaz(n / 2);
            if (n / 2 == 5 || n/2==17)
            {
                Cnt++;
                return;
            }
        }
        else
        { //홀수
            a.push_back(n);
            collaz(n * 3  - 1);
            if (n * 3 - 1 == 5 || n * 3 + 1 == 17)
            {
                Cnt++;
                return;
            }
        }
    }
}
*/