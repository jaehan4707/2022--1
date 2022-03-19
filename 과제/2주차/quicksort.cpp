#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void quicksort(int low, int high, vector<int>& S);
void partition(int low, int high, int& pivotpoint, vector<int>& S);
int cnt = 0;
int main()
{
    int n;
    cin >> n;
    vector<int> S(n);
    for (int i = 0; i < n; i++)
    {
        cin >> S[i];
    }
    quicksort(0, n - 1, S);
    cout << cnt << "\n";
    for (int i = 0; i < n; i++)
    {
        if (i <= n - 2)
        {
            cout << S[i] << " ";
        }
        else
            cout << S[i];
    }
}
void quicksort(int low, int high, vector<int>& S)
{
    int pivo;
    if (low < high)
    {
        partition(low, high, pivo, S);
        quicksort(low, pivo - 1, S);
        quicksort(pivo + 1, high, S);
    }
}
void partition(int low, int high, int& pivotpoint, vector<int>& S)
{
    int pivoitem = S[low];

    int j = low;
    for (int i = low + 1; i <= high; i++)
    {
        if (S[i] < pivoitem)
        {
            j++;
            swap(S[i], S[j]);
        }
    }
    pivotpoint = j;
    swap(S[low], S[pivotpoint]);
    cnt++;
    if (cnt == 1)
    {
        for (int i = 0; i <= high; i++)
        {
            if (i == high)
            {
                cout << S[i];
            }
            else
                cout << S[i] << " ";
        }
        cout << "\n";
    }
}