/*
M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
void Eratos(int, int);

int main()
{

    int m, n;
    cin >> m >> n;

    Eratos(n, m);

    return 0;
}

void Eratos(int n, int m)
{

    bool* PrimeArray = new bool[n + 1];

    for (int i = 2; i <= n; i++)
        PrimeArray[i] = true; //처음엔 모두 소수로 봄

    PrimeArray[1] = false;

    for (int i = 2; i * i <= n; i++)
    { // n에 루트씨운거 이하의 값들 중
      //소수만 판별해도 됨
      //예를들어 n이 120이면
      // 11*11>120 이므로
      // 11보다 작은 수의 배수들만 지워도 된다

        if (PrimeArray[i])
        { // PrimeArray[i]가 false이면
          // i는 이미 소수가 아니므로 i의 배수 역시 소수가 아니게 된다
          //그러므로 검사할 필요도없다
            for (int j = i * i; j <= n; j += i)
            { // i*k(k<i)까지는 이미 검사되었으므로
              // j의 시작값은 i*2에서 i*i로 개선할 수 있다
                PrimeArray[j] = false;
            }
        }
    }

    for (int i = m; i <= n; i++)
    {
        if (PrimeArray[i])
            cout << i << "\n";
    }
}