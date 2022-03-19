/*2주차 과제  2번째 merge sort */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void mergesort2(int low, int high, vector<int>& S);
void merge2(int low, int mid, int high, vector<int>& S);
int n;
// mergesort2(1, n);
int cnt = 0;
int main()
{
    cin >> n;
    vector<int> S(n);
    for (int i = 0; i < n; i++)
        cin >> S[i];
    /*
for (int i = 0; i < n; i++)
    cout << ary[i] << " ";
cout << endl;
*/
    mergesort2(0, n - 1, S);
    cout << cnt << "\n";
    for (int i = 0; i < n; i++)
        cout << S[i] << " ";
}
void mergesort2(int low, int high, vector<int>& S)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergesort2(low, mid, S);      //절반으로 쪼갬  mid기준으로 왼쪽으로 쪼갬
        mergesort2(mid + 1, high, S); // mid기준으로 오른쪽으로 쪼갬
        merge2(low, mid, high, S);    // merge소트실행
    }
}
void merge2(int low, int mid, int high, vector<int>& S)
{
    int i = low, j = mid + 1, k = 0;
    cnt++;
    vector<int> U(high - low + 1);

    while (i <= mid && j <= high)
    {
        if (S[i] < S[j])
            U[k++] = S[i++];
        else
            U[k++] = S[j++];
    }
    if (i > mid) // 왼쪽은 검사 다했으니 -- 오른쪽꺼 다 떙겨와라 이런느낌
    {
        while (j <= high)
            U[k++] = S[j++];
    }
    else // if(i<=mid) 왼쪽 아직 정렬안햇으니 왼쪽하고
    {
        while (i <= mid)
            U[k++] = S[i++];
    }
    for (int t = low; t <= high; t++)
        S[t] = U[t - low];
}