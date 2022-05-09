#include <iostream>
#include <string>
#include <vector>

/**
 * <n-queens problem>
 * ü���ǿ� n���� ���� ������
 * ���θ� �������� �ʰ� �� �� �ִ� ����� ���� ���Ͻÿ�.
 * ��Ʈ��ŷ ����
 * Ʈ���� �����ؾ��Ѵ�.
 */

using namespace std;

// �ڷ��� ����

// �������� ����
int n;                        // ü�������� ũ��
int cnt;                      // ������ ����� ��
int col[12];                  // �ִ� 12���� ���
int result[12];               // �� ��ġ�� �����ϴ� �迭
unsigned long long max_value; // ���ڿ��� ���������� �����ϱ� ������ ���� ū �ڷ����� �����������

// �Լ� ���� ����
void queens(int i);
bool promising(int i);

// �����Լ�
int main()
{
    cin >> n;
    queens(0);
    printf("%d\n", cnt);
    cout << max_value;
    // cout << to_string(max_value);
}
// �Լ� ����
void queens(int i)
{
    int j;
    // int max = 0;
    if (promising(i))
    {
        if (i == n) // ���������� �� ���
        {
            unsigned long long tmp;
            string result;
            for (int x = 1; x <= n; x++)
            {
                result += to_string(col[x]); // �������� ���ڿ� ���·� �ٲ��ִ� �Լ�
            }
            tmp = stoll(result); // ���ڿ��� long long ���� ���·� �ٲ��ִ� �Լ�
            if (max_value < tmp)
            {
                // �ִ밪 ã�� ����
                max_value = tmp;
            }
            cnt++;
        }
        else
        {
            for (j = 1; j <= n; j++)
            {
                col[i + 1] = j;
                queens(i + 1);
            }
        }
    }
}
bool promising(int i)
{
    int k = 1;
    bool flag = true;

    while (k < i && flag)
    {
        if ((col[i] == col[k]) || (abs(col[i] - col[k]) == i - k))
            flag = false;
        k++;
    }
    return flag;
}