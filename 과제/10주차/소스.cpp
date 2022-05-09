#include <iostream>
#include <string>
#include <vector>

/**
 * <n-queens problem>
 * 체스판에 n개의 퀸이 있을때
 * 서로를 위협하지 않고 둘 수 있는 경우의 수를 구하시오.
 * 백트래킹 문제
 * 트리를 생성해야한다.
 */

using namespace std;

// 자료형 선언

// 전역변수 선언
int n;                        // 체스보드의 크기
int cnt;                      // 가능한 경우의 수
int col[12];                  // 최대 12까지 계산
int result[12];               // 각 위치값 저장하는 배열
unsigned long long max_value; // 문자열을 정수형으로 저장하기 때문에 아주 큰 자료형을 선언해줘야함

// 함수 원형 선언
void queens(int i);
bool promising(int i);

// 메인함수
int main()
{
    cin >> n;
    queens(0);
    printf("%d\n", cnt);
    cout << max_value;
    // cout << to_string(max_value);
}
// 함수 구현
void queens(int i)
{
    int j;
    // int max = 0;
    if (promising(i))
    {
        if (i == n) // 리프노드까지 온 경우
        {
            unsigned long long tmp;
            string result;
            for (int x = 1; x <= n; x++)
            {
                result += to_string(col[x]); // 정수형을 문자열 형태로 바꿔주는 함수
            }
            tmp = stoll(result); // 문자열을 long long 정수 형태로 바꿔주는 함수
            if (max_value < tmp)
            {
                // 최대값 찾는 과정
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