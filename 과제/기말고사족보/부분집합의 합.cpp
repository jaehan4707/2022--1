//total은 현재 내가 지나쳐온 원소들을 전체원소의 합에서 빼는것.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int n, W;
int sum = 0;
int total = 0;
int cnt = 0;
vector<int> seq;
vector<int> sub;
int cc;
void subset(int i, int weight, int total);
bool promising(int i, int weight, int total);
vector<int> include;
vector<string> str;
int big(int i, int j)
{
    return i > j;
}
int main()
{
    cin >> n >> W;
    // vector<int>sum(n, 0);
    sub.resize(n + 1);
    include.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> sub[i];
        total = total + sub[i];
    }
    sort(sub.begin() + 1, sub.end(), big);
    for (int i = 1; i <= sub.size() - 1; i++)
    {
        cout << sub[i] << " ";
    }
    cout << endl;
    subset(0, 0, total);
    cout << cnt << endl;
    /*
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == "")
            cout << endl;
        else
        {
            if (str[i + 1] == "")
                cout << str[i];
            else
                cout << str[i] << " ";
        }
    }
    */
    //cout << cc << endl;
}
void subset(int i, int weight, int total)
{
    if (promising(i, weight, total))
    {
        if (weight == W)
        {
            // cc++;
            cnt++;
            string ab = "";
            for (int j = 1; j <= i; j++)
            {
                if (include[j] == 1)
                    // ab += to_string(sub[j]);
                    // str[cnt].push_back(ab[j-1]);
                    str.push_back(to_string(sub[j]));
                // ab += to_string(sub[include[j]]); //ab에 저장됨.
                // str[cnt].push_back(to_string(include[i]));
                // cout << include[j] << " ";
                // str[cnt].push_back(ab);
            }
            str.push_back("");
        }
        else
        {
            include[i + 1] = true;                                  // 더할거라는 뜻
            subset(i + 1, weight + sub[i + 1], total - sub[i + 1]); //더했고 다음 단계로 진행 만약 재귀를 탈출한다면

            include[i + 1] = false;                                 //안더한다는 뜻.
            subset(i + 1, weight, total - sub[i + 1]);              //안더하고 다음 단계로 진행
            if (i + 1 == 2)
            {
                //cout<<"안담앗을때 검사" << "" << weight<<"" << total<<endl;
            }
        }
        if (i + 1 == 3)
        {
            cout << "검사" << "" << weight << "" << total << endl;
        }
    }
    if (i + 1 == 3)
    {
        cout << "검사" << "" << weight << "" << total << endl;
    }
    // cc++;
}
bool promising(int i, int weight, int total)
{
    return (weight + total >= W) && (weight == W || weight + sub[i + 1] <= W);
    //지금 내가 더한 weight값인 weight값+ 남은 weight값인 total값이 내가 구하려는 W보다 작다면 더 볼필요가 없음.
    // 지금 내가 더한 weight와 다음 더할려는 weight가 W를 넘는다면 탐색종료
}