//���̱��ϴ°�
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
    unsigned long long int max = 0; //�ִ밪 ã���� 0 �� �� �ּڰ� ã���� ū�ų������
    unsigned long long int maxnum = 0;
    for (unsigned long long int i = 2; i <= 5; i++)
    {
        collaz(i);
        a.push_back(1);
        if (max < a.size() && maxnum < i) // max������ Ŀ���ϰ� ���� i������ ����i�� �� Ŀ����
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
        if (n % 2 == 0) //¦��
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
        { //Ȧ��
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