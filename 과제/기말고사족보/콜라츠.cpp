#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int start, finish, num;
map<int, int> m;
int cc;
//��ȯ�ϴ¼��� ã�°�. ��Ģ�ٲ㵵 ����.
int main()
{
    cin >> start >> finish;

    for (int i = start; i <= finish; i++)
    {
        int num = i;
        while (num != 1)
        {
            if (m.find(num) != m.end()) //���� �̹� �ִ°Ŷ�� ++�ϰ� ������.
            {
                cc++;
                break;
            }
            m.insert(make_pair(num, 0));
            if (num % 2 == 0) //¦��
            {
                num = num / 2;
            }
            else
            { //Ȧ��
                num = num * 3 - 1;
            }
        }
        m.clear();
    }
    cout << cc;
}