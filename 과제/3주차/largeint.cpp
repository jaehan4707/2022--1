/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void removezero(vector<int>& v);
void reverseString(string a, vector<int>& A);
void printary(vector<int>& A);
void ladd(vector<int>& a, vector<int>& b, vector<int>& c);
void lmult(vector<int>& a, vector<int>& b, vector<int>& c);
void pow_by_exp(vector<int>& u, int m, vector<int>& v);
void rem_by_exp(vector<int>& u, int m, vector<int>& v);
void divide(vector<int>& u, int m, vector<int>& a);
void prod(vector<int>& u, vector<int>& v, vector<int>& r);
int threshold, cnt = 0;
int main()
{
    cin >> threshold;
    string a;
    string b;
    cin >> a >> b;

    vector<int> A(a.length());
    vector<int> B(b.length());
    vector<int> C(max(a.length(), b.length()) + 1);
    int c = 0;
    reverseString(a, A);
    reverseString(b, B);
    prod(A, B, C);
    cout << cnt << "\n";
    printary(C);
    return 0;
}
void removezero(vector<int>& v)
{
    while (v.size() != 0 && v.back() == 0)
        v.pop_back();
}
void reverseString(string a, vector<int>& A)
{
    int c = 0;
    for (int i = a.length(); i > 0; i--)
    {
        A[c] = a[i - 1] - 48;
        c++;
    }
}
void printary(vector<int>& A)
{
    for (int i = A.size() - 1; i >= 0; i--)
    {
        cout << A[i];
    }
}
void carry(vector<int>& A)
{
    int carry = 0;
    for (int i = 0; i < A.size(); i++)
    {
        A[i] += carry;
        carry = A[i] / 10;
        A[i] = A[i] % 10;
    }
    if (carry != 0)
    {
        A.push_back(carry);
    }
}
void ladd(vector<int>& a, vector<int>& b, vector<int>& c)
{
    c.resize(max(a.size(), b.size()));
    fill(c.begin(), c.end(), 0);
    for (int i = 0; i < c.size(); i++)
    {
        if (i < a.size())
            c[i] += a[i];
        if (i < b.size())
            c[i] += b[i];
    }
    carry(c);
}
void lmult(vector<int>& a, vector<int>& b, vector<int>& c)
{
    c.resize(a.size() + b.size() - 1);
    fill(c.begin(), c.end(), 0);
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            c[i + j] += a[i] * b[j];
        }
    }
    carry(c);
}
void pow_by_exp(vector<int>& u, int m, vector<int>& v) // t1 2m t2
{
    if (u.size() == 0)
        v.resize(0);
    else
    {
        v.resize(u.size() + m);
        fill(v.begin(), v.end(), 0);
        copy(u.begin(), u.end(), v.begin() + m);
    }
}
void rem_by_exp(vector<int>& u, int m, vector<int>& v)
{
    if (u.size() == 0)
        v.resize(0);
    else
    {
        int k;
        if (m < u.size())
        {
            k = m;
            v.resize(k);
        }
        else
        {
            k = u.size();
            v.resize(k);
        }
        copy(u.begin(), u.begin() + k, v.begin()); // u�� v�� ����
        removezero(v);
    }
}
void divide(vector<int>& u, int m, vector<int>& a) // u�� �Ųٷ� �Է¹��� ����  m�� ������ ����. m�� ũ�⿡�� ���ݻ���  u�� 573,.. n/2 a=����迭
{
    if (u.size() == 0)
        a.resize(0);
    else
    {
        int k;
        if (m < u.size())
        {
            k = m;
            if (u.size() % 2 == 0) //¦���ϋ��� k
                a.resize(k);
            else //Ȧ���϶��� ���� �� ���� �ɰ���
                a.resize(k + 1);
        }
        else //���� �迭 ���� ����
        {
            k = u.size();
            a.resize(k);
        }
        copy(u.begin() + k, u.end(), a.begin()); // k�������� ������ a���ۿ� ����ִ´�.
        removezero(a);
    }
}
void prod(vector<int>& u, vector<int>& v, vector<int>& r) //
{
    cnt++;
    int n, m;

    n = max(u.size(), v.size()); //�ι迭�߿� ū �迭�� ũ�⸦ ����.
    vector<int> t1(n);
    vector<int> t2(n);
    vector<int> t3(n);
    vector<int> t4(n);
    vector<int> t5(n);
    vector<int> t6(n);
    vector<int> t7(n);
    vector<int> t8(n);
    vector<int> x(n);
    vector<int> w(n);
    vector<int> y(n);
    vector<int> z(n);
    //�迭 ����

    if (u.size() == 0 || v.size() == 0)
        r.resize(0);
    else if (n <= threshold) //�Ӱ����� ����
        lmult(u, v, r); //�����ش�
    else
    {
        m = n / 2;
        divide(u, m, x);           // u�� 10^m������ ���� ���� x�� ����
        rem_by_exp(u, m, y);       // ������ ����
        divide(v, m, w);           // v�� 10^m������ ���� ���� w�� ����
        rem_by_exp(v, m, z);       //������ ����
        prod(x, w, t1);            // x*w �� t1�� ����
        pow_by_exp(t1, 2 * m, t2); // t1���ٰ� �ڸ� �÷��ֱ�
        prod(x, z, t3);            // xz�� t3�� ����
        prod(w, y, t4);            // wy�� t4�� ����
        ladd(t3, t4, t5);          // t3 t4�� ���ؼ� t5�� ����
        pow_by_exp(t5, m, t6);     // t5�� m��ŭ �ڸ��÷���
        prod(y, z, t7);            // yz�� t7�� ����
        ladd(t2, t6, t8);          // t2+t6�� t8�� ����
        ladd(t8, t7, r);           // t8+t7�� r�� ����
    }
}
*/